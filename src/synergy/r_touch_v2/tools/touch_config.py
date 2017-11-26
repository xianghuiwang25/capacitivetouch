#!/usr/bin/env python
import sys
import os
import re
import logging
import argparse
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
* File Name    : touch_config.c
* Version      : 2.0
* Description  : This file contains TOUCH middleware configuration settings.
***********************************************************************************************************************/
#include "r_touch.h"
#include "r_touch_tuning.h"
"""



class SENSOR(object):
    """ Touch Sensor Class """
    def __init__(self, rx, tx, threshold, hysteresis, name):
        """ Initialize parameters for determining touch with a sensor. Default values specified here. """
        assert type(threshold) == str
        assert type(hysteresis) == str
        assert type(name) == str
        self.threshold = threshold
        self.hysteresis = hysteresis
        self.dt_limit = "%(name)s_TOUCH_ON" % {"name":name}
        self.dr_limit = "%(name)s_TOUCH_OFF" % {"name":name}
        self.drift_rate = "%(name)s_DRIFT_FREQUENCY" % {"name":name}
        self.recalib_delay = "%(name)s_DRIFT_FREQUENCY" % {"name":name}
        self.recalib_threshold = 200
        self.drift_rate_plus = 0
        self.drift_rate_minus = 0
        self.output = None
        self.rx = rx
        self.tx = tx
        return;
    
    def write(self, index):
        assert int == type(index)
        template = "    [%(index)d] = {.threshold = %(threshold)s, .hysteresis = %(hysteresis)s, .dt_limit = %(dt_limit)s, .dr_limit = %(dr_limit)s, .drift_rate = %(drift_rate)s, .drift_rate_plus = %(drift_rate_plus)d, .drift_rate_minus = %(drift_rate_minus)d, .recalib_delay = %(recalib_delay)s, .recalib_threshold = %(recalib_threshold)d},"
        self.output = template % {  'index':index,
                                    'threshold':self.threshold,
                                    'hysteresis':self.hysteresis,
                                    'dt_limit':self.dt_limit,
                                    'dr_limit':self.dr_limit,
                                    'drift_rate':self.drift_rate,
                                    'drift_rate_plus':self.drift_rate_plus,
                                    'drift_rate_minus':self.drift_rate_minus,
                                    'recalib_delay':self.recalib_delay,
                                    'recalib_threshold':self.recalib_threshold,
                                  }
        return;

class TOUCH(object):
    """ TOUCH Configuration Class """
    ## dictionary :=  name, touch_sensor_parameter, touch_sensor_count, touch_buffer_area, ctsu_cfg_name ##
    template = """
#define TOUCH_CFG_GENERATE    (1) //(%(generate)s)
static touch_common_parameter_t %(name)s_common =
{
    .drift_hold_limit = 50,
    .on_limit = (%(suffix)s_MSA == 0) ? (UINT16_MAX):(%(suffix)s_MSA),
#if defined(SLIDER_USE) || defined(WHEEL_USE)
    .max_touched_sensors = 2,
#else
    .max_touched_sensors = 1,
#endif
};

static touch_sensor_parameter_t %(name)s_sensor[] =
{
%(touch_sensor_parameter)s
};

static uint8_t %(name)s_binary[(%(touch_sensor_count)d/8) + 1];

static uint8_t %(name)s_buffer[%(touch_buffer_area)d];

extern ctsu_instance_t const %(ctsu_cfg_name)s;

#if (TOUCH_CFG_GENERATE == 1)
static touch_cfg_t %(name)s_cfg =
{
    .p_ctsu = &%(ctsu_cfg_name)s,
    .p_common = &%(name)s_common,
    .p_sensor = &%(name)s_sensor[0],
    .p_binary_result = %(name)s_binary,
    .p_callback = NULL,
    .num_ignored = 0,
    .p_ignored = NULL,
    .buffer = {
        .p_start = %(name)s_buffer,
        .size = sizeof(%(name)s_buffer),
    },
    .custom =
    {
        .p_filter = NULL,
        .p_touch_detect = NULL,
        .p_filter_instance = NULL,
        .num_filter_instances = 0,
    },
};

static touch_instance_ctrl_t %(name)s_ctrl;

