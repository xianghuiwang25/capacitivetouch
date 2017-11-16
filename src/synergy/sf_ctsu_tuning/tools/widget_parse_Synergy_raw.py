import os
import re
import sys

import logging
import zipfile
import shutil
import argparse
import xml.dom.minidom

import ctsu_config
import touch_config
import button_config
# import slider_config

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

class MCU(object):
    """ MCU Settings"""
    bsp_series = {"51":"0x0", "52":"0x0", }
    bsp_group = {"51":{"10":"0x0", "11":"0x1", "13":"0x3", "30":"0x0"},
                  "52":{"30":"0x0", "31":"0x0" } }
    bsp_version = {"51":{"A":"0xA", "B":"0xB" },
                  "52":{"A":"0xA", "B":"0xB" } }
    bsp_capacity = {"3":"0x3","5":"0x5","6":"0x6","7":"0x7","8":"0x8"}
    bsp_package = {"FM":"0x0","FP":"0x9","LJ":"0xA","FN":"0xB"}
    bsp_clk_src = {"LOCO":"0","HOCO":"1","Main":"2","SUB":"3","PLL":"4"}
    
    def __init__(self, src):
        if False == os.path.isdir(src):
            logging.error("Workbench6 TouchAPI Project path does not exist.")
            sys.exit(1)
        if False == os.path.exists(src + "/.cproject"):
            logging.error("Workbench6 TouchAPI project does not contain valid .cproject file.")
            sys.exit(1)
        if False ==  os.path.exists(src + "/Include/HwResource/r_cgc.h"):
            logging.error("Workbench6 TouchAPI project does not contain r_cgc.h file.")
            sys.exit(1)
        
        self.src = src
        DOMTree = xml.dom.minidom.parse(src + "/.cproject")
        cproject = DOMTree.documentElement
        optionValues = cproject.getElementsByTagName("option")
        for optionValue in optionValues:
            if optionValue.hasAttribute("name"):
                if optionValue.getAttribute("name")=="DeviceShortName":
                    device = optionValue.getAttribute("value")
                    
        self.device = device
             
        rx_mcu_decomposer = r"(R5)(F)(\d{2})(\d{2})(\d{1})(.)(.)(..)"
        search_pattern = re.compile(rx_mcu_decomposer)
        match = re.search(search_pattern,device)
        if(match):
            self.series = match.group(3)
            self.group = match.group(4)
            self.capacity = match.group(5)
            self.version = match.group(6)
            self.temperature = match.group(7)
            self.package = match.group(8)
            
