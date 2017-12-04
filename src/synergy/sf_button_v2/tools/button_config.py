#!/usr/bin/env python
import sys
import os
import re

import logging
import argparse
import random 
import touch_config
import ctsu_config

license = """
Copyright (c) 2017 Onkar Raut (onkar.raut.at.renesas.com).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""

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

#if CONFIGURATION_COUNT < BUTTON_CFG_MAX_CONTROL_BLOCK_COUNT
#error "Check BUTTON_CFG_MAX_CONTROL_BLOCK_COUNT value. Please delete this preprocessor after verifying condition."
#endif

touch_button_instance_t const * const g_all_buttons[CONFIGURATION_COUNT + 1] = 
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
    template = """extern touch_instance_t const %(touch_cfg)s;
extern void App_TOUCH_Button_Notification(void*);
static touch_button_cfg_t const %(name)s_cfg = { 
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

static touch_button_instance_ctrl_t %(name)s_ctrl;

touch_button_instance_t const %(name)s = 
{
    .p_ctrl = &%(name)s_ctrl,
    .p_cfg  = &%(name)s_cfg,
    .p_api  = &g_touch_button_on_g_touch_button,
};
"""

    xml_template = """
    <module id=\"module.framework.sf_touch_button_v2.%(rand)d\">
      <property id=\"module.framework.sf_touch_button.name\" value=\"%(name)s\"/>
      <property id=\"module.framework.sf_touch_button.press_enable\" value=\"module.framework.sf_touch_button.press_enable.enabled\"/>
      <property id=\"module.framework.sf_touch_button.release_enable\" value=\"module.framework.sf_touch_button.release_enable.enabled\"/>
      <property id=\"module.framework.sf_touch_button.debounce\" value=\"1\"/>
      <property id=\"module.framework.sf_touch_button.p_callback\" value=\"touch_button_common_callback\"/>
    </module>
    <context id=\"_context.%(crand)d\">
      <stack module=\"module.framework.sf_touch_button_v2.%(rand)d\">
        <stack module=\"module.driver.touch_on_touch.%(touch_rand)d\" requires=\"module.framework.sf_touch_button.requires.touch\">
          <stack module=\"module.driver.ctsu_on_ctsu.%(ctsu_rand)d\" requires=\"module.driver.touch.requires.ctsu\"/>
        </stack>
        <stack module=\"module.driver.ctsu_sensor_on_ctsu.%(sensor_rand)d\" requires=\"module.framework.sf_touch_button.requires.ctsu_sensor\">
          <stack module=\"module.driver.ctsu_on_ctsu.%(ctsu_rand)d\" requires=\"module.driver.ctsu_sensor.requires.ctsu\"/>
        </stack>
      </stack>
    </context>
    """
    configs = set()
    
    def __init__(self, name, rx, tx, callback, identifier, debounce, press_enable, release_enable, short_enable, long_enable, touch_cfg):
        self.name = name
        self.rand  = random.randint(100000000,9999999999999)
        self.tx = tx
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
                                            'tx':0xFF if self.tx==None else int(self.tx),
                                            'debounce':self.debounce,
                                            'cb_name':self.cb_name,
                                            'press_enable':self.press_enable,
                                            'release_enable':self.release_enable,
                                            'short_enable':self.short_enable,
                                            'long_enable':self.long_enable,
                                            'identifier':self.identifier,
                                            'touch_cfg':self.touch_cfg.name,                                        
                                         }
        logging.info("Button Configuration:\n" + self.output)
        return
    
    def write_xml(self, template=xml_template, outfile=None, generate=True):
        self.xml = []
        
        if outfile!=None:
            self.touch_cfg.ctsu_cfg.write_xml()
            self.xml.append(self.touch_cfg.ctsu_cfg.xml)
            
        if outfile!=None:
            self.touch_cfg.write_xml()
            self.xml.append(self.touch_cfg.xml)
        
        index = len(self.touch_cfg.ctsu_cfg.sensordata)
        for sensor in self.touch_cfg.ctsu_cfg.sensordata:
            if self.rx == sensor.rx and self.tx == sensor.tx:
                index = self.touch_cfg.ctsu_cfg.sensordata.index(sensor)
        
        output = template % {'name':self.name,
                             'rand' :self.rand,
                             'crand':random.randint(10000000,99999999),
                             'touch_rand': self.touch_cfg.rand,
                             'ctsu_rand':self.touch_cfg.ctsu_cfg.rand,
                             'sensor_rand':self.touch_cfg.ctsu_cfg.sensordata[index].rand,
                             }
        
        self.xml.append(output)
        
        self.xml = '\n'.join(self.xml)
        
        if(outfile!=None):
            try:
                ## Open file for writing ##
                outfile = open(outfile, 'w');
                ## Write out all the information gathered ##
                outfile.write("""<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>
                <synergyConfiguration version=\"3\">
                  <synergyModuleConfiguration>
                """)
                outfile.write(self.xml);
                outfile.write("""
                  </synergyModuleConfiguration>
                </synergyConfiguration>
                """)
                ## Close the file ##
                outfile.close();    
            except IOError:
                logging.error("Failed to write output to file:%s" % outfile)
                raise;
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
                                                            None, 
                                                            "App_TOUCH_Button_Notification", 
                                                            touch_config.sensors.index(sensor),
                                                            20, 
                                                            'true', 
                                                            'true', 
                                                            'false', 
                                                            'false', 
                                                            touch_config)
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
                                                            touch_config)
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
    parser.add_argument('-x', '--xml', dest='xmlgen', action='store_true', default=False, help='Generate XML for importing to ISDE')
    
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
        if args.xmlgen==True:
            button.write_xml(BUTTON.xml_template, "./out"+ str(list(BUTTON.configs).index(button)) +".xml")
    write(args.outfile)
