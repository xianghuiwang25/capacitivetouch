#!/usr/bin/env python
import sys
import os
import re

import logging
import argparse
import touch_config
import ctsu_config

output_header = """
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : button_config.c
* Version      : 2.0 
* Description  : This file contains all TOUCH button configurations.
***********************************************************************************************************************/
#include "bsp_api.h"
#include "sf_touch_button.h"
"""

output_footer = """
#define CONFIGURATION_COUNT    (%(count)s)
touch_button_cfg_t const * const g_all_button_configs[CONFIGURATION_COUNT + 1] = 
{
#if (CONFIGURATION_COUNT > 0)
    %(config_names)s,
#endif
    NULL,
};

const uint16_t g_button_config_count = CONFIGURATION_COUNT;
"""
class BUTTON:
    """ Button Configuration Class. """
    template = """extern touch_cfg_t %(touch_cfg)s;
extern void App_TOUCH_Button_Notification(void*);
touch_button_cfg_t const %(name)s = { 
     .button.tx = %(tx)d,
     .button.rx = %(rx)d,
     .p_touch = &%(touch_cfg)s,
     .enable.bit.reserved = 0,
     .enable.hold =%(short_enable)s,
     .enable.press = %(press_enable)s,
     .enable.release = %(release_enable)s,
     .debounce = %(debounce)d,
     .hold_max = 1000,
     .p_callback = %(cb_name)s,
};
"""
    configs = set()
    
    def __init__(self, name, rx, tx, callback, identifier, debounce, press_enable, release_enable, short_enable, long_enable, touch_cfg):
        self.name = name
        self.tx = int(tx)
        self.rx = int(rx)
        self.cb_name = callback
        self.debounce = debounce
        self.identifier = identifier
        self.press_enable = press_enable
        self.release_enable = release_enable
        self.short_enable = short_enable
        self.long_enable = long_enable
        self.touch_cfg = touch_cfg
        self.output = ""
    
    def write(self, template):
        self.output = self.output + template % {
                                            'name': self.name,
                                            'rx':self.rx,
                                            'tx':self.tx,
                                            'debounce':self.debounce,
                                            'cb_name':self.cb_name,
                                            'press_enable':self.press_enable,
                                            'release_enable':self.release_enable,
                                            'short_enable':self.short_enable,
                                            'long_enable':self.long_enable,
                                            'identifier':self.identifier,
                                            'touch_cfg':self.touch_cfg,                                        
                                         }
        logging.info("Button Configuration:\n" + self.output)
        return

    
def read(list_touch_configs):
    search_patterns = []
    search_patterns.append(r"(SELF_TS(\d{2})_THR)")
    search_patterns.append(r"(MUTUAL(\d{1})_KEY(\d{2})_THR)")
    
    for touch_config in list_touch_configs:
        for sensor in touch_config.sensors:
            for search_pattern in search_patterns:
                pattern = re.compile(search_pattern)
                match = re.search(pattern, sensor.threshold)
                if match:
                    if 0 == search_patterns.index(search_pattern):
                        ## Button sensor found in self-cap mode ##
                        button_config = BUTTON( "Button_RX" + match.group(2) + "_on_" + touch_config.name,
                                                            sensor.rx, 
                                                            0xFF, 
                                                            "App_TOUCH_Button_Notification", 
                                                            touch_config.sensors.index(sensor),
                                                            20, 
                                                            'true', 
                                                            'true', 
                                                            'false', 
                                                            'false', 
                                                            touch_config.name)
                        BUTTON.configs.add(button_config)
                    
                    if 1 == search_patterns.index(search_pattern):
                        ## Button sensor found in mutual-cap mode ##
                        button_config = BUTTON("Button_RX%02d_TX%02d_on_" % (sensor.rx,sensor.tx ) + touch_config.name,
                                                            sensor.rx, 
                                                            sensor.tx, 
                                                            "App_TOUCH_Button_Notification", 
                                                            touch_config.sensors.index(sensor),
                                                            20, 
                                                            'true', 
                                                            'true', 
                                                            'false', 
                                                            'false', 
                                                            touch_config.name)
                        BUTTON.configs.add(button_config)
    
    return

def write(outfile):
    outpath = os.path.dirname(outfile);
#     outfile = outpath + "/button_config.c"
    try:
        if not os.path.exists(outpath):
            os.makedirs(outpath);
        ## Open file for writing ##
        outfile = open(outfile, 'w');
        
        names = []
        
        ## Write out all the information gathered ##
        outfile.write(output_header);
        for button in BUTTON.configs:
            outfile.write(button.output)
            names.append("&"+button.name)
            
        output_names = ",\r".join(names)
        outfile.write(output_footer % {"config_names": output_names,
                                       "count": len(BUTTON.configs)});
        ## Close the file ##
        outfile.close();    
    except IOError:
        logging.error("Failed to write output to file:%s" % outfile)
        raise;
    except OSError as exc: # Python >2.5
        if exc.errno == errno.EEXIST and os.path.isdir(path):
            pass
        else: raise
    return

if __name__ == '__main__':
    if sys.version_info < (2, 4):
        raise "must use python 2.5 or greater"

    parser = argparse.ArgumentParser(description='Create TOUCH configuration instances from a Workbench6 Project.',
                                     epilog="Sample: python touch_config.py -i ./TouchAPI_20160822172140")
    parser.add_argument('-o', '--output', dest='outfile', default="./output.c", help='Specify full path and file name for C output. E.g.: ./r_touch_rx_config_self01.c')
    parser.add_argument('-l', '--log', dest='logfile', help='Specify where logger information should be output.')
    parser.add_argument('-t', '--tx', dest='tx', nargs='+', type=int, default=None, help='TS pin numbers to use as Transmit Pins for the CTSU.')
    parser.add_argument('-r', '--rx', dest='rx', nargs='+', type=int, default=None, help='TS pin numbers to use as Receive Pins for the CTSU.')
    
    required = parser.add_argument_group('required named arguments')
    required.add_argument('-i', '--input', dest='inPath', required=True, help='Specify full path to TouchApi_YYYYMMDDHHMMSS project.')
    
    args = parser.parse_args()
    
    if args.logfile is not None:
        logging.basicConfig(filename=args.logfile, level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
    else:
        logging.basicConfig(level=logging.INFO, format='%(module)s: %(asctime)s - %(levelname)s - %(message)s')
    
    ctsu_file = args.inPath + "/Include/CTSU/r_ctsu.h";
    touch_file = args.inPath + "/Include/Touch/r_touch.h"
    ctsu_config.read(ctsu_file, args.tx, args.rx);
    ctsu_config.copy_clean_header(ctsu_file, args.outfile)

    touch_config.read(touch_file, ctsu_config.CTSU.configs)
    touch_config.copy_clean_header(touch_file, args.outfile)

    filename, file_extension = os.path.splitext(args.outfile)
    
    for touch_cfg in touch_config.TOUCH.configs:
        touch_cfg.write(touch_config.TOUCH.template, filename + str(touch_config.TOUCH.configs.index(touch_cfg)) + file_extension)
        
    read(touch_config.TOUCH.configs)
    
    for button in BUTTON.configs:
            button.write(BUTTON.template)
            
    write(args.outfile)