#         self.series = MCU.bsp_series[mcu_series]
#         self.group = MCU.bsp_group[mcu_series][mcu_group]
#         self.capacity = MCU.bsp_capacity[mcu_capacity]
#         self.version = MCU.bsp_version[mcu_series][mcu_version]
#         self.temperature = mcu_temperature
#         self.package = MCU.bsp_package[mcu_package]
        
        rx_mcu_decomposer = r"(R5)(F5)(\d{3})(\d{1})(.)(.)(..)"
        search_pattern = re.compile(rx_mcu_decomposer)
        match = re.search(search_pattern,device)
        if(match):
            self.family = match.group(3)
        
        
        cgc_search_patterns = []
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_CLOCK_SOURCE\s*\((\d{1})\))")     ## 00
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_XTAL_HZ\s*\((\d{7,8})\))")        ## 01
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_PLL_MUL\s*\((\d{1})\))")          ## 02
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_PLL_DIV\s*\((\d{1})\))")          ## 03
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_ICLK_HZ\s*\((\d{7,8})\))")        ## 04
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_UPLL_MUL\s*\((\d{1})\))")         ## 05
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_UPLL_DIV\s*\((\d{1})\))")         ## 06
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_ICK_DIV\s*\((\d{1})\))")          ## 07
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_PCKB_DIV\s*\((\d{1})\))")         ## 08
        cgc_search_patterns.append(r"(#define\s*TOUCH_CFG_HOCO_FREQUENCY\s*\((\d{1})\))")   ## 09
        cgc_search_patterns.append(r"(#define\s*WORKBENCH_SERIAL_CONNECT\s*\((\d{1})\))")   ## 10
        
        f_rd = open(src + "/Include/HwResource/r_cgc.h", 'r')
        file_lines_cgc = f_rd.readlines()
        f_rd.close()
        
        for cgc_search_pattern in cgc_search_patterns:
            search_pattern = re.compile(cgc_search_pattern)
            for line in file_lines_cgc:
                match = re.search(search_pattern,line)
                if match:
                    if 0 == cgc_search_patterns.index(cgc_search_pattern):
                        self.clk_src = match.group(2)
                    if 1 == cgc_search_patterns.index(cgc_search_pattern):
                        self.xtal_freq = match.group(2)
                    if 2 == cgc_search_patterns.index(cgc_search_pattern):
                        self.pll_m = match.group(2)
                    if 3 == cgc_search_patterns.index(cgc_search_pattern):
                        self.pll_d = match.group(2)
                    if 4 == cgc_search_patterns.index(cgc_search_pattern):
                        self.sys_clk_freq = match.group(2)
                    if 5 == cgc_search_patterns.index(cgc_search_pattern):
                        self.upll_m = match.group(2)
                    if 6 == cgc_search_patterns.index(cgc_search_pattern):
                        self.upll_d = match.group(2)
                    if 7 == cgc_search_patterns.index(cgc_search_pattern):
                        self.iclk_d = match.group(2)
                    if 8 == cgc_search_patterns.index(cgc_search_pattern):
                        self.pclk_b = match.group(2)
                    if 9 == cgc_search_patterns.index(cgc_search_pattern):
                        self.hoco_freq = match.group(2)
                    if 10 == cgc_search_patterns.index(cgc_search_pattern):
                        self.connect = match.group(2)
        
        return
    
def read(src):
    """ Read the MCU settings of the TouchAPI Project."""
    mcu = MCU(src)
    return mcu

def write(mcu, install, dest):
    touch_config_template = """
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer 
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.    
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : touch_config.c
* Version      : 2.0
* Description  : This f_src contains an array pointing to all touch configurations created.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "r_touch_api.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define    MAX_CONFIGS    (%(count)s)

#if (MAX_CONFIGS > TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS)
#error "Check TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS value in synergy_cfg/ssp_cfg/driver/r_touch_cfg.h"
#endif

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/
%(extern)s;
touch_cfg_t const * const g_all_touch_configs[MAX_CONFIGS+1] =
{
#if (MAX_CONFIGS > 0)
    %(name)s,
#endif
    NULL,
};

const uint8_t g_num_touch_configs = %(count)s;

    """
    
    ctsu_config_template = """
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer 
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.    
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : ctsu_config.c
* Version      : 2.0
* Description  : This f_src contains an array pointing to all touch configurations created.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "r_ctsu_api.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define    MAX_CONFIGS    (%(count)s)
/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/
%(extern)s;
ctsu_instance_t const * const g_all_ctsu_configs[MAX_CONFIGS+1] =
{
#if (MAX_CONFIGS > 0)
    %(name)s,
#endif
    NULL,
};
const uint8_t g_num_ctsu_configs = %(count)s;
    """
    
    """ Use the MCU settings to create and modify a project at the destination. """
    if False == os.path.isdir(dest):
        logging.error("Output directory does not exist.")
        sys.exit(1)
    
#     if os.path.isdir(dest + "\Base_Project_RX" + mcu.family)==False:
#         """ Base Project does not exist. Extract it."""
#         zipfile = install + ("\FIT_Base_Projects\Base_Project_RX%s.zip" % mcu.family)
#         if False == os.path.exists(zipfile):
#             logging.error("File %s does not exist." % zipfile)
#             sys.exit(1)
#         unzip(zipfile, dest)
#         
    outdir = dest # +"/Base_Project_RX" + mcu.family