touch_instance_t const %(name)s = 
{
 .p_ctrl = &%(name)s_ctrl,
 .p_cfg  = &%(name)s_cfg,
 .p_api  = &g_touch_on_touch,
};
#endif
    """
    
    xml_template = """
    <module id=\"module.driver.touch_on_touch.%(rand)d\">
      <property id=\"module.driver.touch.name\" value=\"%(name)s\"/>
      <property id=\"module.driver.touch.p_binary_result\" value=\"%(name)s_binary\"/>
      <property id=\"module.driver.touch.drift_hold_limit\" value=\"0\"/>
      <property id=\"module.driver.touch.on_limit\" value=\"65535\"/>
      <property id=\"module.driver.touch.max_touched_sensors\" value=\"1\"/>
      <property id=\"module.driver.touch.p_callback\" value=\"NULL\"/>
    </module>
    """
    
    xml_requires = """
    <stack module=\"module.driver.touch_on_touch.%(rand)d\" requires=\"module.framework.sf_touch_button.requires.touch\">
        %(requires_ctsu)s
    </stack>
    """
    
    configs = [] 
    def __init__(self, ctsu_cfg):
        """ Initialize an object of class TOUCH."""
        assert True == isinstance(ctsu_cfg, ctsu_config.CTSU)
        self.rand  = random.randint(100000000,9999999999999)
        self.ctsu_cfg = ctsu_cfg
        self.ctsu_cfg_name = "%s" % ctsu_cfg.name
        self.name = "g_touch%(itr)s_on_%(ctsu_cfg)s"  % {"ctsu_cfg" : self.ctsu_cfg_name,
                                                            "itr":str(ctsu_cfg.itr)}
        self.itr = ctsu_cfg.itr
        self.suffix = "%(mode)s%(itr)s" % {"mode":("SELF" if ctsu_cfg.mode==0 else "MUTUAL"),
                                           "itr":(str(ctsu_cfg.itr) if (ctsu_cfg.itr!=None) else "")}
        self.touch_sensor_parameter = []
        self.touch_sensor_count = ctsu_cfg.num_sensors
        self.touch_buffer_area = ctsu_cfg.num_sensors * 32
        self.ctsu_cfg_name = "%s_cfg" % ctsu_cfg.name
        self.sensors = []
        
        logging.info("Mode of Operation: " + "SELF" if ctsu_cfg.mode==0 else "MUTUAL")
        logging.info("Sensor Count: %d" % self.touch_sensor_count)
        logging.info("Sensor Buffer Area (bytes): %d" % self.touch_buffer_area)
        logging.info("CTSU Configuration Name" + self.ctsu_cfg_name)
        return

    def add_sensor(self, index, rx, tx, threshold, hysteresis):
        touch_sensor_parameter = SENSOR(rx, tx, threshold, hysteresis, self.suffix)
        touch_sensor_parameter.write(index)
        self.touch_sensor_parameter.append(touch_sensor_parameter.output)
        self.sensors.append(touch_sensor_parameter)
        return

    def write(self, template, output=None, generate=True):
        """ Write out the TOUCH configuration. """
        self.output = template %  { 'name':self.name,
                                    'suffix':self.suffix,
                                    'touch_sensor_count':self.touch_sensor_count,
                                    'touch_buffer_area':self.touch_buffer_area,
                                    'ctsu_cfg_name':self.ctsu_cfg_name,
                                    'touch_sensor_parameter':"\n"+"\n".join(self.touch_sensor_parameter),
                                    'generate':"1" if generate == True else "0",
                                  }
        
        logging.info("Touch Output shown below:\n" + self.output)
        ## Create final output ##
        self.output = self.output

        ## Write output ##
        if(output!=None):
            try:
                ## Open file for writing ##
                outfile = open(output, 'w');
                ## Write out all the information gathered ##
                outfile.write(output_header);
                outfile.write(self.output);
                ## Close the file ##
                outfile.close();    
            except IOError:
                logging.error("Failed to write output to file:%s" % outfile)
                raise;
        return
    
    def write_xml(self, template = xml_template, output=None, generate=True):
        self.xml = template % {'rand' :self.rand,
                               'requires_ctsu':self.ctsu_cfg.xml_requires
                               }
        
        return

def read(infile, list_ctsu_cfgs):
    """ Read the r_touch.h file and figure out which channels are buttons v/s slider/wheels."""
    global touch_configs
    assert len(list_ctsu_cfgs) > 0

    try:
        infile = open(infile, 'r');
        file_lines_touch = infile.readlines();
        infile.close();
    except IOError:
        logging.error("Could not access input file:%s" % infile)
        raise

    for ctsu_cfg in list_ctsu_cfgs:
        """ Run through each CTSU configuration and create corresponding Touch Configurations"""
        if ctsu_cfg.mode == 0:
            ## Self Capacitance ##
            touch_config = TOUCH(ctsu_cfg)
            self_search_patterns = [r"(#define\s*SELF_KEY_USE_(%(ts)02d)\s*\((\d{1})\))",
                                    r"(#define\s*SLIDER(\d{1,2})_(\d{1,2})\s*\((%(ts)d)\))",
                                    r"(#define\s*WHEEL(\d{1,2})_(\d{1,2})\s*\((%(ts)d)\))",
                                    r"(#define\s*SELF_TS%(ts)02d_THR\s*\((\d{1,5})\))",
                                    r"(#define\s*SELF_TS%(ts)02d_HYS\s*\((\d{1,5})\))"]
            for ts in ctsu_cfg.en:
                for self_search_pattern in self_search_patterns:
                    search_pattern = re.compile(self_search_pattern % {'ts':ts})
                    for line in file_lines_touch:
                        match = re.search(search_pattern,line)
                        if match:
                            if 0 == self_search_patterns.index(self_search_pattern):
                                if match.group(3)=="1":
                                    ## TS is used as a Button ##
                                    touch_config.add_sensor(ctsu_cfg.en.index(ts),
                                                            ts,
                                                            None,
                                                            "SELF_TS%02d_THR" % ts,
                                                            "SELF_TS%02d_HYS" % ts)                                  
                            if 1 == self_search_patterns.index(self_search_pattern):
                                if int(match.group(4)) == ts:
                                    ## TS is used in a Slider ##
                                    touch_config.add_sensor(ctsu_cfg.en.index(ts),
                                                             ts,
                                                             None,
                                                             "SLIDER%s_%s_NORM/4" % (match.group(2), match.group(3)),
                                                             "SLIDER%s_%s_NOISE" % (match.group(2), match.group(3)))
                            if 2 == self_search_patterns.index(self_search_pattern):
                                if int(match.group(4)) == ts:
                                    ## TS is used in a Wheel ##
                                    touch_config.add_sensor(ctsu_cfg.en.index(ts),
                                                             ts,
                                                             None,
                                                             "WHEEL%s_%s_NORM/4" % (match.group(2), match.group(3)),
                                                             "WHEEL%s_%s_NOISE" % (match.group(2), match.group(3)))
                            if 3 == self_search_patterns.index(self_search_pattern):
                                touch_config.ctsu_cfg.sensordata[ctsu_cfg.en.index(ts)].threshold = int(match.group(2))
                            if 4 == self_search_patterns.index(self_search_pattern):
                                touch_config.ctsu_cfg.sensordata[ctsu_cfg.en.index(ts)].hysteresis = int(match.group(2))
                                
        elif ctsu_cfg.mode == 1:
            ## Mutual Capacitance ##
            touch_config = TOUCH(ctsu_cfg)
            mutual_search_patterns = [r"(#define\s*MUTUAL"+str(ctsu_cfg.itr)+"_KEY%(ts)02d_USE\s*\((\d{1})\))"]
            for ts in range(0, ctsu_cfg.num_sensors):
                for mutual_search_pattern in mutual_search_patterns:
                    search_pattern = re.compile(mutual_search_pattern % {'ts':ts})
                    for line in file_lines_touch:
                        match = re.search(search_pattern,line)
                        if match:
                                if 0 == mutual_search_patterns.index(mutual_search_pattern):
                                    if match.group(2)=="1":
                                        ## TS is used as a button ##
                                        touch_config.add_sensor(ts,
                                                                None,
                                                                None,
                                                                "MUTUAL"+str(ctsu_cfg.itr)+"_KEY%02d" % (ts)+"_THR",
                                                                "MUTUAL"+str(ctsu_cfg.itr)+"_KEY%02d" % (ts)+"_HYS")
            
            for ch_rx in ctsu_cfg.rx:
                for ch_tx in ctsu_cfg.tx:
                    offset = ctsu_cfg.rx.index(ch_rx) * len(ctsu_cfg.tx) + ctsu_cfg.tx.index(ch_tx)
                    touch_config.sensors[offset].rx = ch_rx
                    touch_config.sensors[offset].tx = ch_tx
        TOUCH.configs.append(touch_config)
    return

def copy_clean_header(infile, outfile):
    """ Remove unused definitions from the TOUCH settings header file generated by Workbench6. """
    ## Read Original File ##
    try:
        infile = open(infile, 'r');
        file_lines_touch = infile.readlines();
        infile.close();
    except IOError:
        logging.error("Could not access input file:%s" % infile)
        raise

    logging.info("Dir Name: %s" % os.path.dirname(outfile))
    outpath = os.path.dirname(outfile);
    outfile = outpath + "/r_touch_tuning.h"
    ## File Clean up ##
    touch_stdinth_add_index = [line for line in file_lines_touch if "Includes" in line]
    touch_stdinth_add_index = file_lines_touch.index(touch_stdinth_add_index[0])
    file_lines_touch.insert(touch_stdinth_add_index + 2, "#include <stdint.h>\r\n")
    
    touch_stdinth_add_index = [line for line in file_lines_touch if """#include \"r_ctsu.h\"""" in line]
    touch_stdinth_add_index = file_lines_touch.index(touch_stdinth_add_index[0])
    file_lines_touch[touch_stdinth_add_index] = """#include \"r_ctsu_tuning.h\""""

    touch_clean_start_index = [line for line in file_lines_touch if "touch_result_t" in line]
    clean_start_index = file_lines_touch.index(touch_clean_start_index[0])

    for index in range(0, clean_start_index):
        if "typedef struct" in file_lines_touch[index]:
            clean_end_index = index
    del file_lines_touch[clean_end_index:clean_start_index+1]

    touch_clean_start_index = [line for line in file_lines_touch if "Global variables" in line]
    touch_clean_end_index = [line for line in file_lines_touch if "#endif //] __R_TOUCH_H__" in line]
    clean_start_index = file_lines_touch.index(touch_clean_start_index[0]) + 2
    clean_end_index = file_lines_touch.index(touch_clean_end_index[0])
    del file_lines_touch[clean_start_index:clean_end_index]

    ## Copy clean file ##
    try:
        if not os.path.exists(outpath):
            os.makedirs(outpath);
        outfile = open(outfile, 'w+');
        for line in file_lines_touch:
            outfile.write(line);
        outfile.close();    
    except IOError:
        logging.error("Failed to write output to file:%s" % outfile)
        raise;
    except OSError as exc: # Python >2.5
        if exc.errno == errno.EEXIST and os.path.isdir(path):
            pass
        else: raise
    return;