#     
#     if False == os.path.isdir(outdir + "/src/ctsu"):
#         logging.error(outdir + "/ctsu does not exist.")
#         sys.exit(1)
#     
#     if False == os.path.exists(outdir + "/.cproject"):
#         logging.error("Workbench6 TouchAPI project does not contain valid .cproject f_src.")
#         sys.exit(1)
#     
#     if False == os.path.exists(outdir + "/r_config/r_bsp_config.h"):
#         logging.error("File %s/r_config/r_bsp_config.h does not exist" % outdir)
#         sys.exit(1)
#     
#     if False == os.path.exists(outdir + "/r_config/r_ctsu_rx_config.h"):
#         logging.error("File %s/r_config/r_ctsu_rx_config.h does not exist" % outdir)
#         sys.exit(1)
#         
#     if False == os.path.exists(outdir + "/r_config/r_touch_rx_config.h"):
#         logging.error("File %s/r_config/r_touch_rx_config.h does not exist" % outdir)
#         sys.exit(1)
#         
#     if False == os.path.exists(outdir + "/r_config/r_touch_button_config.h"):
#         logging.error("File %s/r_config/r_touch_button_config.h does not exist" % outdir)
#         sys.exit(1)
#         
#     if False == os.path.exists(outdir + "/r_config/r_touch_slider_config.h"):
#         logging.error("File %s/r_config/r_touch_slider_config.h does not exist" % outdir)
#         sys.exit(1)
#         
#     if False == os.path.exists(outdir + "/Base_Project_RX%s DefaultBuild.launch" % mcu.family):
#         logging.error("File %s does not exist" % (outdir + "/Base_Project_RX(%s)\ DefaultBuild.launch" % mcu.family))
#         sys.exit(1)
    
#     """ Adjust Board Support Package Configuration """
#     f_rd = open(outdir + "/r_config/r_bsp_config.h", 'r')
#     file_lines_bsp = f_rd.readlines()
#     f_rd.close()
#     
#     bsp_search_patterns = []
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_MCU_PART_PACKAGE\s*\((.*)\))")                  ## 00
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_MCU_PART_MEMORY_SIZE\s*\((.*)\))")              ## 01
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_MCU_PART_GROUP\s*\((.*)\))")                    ## 02
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_MCU_PART_SERIES\s*\((.*)\))")                   ## 03
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_CLOCK_SOURCE\s*\((\d{1})\))")                   ## 04
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_USB_CLOCK_SOURCE\s*\((\d{1})\))")               ## 05
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_XTAL_HZ\s*\((\d{1})\))")                        ## 06
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_PLL_DIV\s*\((\d{1})\))")                        ## 07
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_PLL_MUL\s*\((\d{1})\))")                        ## 08
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_UPLL_DIV\s*\((\d{1})\))")                       ## 09
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_UPLL_MUL\s*\((\d{1})\))")                       ## 10
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_ICK_DIV\s*\((\d{1})\))")                        ## 11
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_FCK_DIV\s*\((\d{1})\))")                        ## 12
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_BCK_DIV\s*\((\d{1})\))")                        ## 13
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_PCKA_DIV\s*\((\d{1})\))")                       ## 14
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_PCKB_DIV\s*\((\d{1})\))")                       ## 15
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_PCKD_DIV\s*\((\d{1})\))")                       ## 16
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_MCU_PART_VERSION\s*\((.*)\))")                  ## 17
#     bsp_search_patterns.append(r"(#define\s*BSP_CFG_HOCO_FREQUENCY\s*\((\d{1})\))")                 ## 18
    
#     for line in file_lines_bsp:
#         for bsp_search_pattern in bsp_search_patterns:
#             search_pattern = re.compile(bsp_search_pattern)
#             match = re.search(search_pattern,line)
#             if match:
#                 index = file_lines_bsp.index(line)
#                 if 0 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_MCU_PART_PACKAGE        (%s)\n" % MCU.bsp_package[mcu.package]
#                 elif 17 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_MCU_PART_VERSION        (%s)\n" % MCU.bsp_version[mcu.series][mcu.version]
#                 elif 1 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_MCU_PART_MEMORY_SIZE    (%s)\n" % MCU.bsp_capacity[mcu.capacity]
#                 elif 2 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_MCU_PART_GROUP          (%s)\n" % MCU.bsp_group[mcu.series][mcu.group]
#                 elif 3 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_MCU_PART_SERIES         (%s)\n" % MCU.bsp_series[mcu.series]
#                 elif 4 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_CLOCK_SOURCE       (%s)\n" % mcu.clk_src
#                 elif 5 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_USB_CLOCK_SOURCE        (0)\n"
#                     if mcu.family.lower() == "113":
#                         if mcu.clk_src == "4":
#                             usable_hz = ["16000000", "12000000", "8000000", "6000000"]
#                             if mcu.xtal_freq in usable_hz:
#                                 newline = "#define BSP_CFG_USB_CLOCK_SOURCE        (1)\n"
#                     elif mcu.family.lower() == "231":
#                         if mcu.clk_src == "4":
#                             usable_hz = ["16000000", "12000000", "8000000", "6000000", "4000000"]
#                             if mcu.xtal_freq in usable_hz:
#                                 newline = "#define BSP_CFG_USB_CLOCK_SOURCE        (1)\n"
#                 elif 6 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_XTAL_HZ            (%s)\n" % mcu.xtal_freq
#                 elif 7 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_PLL_DIV            (%s)\n" % mcu.pll_d
#                 elif 8 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_PLL_MUL            (%s)\n" % mcu.pll_m
#                 elif 9 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_UPLL_DIV            (%s)\n" % mcu.upll_d
#                 elif 10 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_UPLL_MUL            (%s)\n" % mcu.upll_m
#                 elif 11 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_ICK_DIV            (%s)\n" % mcu.iclk_d
#                 elif 12 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_FCK_DIV            (%s)\n" % mcu.pclk_b
#                 elif 13 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_BCK_DIV            (%s)\n" % mcu.pclk_b
#                 elif 14 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_PCKA_DIV            (%s)\n" % mcu.pclk_b
#                 elif 15 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_PCKB_DIV            (%s)\n" % mcu.pclk_b
#                 elif 16 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_PCKD_DIV            (%s)\n" % mcu.pclk_b
#                 elif 18 == bsp_search_patterns.index(bsp_search_pattern):
#                     newline = "#define BSP_CFG_HOCO_FREQUENCY      (%s)\n" % mcu.hoco_freq
#                 file_lines_bsp[index] = newline
#     
#     """ Adjust Project Settings """
#     f_rd = open(outdir + "/.cproject", 'r')
#     file_lines_cproject = f_rd.readlines()
#     f_rd.close()
#     rx_mcu_decomposer = r"(.*)(R5F)(\w*)(.*)"
#     search_pattern = re.compile(rx_mcu_decomposer)
#     matches = [line for line in file_lines_cproject if mcu.device[0:3] in line]
#     for line in matches:
#         match = re.search(search_pattern, line)
#         if match:
#             if len(match.group(3))==5:
#                 mcu_id_string = mcu.series + mcu.group + mcu.capacity
#                 index = file_lines_cproject.index(line)
#                 file_lines_cproject[index] = file_lines_cproject[index].replace("R5F"+match.group(3), "R5F"+mcu_id_string);
#             if len(match.group(3))==9:
#                 mcu_id_string = mcu.series + mcu.group + mcu.capacity + mcu.version + "x" + mcu.package
#                 index = file_lines_cproject.index(line)
#                 file_lines_cproject[index] = file_lines_cproject[index].replace("R5F"+match.group(3), "R5F"+mcu_id_string);
#                 
#     cproject_search_patterns = []
#     search_pattern = re.compile(r"(.*)(WORKBENCH_SERIAL_CONNECT=\d{1})(.*)")
#     matches = [line for line in file_lines_cproject if r"WORKBENCH_SERIAL_CONNECT" in line]
#     
#     for line in matches:
#         match = re.search(search_pattern, line)
#         if match:
#             index = file_lines_cproject.index(line)
#             g2 = match.group(2)
#             replace = r"WORKBENCH_SERIAL_CONNECT=%s" % mcu.connect
#             file_lines_cproject[index] = file_lines_cproject[index].replace(match.group(2), r"WORKBENCH_SERIAL_CONNECT=%s" % mcu.connect)
# 
#     """ Output Project Configuration """
#     f_wr = open(outdir + "/.cproject", 'w')
#     for line in file_lines_cproject:
#         f_wr.write(line)
#     f_wr.close()
#     
#     """ Adjust Debugger Settings """
#     f_rd = open(outdir + "/Base_Project_RX%s DefaultBuild.launch" % mcu.family, 'r')
#     file_lines_debugger = f_rd.readlines()
#     f_rd.close()
#     rx_mcu_decomposer = r"(.*)(R5F)(\w*)(.*)"
#     search_pattern = re.compile(rx_mcu_decomposer)
#     matches = [line for line in file_lines_debugger if mcu.device[0:3] in line]
#     for line in matches:
#         match = re.search(search_pattern, line)
#         if match:
#             if len(match.group(3))==5:
#                 mcu_id_string = mcu.series + mcu.group + mcu.capacity
#                 index = file_lines_debugger.index(line)
#                 file_lines_debugger[index] = file_lines_debugger[index].replace("R5F"+match.group(3), "R5F"+mcu_id_string);
#             if len(match.group(3))==9:
#                 mcu_id_string = mcu.series + mcu.group + mcu.capacity + mcu.version + "x" + mcu.package
#                 index = file_lines_debugger.index(line)
#                 file_lines_debugger[index] = file_lines_debugger[index].replace("R5F"+match.group(3), "R5F"+mcu_id_string);
#     """ Output Project Configuration """
#     f_wr = open(outdir + "/Base_Project_RX%s DefaultBuild.launch" % mcu.family, 'w')
#     for line in file_lines_debugger:
#         f_wr.write(line)
#     f_wr.close()
#     
    """ Calculate PCLKB frequency """
    if mcu.family == "113" or mcu.family == "130":
        hoco_freq = 32000000
    elif mcu.family == "231" or mcu.family == "230":
        hoco_freq = 32000000 if int(mcu.hoco_freq) == 0 else 54000000
     
    if int(mcu.clk_src) == 1:
        """ Running using HOCO """
        frequency = hoco_freq
    elif int(mcu.clk_src) == 3:
        """ Running using Main Oscillator (no PLL)"""
        frequency = int(mcu.xtal_freq)
    elif int(mcu.clk_src) == 4:
        """ Running using PLL """
        frequency = (int(mcu.xtal_freq) * int(mcu.pll_m))/int(mcu.pll_d)
    else:
        logging.error("Invalid Clock Selection.")
        sys.exit(2)
        
    pclkb_freq = frequency/int(mcu.pclk_b)
    