if __name__ == '__main__':
    if sys.version_info < (2, 4):
        raise "must use python 2.5 or greater"

    parser = argparse.ArgumentParser(description='Create TOUCH configuration instances from a Workbench6 Project.',
                                     epilog="Sample: python touch_config.py -p ./TouchAPI_20160822172140")
    parser.add_argument('-i', '--input', dest='inPath', help='Specify full path to location containing r_ctsu.h and r_touch.h.')
    parser.add_argument('-o', '--output', dest='outfile', default="./output.c", help='Specify full path and file name for C output. E.g.: ./r_touch_rx_config_self01.c')
    parser.add_argument('-l', '--log', dest='logfile', help='Specify where logger information should be output.')
    parser.add_argument('-t', '--tx', dest='tx', nargs='+', type=int, default=None, help='TS pin numbers to use as Transmit Pins for the CTSU.')
    parser.add_argument('-r', '--rx', dest='rx', nargs='+', type=int, default=None, help='TS pin numbers to use as Receive Pins for the CTSU.')
    parser.add_argument('-p', '--project', dest='projectPath', help='Specify full path to TouchApi_YYYYMMDDHHMMSS project.')
    parser.add_argument('-n', '--no_cfg', dest='generate', action='store_false', default=True, help='Disable generation of ctsu_cfg_t')
#     required = parser.add_argument_group('required named arguments')
        
    args = parser.parse_args()
    generate = args.generate

    if args.logfile is not None:
        logging.basicConfig(filename=args.logfile, level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
    else:
        logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

    if args.inPath != None:    
        ctsu_file = args.inPath + "/r_ctsu.h";
        touch_file = args.inPath + "/r_touch.h"
    else:
        ctsu_file = args.projectPath + "/Include/CTSU/r_ctsu.h";
        touch_file = args.projectPath + "/Include/Touch/r_touch.h"
        
    ctsu_config.read(ctsu_file, args.tx, args.rx);
#     ctsu_config.copy_clean_header(ctsu_file, args.outfile)

    read(touch_file, ctsu_config.CTSU.configs)
#     copy_clean_header(touch_file, args.outfile)

    filename, file_extension = os.path.splitext(args.outfile)
    
    for touch_cfg in TOUCH.configs:
        touch_cfg.write(TOUCH.template, filename + str(TOUCH.configs.index(touch_cfg)) + file_extension, generate)