#     """ Output BSP Configuration """
#     f_wr = open(outdir + "/r_config/r_bsp_config.h", 'w')
#     for line in file_lines_bsp:
#         f_wr.write(line)
#     f_wr.close()
    
    """ Create output from templates """
    for button in button_config.BUTTON.configs:
            button.write(button_config.BUTTON.template)
            
    button_config.write(outdir + "/src/button_config.c")

#     """ Change r_touch_button_config.h"""
#     f_rd = open(outdir + "/r_config/r_touch_button_config.h", 'r')
#     file_lines_button = f_rd.readlines()
#     f_rd.close()
#     
#     matches = [line for line in file_lines_button if "BUTTON_CFG_MAX_CONTROL_BLOCK_COUNT" in line]
#     count = len(button_config.BUTTON.configs) if len(button_config.BUTTON.configs) > 0 else 1
#     for match in matches:
#         file_lines_button[file_lines_button.index(match)] = "#define BUTTON_CFG_MAX_CONTROL_BLOCK_COUNT    (%d)\n" % (count if count > 0 else 1)
#     
#     f_wr = open(outdir + "/synergy_cfg/ssp_cfg/driver/sf_touch_button_cfg.h", 'w')
#     for line in file_lines_button:
#         f_wr.write(line)
#     f_wr.close()
    
#     """ SLIDER CONFIGURATION GENERATION """
#     for slider in slider_config.SLIDER.linear_configs:
#         slider.write(slider_config.SLIDER.linear_configs.index(slider))
#     for wheel in slider_config.SLIDER.circular_configs:
#         wheel.write(slider_config.SLIDER.circular_configs.index(wheel))
#         
#     """ Change r_touch_slider_config.h"""
#     f_rd = open(outdir + "/synergy_cfg/ssp_cfg/driver/r_touch_slider_config.h", 'r')
#     file_lines_slider = f_rd.readlines()
#     f_rd.close()
#     
#     matches = [line for line in file_lines_slider if "TOUCH_SLIDER_CFG_MAX_CONTROL_BLOCK_COUNT" in line]
#     count = (len(slider_config.SLIDER.circular_configs) + len(slider_config.SLIDER.linear_configs))
#     for match in matches:
#         file_lines_slider[file_lines_slider.index(match)] = "#define TOUCH_SLIDER_CFG_MAX_CONTROL_BLOCK_COUNT    (%d)\n" % (count if count > 0 else 1)
#     
#     f_wr = open(outdir + "/synergy_cfg/ssp_cfg/driver/r_touch_slider_config.h", 'w')
#     for line in file_lines_slider:
#         f_wr.write(line)
#     f_wr.close()
    
    
#     """ Write output files to disk. """
#     slider_config.write(outdir + "/src/slider_config.c")
    
    """ TOUCH CONFIGURATION GENERATION """
    touch_cfg_name = []
    touch_cfg_extern = []
    for touch_cfg in touch_config.TOUCH.configs:
        touch_cfg.write(touch_config.TOUCH.template, outdir + "/src/touch_config" + str(touch_config.TOUCH.configs.index(touch_cfg)) + ".c")
        touch_cfg_name.append("&%s" % touch_cfg.name)
        touch_cfg_extern.append("extern touch_instance_t %s" % touch_cfg.name)
        
    
    f_wr = open(outdir + "/src/touch_configs.c", 'w')
    f_wr.writelines(touch_config_template % {"extern":(";\n\r".join(touch_cfg_extern)),
                                             "name":(",\n\r".join(touch_cfg_name)),
                                             "count":len(touch_config.TOUCH.configs)})
    f_wr.close()
        
#     """ Change r_touch_cfg.h """
#     f_rd = open(outdir + "/synergy_cfg/ssp_cfg/driver/r_touch_cfg.h", 'r')
#     file_lines_touch = f_rd.readlines()
#     f_rd.close()
#     
#     matches = [line for line in file_lines_touch if "TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT" in line]
#     count = len(touch_config.TOUCH.configs) if len(touch_config.TOUCH.configs) > 0 else 1
#     for match in matches:
#         file_lines_touch[file_lines_touch.index(match)] = "#define TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT    (%d)\n" % (count)
# 
#     f_wr = open(outdir + "/synergy_cfg/ssp_cfg/driver/r_touch_cfg.h", 'w')
#     for line in file_lines_touch:
#         f_wr.write(line)
#     f_wr.close()
  
    """ CTSU CONFIGURATION GENERATION """
    ctsu_cfg_name = []
    ctsu_cfg_extern = []
    for ctsu_cfg in ctsu_config.CTSU.configs:
        ctsu_cfg.pclk = int(pclkb_freq)
        ctsu_cfg.write(ctsu_config.CTSU.template, outdir + "/src/ctsu_config" + str(ctsu_config.CTSU.configs.index(ctsu_cfg)) + ".c")
        ctsu_cfg_name.append("&%s" % ctsu_cfg.name)
        ctsu_cfg_extern.append("extern ctsu_instance_t %s" % ctsu_cfg.name)
        
    f_wr = open(outdir + "/src/ctsu_configs.c", 'w')
    f_wr.writelines(ctsu_config_template % {"extern":(";\n\r".join(ctsu_cfg_extern)),
                                             "name":(",\n\r".join(ctsu_cfg_name)),
                                             "count":len(touch_config.TOUCH.configs)})
    f_wr.close()
        
#     """ Change r_ctsu_rx_config.h"""
#     f_rd = open(outdir + "/r_config/r_ctsu_rx_config.h", 'r')
#     file_lines_ctsu = f_rd.readlines()
#     f_rd.close()
#     
#     matches = [line for line in file_lines_ctsu if "CTSU_CFG_MAX_CONTROL_BLOCK_COUNT" in line]
#     count = (len(ctsu_config.CTSU.configs)+1) if len(ctsu_config.CTSU.configs) > 0 else 2
#     for match in matches:
#         file_lines_ctsu[file_lines_ctsu.index(match)] = "#define CTSU_CFG_MAX_CONTROL_BLOCK_COUNT    (%d)\n" % (count)
# 
#     f_wr = open(outdir + "/r_config/r_ctsu_rx_config.h", 'w')
#     for line in file_lines_ctsu:
#         f_wr.write(line)
#     f_wr.close()
    
    
    ctsu_file = mcu.src + "/Include/CTSU/r_ctsu.h";
    touch_file = mcu.src + "/Include/Touch/r_touch.h";
    
    """ Adjust header files and output to disk."""
    ctsu_config.copy_clean_header(ctsu_file, outdir + "/src/")
    touch_config.copy_clean_header(touch_file, outdir + "/src/")
    
    """ Copy wbSetting folder to the Base Project """
    if os.path.exists(outdir + "/wbSetting") and os.path.exists(mcu.src + "/wbSetting"):
        logging.info("Copying from %s to %s " % (mcu.src + "/wbSetting", outdir + "/wbSetting"))
        for f_src in os.listdir(mcu.src + "/wbSetting"):
            if os.path.isfile(mcu.src + "/wbSetting/%s" % f_src)==True:
                shutil.copy(mcu.src + "/wbSetting/%s" % f_src, outdir + "/wbSetting/%s" % os.path.basename(f_src))    
    
    return

def unzip(src, dest):
    """ Unzip the base project to the target location"""
    with zipfile.ZipFile(src, "r") as z:
        z.extractall(dest)
        return 0
    return 1

if __name__ == '__main__':
    if sys.version_info < (2, 4):
        raise "must use python 2.5 or greater"

    parser = argparse.ArgumentParser(description='Parse a TouchAPI project generated by Workbench6 and create output for Synergy Project v2.0',
                                     epilog="Sample: python -B widget_parse_RX_raw.py --help")
    parser.add_argument('-l', '--log', dest='logfile', help='Specify where logger information should be output.')
    parser.add_argument('-c', '--ctsu', dest='ctsu', action='store_true', help='Only Configuration parameters related to the CTSU are generated')
    parser.add_argument('-t', '--tx', dest='tx', nargs='+', type=int, default=None, help='TS pin numbers to use as Transmit Pins for the CTSU.')
    parser.add_argument('-r', '--rx', dest='rx', nargs='+', type=int, default=None, help='TS pin numbers to use as Receive Pins for the CTSU.')
    
    required = parser.add_argument_group('required named arguments')
    required.add_argument('-i', '--input', dest='install', required=True, help='Specify full path to Workbench6 install.')
    required.add_argument('-p', '--wbp', dest='project', required=True, help='Specify full path to Project generated by Workbench6')
    required.add_argument('-o', '--output', dest='outdir', default=".", help='Specify full path for .c/.h output. E.g.: ./script_output')    
    args = parser.parse_args()
    
    if args.logfile is not None:
        logging.basicConfig(filename=args.logfile, level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
    else:
        logging.basicConfig(level=logging.INFO, format='%(module)s: %(asctime)s - %(levelname)s - %(message)s')
        
    """ Read MCU settings of the TouchAPI project """
    mcu = read(args.project)
    
    ctsu_file = args.project + "/Include/CTSU/r_ctsu.h";
    touch_file = args.project + "/Include/Touch/r_touch.h";
    
    """ Read the CTSU, TOUCH, BUTTON, SLIDER information. """
    ctsu_config.read(ctsu_file, args.tx, args.rx);
    touch_config.read(touch_file, ctsu_config.CTSU.configs)
    button_config.read(touch_config.TOUCH.configs)
#     slider_config.read(touch_config.TOUCH.configs)
    
    """ Write out all information """
    write(mcu, args.install, args.outdir)
    

    
    sys.exit(0)
