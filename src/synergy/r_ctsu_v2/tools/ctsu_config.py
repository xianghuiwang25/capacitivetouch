#!/usr/bin/env python
import os
import re
import logging
import argparse
import random

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

ctsu_configs = []

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
* File Name    : ctsu_config.c
* Version      : 2.0
* Description  : This file contains CTSU SFR settings.
***********************************************************************************************************************/
#include "r_ctsu.h"
#include "r_ctsu_tuning.h"

"""

class SENSOR(object):
    xml_template = """
    <module id=\"module.driver.ctsu_sensor_on_ctsu.%(rand)d\">
      <property id=\"module.driver.ctsu_sensor.name\" value=\"CTSU_SENSOR_%(idx)d\"/>
      <property id=\"module.driver.ctsu_sensor.index\" value=\"%(idx)d\"/>
      <property id=\"module.driver.ctsu_sensor.rx\" value=\"module.driver.ctsu_sensor.rx.%(rx)s\"/>
      <property id=\"module.driver.ctsu_sensor.tx\" value=\"module.driver.ctsu_sensor.tx.%(tx)s\"/>
      <property id=\"module.driver.ctsu_sensor.ctsussdiv\" value=\"%(ssdiv)d\"/>
      <property id=\"module.driver.ctsu_sensor.ctsusnum\" value=\"%(snum)d\"/>
      <property id=\"module.driver.ctsu_sensor.ctsuicog\" value=\"%(icog)d\"/>
      <property id=\"module.driver.ctsu_sensor.ctsusdpa\" value=\"%(sdpa)d\"/>
      <property id=\"module.driver.ctsu_sensor.ctsuricoa\" value=\"%(ricoa)d\"/>
      <property id=\"module.driver.ctsu_sensor.ctsuso\" value=\"%(so)d\"/>
      <property id=\"module.driver.ctsu_sensor.sep1\" value=\"module.driver.ctsu_sensor.sep1.none\"/>
      <property id=\"module.driver.ctsu_sensor.threshold\" value=\"%(thr)d\"/>
      <property id=\"module.driver.ctsu_sensor.hysteresis\" value=\"%(hys)d\"/>
      <property id=\"module.driver.ctsu_sensor.dtouch\" value=\"3\"/>
      <property id=\"module.driver.ctsu_sensor.drelease\" value=\"3\"/>
      <property id=\"module.driver.ctsu_sensor.sep2\" value=\"module.driver.ctsu_sensor.sep2.none\"/>
      <property id=\"module.driver.ctsu_sensor.drift\" value=\"1000\"/>
      <property id=\"module.driver.ctsu_sensor.dr_accel\" value=\"0\"/>
      <property id=\"module.driver.ctsu_sensor.dr_decel\" value=\"0\"/>
      <property id=\"module.driver.ctsu_sensor.sep3\" value=\"module.driver.ctsu_sensor.sep3.none\"/>
      <property id=\"module.driver.ctsu_sensor.offset_interval\" value=\"1000\"/>
      <property id=\"module.driver.ctsu_sensor.offset_thresh\" value=\"100\"/>
    </module>
    """
    
    xml_stack = """
    <context id=\"_context.%(crand)d\">
        <stack module=\"module.driver.ctsu_sensor_on_ctsu.%(rand)d\">
            <stack module=\"module.driver.ctsu_on_ctsu.%(requires_ctsu)d\" requires=\"module.driver.ctsu_sensor.requires.ctsu\"/>
        </stack>
    </context>
    """
    
    def __init__(self, rx, tx, idx, ssdiv, so, snum, sdpa, ricoa, icog, thr, hys):
        self.rand  = random.randint(100000000,9999999999999)
        self.rx    = rx
        self.tx    = tx
        self.idx   = idx
        self.ssdiv = ssdiv 
        self.so    = so   
        self.snum  = snum 
        self.sdpa  = sdpa 
        self.ricoa = ricoa
        self.icog  = icog  
        self.threshold = thr
        self.hysteresis = hys
    
    def write(self, template = xml_template):
        self.xml = template % { 'rx'   : "%02d" % (self.rx)    ,
                                'tx'   : "none" if self.tx == None else "%02d" % (self.tx),
                                'idx'  :self.idx  ,
                                'ssdiv':self.ssdiv,
                                'so'   :self.so   ,
                                'snum' :self.snum ,
                                'sdpa' :self.sdpa ,
                                'ricoa':self.ricoa,
                                'icog' :self.icog ,
                                'thr'  :self.threshold,
                                'hys'  :self.hysteresis,
                                'rand' :self.rand,
                               }
        logging.debug(" Sensor XML output shown below:\n" + self.xml)
        
    def write_requires(self, requires_ctsu):
        self.xml_stack = SENSOR.xml_stack % {'rand' :self.rand,
                                            'requires_ctsu' : requires_ctsu,
                                            'crand':random.randint(10000000,99999999),
                                            }
        logging.debug(" Sensor XML requirement below:\n" + self.xml_stack)
        return

class CTSU(object):
    """ A CTSU configuration instance."""
    configs = []
    template = """
/* TODO: In the SSP Configurator, set Measurement method for CTSU Driver on r_ctsu: %(name)s_cfg to id %(id)s */    
#define CTSU_CFG_GENERATE    (1) //(%(generate)s)

static ctsu_const_sfrs_t %(name)s_common_sfrs = {
	.ctsucr0.byte     = %(CR0)s,
	.ctsucr1.byte     = %(CR1)s,
	.ctsusdprs.byte   = %(SDPRS)s,
	.ctsusst.byte     = %(SST)s,

	.ctsuchac0.byte   = %(CHAC0)s,
	.ctsuchac1.byte   = %(CHAC1)s,
	.ctsuchac2.byte   = %(CHAC2)s,
	.ctsuchac3.byte   = %(CHAC3)s,
	.ctsuchac4.byte   = %(CHAC4)s,

	.ctsuchtrc0.byte  = %(CHTRC0)s,
	.ctsuchtrc1.byte  = %(CHTRC1)s,
	.ctsuchtrc2.byte  = %(CHTRC2)s,
	.ctsuchtrc3.byte  = %(CHTRC3)s,
	.ctsuchtrc4.byte  = %(CHTRC4)s,

	.ctsudclkc.byte   = %(DCLKC)s,
};

static ctsu_sensor_setting_t %(name)s_sensor_settings[] =
{
\t%(sensor_setting)s
};

static uint16_t %(name)s_data_buffer[%(sensor_count)d];

#if (CTSU_CFG_GENERATE == 1)
static ctsu_cfg_t %(name)s_cfg = {
    /* One Time Settings */
    .p_ctsu_settings = &%(name)s_common_sfrs,
    /* Per channel settings */
    .p_sensor_settings = (ctsu_sensor_setting_t*)%(name)s_sensor_settings,
    .p_sensor_data = %(name)s_data_buffer,
	.pclkb_hz = %(pclk)d,	/* XXX: Replace with value used for PCLKB when tuning. */
	.p_callback = NULL,
#if (CTSU_CFG_ENABLE_MEASUREMENT_CORRECTION > 0)
	.correction_factor_pri_cal = %(corr_pri)d,
	.correction_factor_sec_cal = %(corr_sec)d,
	.correction_ctsuso_delta = %(corr_del)d,
#endif
};

static ctsu_instance_ctrl_t %(name)s_ctrl;

ctsu_instance_t const %(name)s = 
{
 .p_ctrl = &%(name)s_ctrl,
 .p_cfg  = &%(name)s_cfg,
 .p_api  = &g_ctsu_on_ctsu,
};

#endif
	"""
    
    xml_template = """ 
    <module id=\"module.driver.ctsu_on_ctsu.%(rand)d\">
      <property id=\"module.driver.ctsu.name\" value=\"%(name)s\"/>
      <property id=\"module.driver.ctsu.pclkb_div\" value=\"module.driver.ctsu.pclkb_div.div_%(pclkdiv)d\"/>
      <property id=\"module.driver.ctsu.mode\" value=\"module.driver.ctsu.mode.%(id)s\"/>
      <property id=\"module.driver.ctsu.txvsel\" value=\"module.driver.ctsu.txvsel.vcc\"/>
      <property id=\"module.driver.ctsu.ctsusoff\" value=\"module.driver.ctsu.ctsusoff.enabled\"/>
      <property id=\"module.driver.ctsu.data\" value=\"module.driver.data.workbench\"/>
      <property id=\"module.driver.ctsu.p_ctsu_settings\" value=\"%(name)s_common_sfrs\"/>
      <property id=\"module.driver.ctsu.p_sensor_settings\" value=\"%(name)s_sensor_settings\"/>
      <property id=\"module.driver.ctsu.p_sensor_data\" value=\"%(name)s_data_buffer\"/>
      <property id=\"module.driver.ctsu.pclkb_hz\" value=\"%(pclk)d\"/>
      <property id=\"module.driver.ctsu.p_callback\" value=\"NULL\"/>
      <property id=\"module.driver.ctsu.ts00\" value=\"module.driver.ctsu.ts00.%(ts00)s\"/>
      <property id=\"module.driver.ctsu.ts01\" value=\"module.driver.ctsu.ts01.%(ts01)s\"/>
      <property id=\"module.driver.ctsu.ts02\" value=\"module.driver.ctsu.ts02.%(ts02)s\"/>
      <property id=\"module.driver.ctsu.ts03\" value=\"module.driver.ctsu.ts03.%(ts03)s\"/>
      <property id=\"module.driver.ctsu.ts04\" value=\"module.driver.ctsu.ts04.%(ts04)s\"/>
      <property id=\"module.driver.ctsu.ts05\" value=\"module.driver.ctsu.ts05.%(ts05)s\"/>
      <property id=\"module.driver.ctsu.ts06\" value=\"module.driver.ctsu.ts06.%(ts06)s\"/>
      <property id=\"module.driver.ctsu.ts07\" value=\"module.driver.ctsu.ts07.%(ts07)s\"/>
      <property id=\"module.driver.ctsu.ts08\" value=\"module.driver.ctsu.ts08.%(ts08)s\"/>
      <property id=\"module.driver.ctsu.ts09\" value=\"module.driver.ctsu.ts09.%(ts09)s\"/>
      <property id=\"module.driver.ctsu.ts10\" value=\"module.driver.ctsu.ts10.%(ts10)s\"/>
      <property id=\"module.driver.ctsu.ts11\" value=\"module.driver.ctsu.ts11.%(ts11)s\"/>
      <property id=\"module.driver.ctsu.ts12\" value=\"module.driver.ctsu.ts12.%(ts12)s\"/>
      <property id=\"module.driver.ctsu.ts13\" value=\"module.driver.ctsu.ts13.%(ts13)s\"/>
      <property id=\"module.driver.ctsu.ts14\" value=\"module.driver.ctsu.ts14.%(ts14)s\"/>
      <property id=\"module.driver.ctsu.ts15\" value=\"module.driver.ctsu.ts15.%(ts15)s\"/>
      <property id=\"module.driver.ctsu.ts16\" value=\"module.driver.ctsu.ts16.%(ts16)s\"/>
      <property id=\"module.driver.ctsu.ts17\" value=\"module.driver.ctsu.ts17.%(ts17)s\"/>
      <property id=\"module.driver.ctsu.ts18\" value=\"module.driver.ctsu.ts18.%(ts18)s\"/>
      <property id=\"module.driver.ctsu.ts19\" value=\"module.driver.ctsu.ts19.%(ts19)s\"/>
      <property id=\"module.driver.ctsu.ts20\" value=\"module.driver.ctsu.ts20.%(ts20)s\"/>
      <property id=\"module.driver.ctsu.ts21\" value=\"module.driver.ctsu.ts21.%(ts21)s\"/>
      <property id=\"module.driver.ctsu.ts22\" value=\"module.driver.ctsu.ts22.%(ts22)s\"/>
      <property id=\"module.driver.ctsu.ts23\" value=\"module.driver.ctsu.ts23.%(ts23)s\"/>
      <property id=\"module.driver.ctsu.ts24\" value=\"module.driver.ctsu.ts24.%(ts24)s\"/>
      <property id=\"module.driver.ctsu.ts25\" value=\"module.driver.ctsu.ts25.%(ts25)s\"/>
      <property id=\"module.driver.ctsu.ts26\" value=\"module.driver.ctsu.ts26.%(ts26)s\"/>
      <property id=\"module.driver.ctsu.ts27\" value=\"module.driver.ctsu.ts27.%(ts27)s\"/>
      <property id=\"module.driver.ctsu.ts28\" value=\"module.driver.ctsu.ts28.%(ts28)s\"/>
      <property id=\"module.driver.ctsu.ts29\" value=\"module.driver.ctsu.ts29.%(ts29)s\"/>
      <property id=\"module.driver.ctsu.ts30\" value=\"module.driver.ctsu.ts30.%(ts30)s\"/>
      <property id=\"module.driver.ctsu.ts31\" value=\"module.driver.ctsu.ts31.%(ts31)s\"/>
      <property id=\"module.driver.ctsu.ts32\" value=\"module.driver.ctsu.ts32.%(ts32)s\"/>
      <property id=\"module.driver.ctsu.ts33\" value=\"module.driver.ctsu.ts33.%(ts33)s\"/>
      <property id=\"module.driver.ctsu.ts34\" value=\"module.driver.ctsu.ts34.%(ts34)s\"/>
      <property id=\"module.driver.ctsu.ts35\" value=\"module.driver.ctsu.ts35.%(ts35)s\"/>
      <property id=\"module.driver.ctsu.sep1\" value=\"module.driver.ctsu.sep1.none\"/>
    </module>
    <context id=\"_context.%(crand)d\">
        <stack module=\"module.driver.ctsu_on_ctsu.%(rand)d\"/>
    </context>
    """
    
    def __init__(self, sensors, pclk, en, itr=None, tx=None, rx=None):
        """ Create a CTSU Configuration with a given mode and channels"""
        mode = 0

        if tx==None:
            mode = self.mode = 0
        else:
            mode = self.mode = 1
        self.pclk = pclk
        self.itr = itr
        self.en = en
        self.tx = tx
        self.rx = rx
        
        if self.mode==0 and rx==None:
            self.rx = self.en
        
        self.num_sensors = 0
        name = "%(mode)s%(itr)s"
        name = "%(itr)s"
        name = name %{ 'mode': "self" if self.mode==0 else "mutual",
                        'itr': "" if itr==None else str(itr),}
        self.itr = 0 if itr == None else itr
        self.name = "g_ctsu"+ name
        self.SST = "(_00010000_CTSUSST_RECOMMEND)"
        self.DCLKC = "((_11_CTSUSSCNT<<4)|(_00_CTSUSSMOD<<0))"
        self.CHAC0 = "0"
        self.CHAC1 = "0"
        self.CHAC2 = "0"
        self.CHAC3 = "0"
        self.CHAC4 = "0"
        self.CHTRC0 = "0"
        self.CHTRC1 = "0"
        self.CHTRC2 = "0"
        self.CHTRC3 = "0"
        self.CHTRC4 = "0"
        self.corr_pri = 0
        self.corr_sec = 0
        self.corr_del = 0
        self.sensor = []
        self.output = None
        self.sensordata = sensors
        self.rand  = random.randint(100000000,9999999999999)

        en.sort();
        if mode==1:
            ## Mutual capacitance mode ##
            assert(tx != None)
            assert(itr != None)
            tx.sort();
            
            self.CR0 = "(MUTUAL%d_CTSUTXVSEL<<7)" % itr
            self.CR1 = "((_11_CTSUMD_MUTUAL<<6)|(MUTUAL%(itr)d_CTSUCLK_PCLKDIV<<4)|(MUTUAL%(itr)d_CTSUATUNE1<<3)|(_0_CTSUATUNE0_NORMAL<<2)|(_1_CTSUCSW_ON<<1)|(_1_CTSUPON_HW_POWER_ON<<0))" % {'itr':itr}
            self.SDPRS = "((MUTUAL%(itr)d_CTSUSOFF<<6)|(MUTUAL%(itr)d_CTSUPRMODE<<4)|(MUTUAL%(itr)d_CTSUPRRATIO<<0))" % {'itr':itr}
            
            for ch in en:
                if ch < 8:
                    self.CHAC0 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 16:
                    self.CHAC1 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 24:
                    self.CHAC2 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 32:
                    self.CHAC3 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 36:
                    self.CHAC4 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                else:
                    logging.error("Cannot use TS%02d" % ch)

            for ch in tx:
                if ch < 8:
                    self.CHTRC0 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 16:
                    self.CHTRC1 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 24:
                    self.CHTRC2 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 32:
                    self.CHTRC3 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                elif ch < 36:
                    self.CHTRC4 += "|(MUTUAL%d_ENABLE_TS%02d<<%d)" % (itr, ch, ch%8)
                else:
                    logging.error("Cannot use TS%02d" % ch)
            self.num_sensors = (len(en) - len(tx))*len(tx)
            
            rx_itr = 0;
            tx_itr = 0;
            for ch in range(0, self.num_sensors):
                sensor_setting = "{ .ctsussc = CTSUSSC_MUTUAL%(itr)d_KEY%(ch)02d,  .ctsuso0 = CTSUSO0_MUTUAL%(itr)d_KEY%(ch)02d,  .ctsuso1 = CTSUSO1_MUTUAL%(itr)d_KEY%(ch)02d, }, /* .rx = %(rx)d, .tx = %(tx)d */" % {'itr':itr, 
                                                                                                                                                                                                                        'ch':ch,
                                                                                                                                                                                                                        'tx': tx[tx_itr],
                                                                                                                                                                                                                        'rx':rx[rx_itr]}
                self.sensordata[itr].rx = rx[rx_itr]
                self.sensordata[itr].tx = tx[tx_itr]
                tx_itr += 1
                if tx_itr >= len(tx):
                    tx_itr = 0
                    rx_itr += 1
                self.sensor.append(sensor_setting)
        else:
            ## Self capacitance mode ##
            assert tx == None;
            self.CR0 = "(0x00)"
            self.CR1 = "((_01_CTSUMD_SELF_MULTI<<6)|(SELF_CTSUCLK_PCLKDIV<<4)|(SELF_CTSUATUNE1<<3)|(_0_CTSUATUNE0_NORMAL<<2)|(_1_CTSUCSW_ON<<1)|(_1_CTSUPON_HW_POWER_ON<<0))" % {'itr':itr,}
            self.SDPRS = "((SELF_CTSUSOFF<<6)|(SELF_CTSUPRMODE<<4)|(SELF_CTSUPRRATIO<<0))"

            for ch in en:
                sensor_setting = "{ .ctsussc = CTSUSSC_TS%(ch)02d,  .ctsuso0 = CTSUSO0_TS%(ch)02d,  .ctsuso1 = CTSUSO1_TS%(ch)02d, }," % {'ch':ch}
                self.sensordata[en.index(ch)].rx = ch
                self.sensordata[en.index(ch)].tx = None
                self.sensor.append(sensor_setting)
                if ch < 8:
                    self.CHAC0 += "|(SELF%s_ENABLE_TS%02d<<%d)" % (str(itr) if (itr!=None) else "", ch, ch%8)
                elif ch < 16:
                    self.CHAC1 += "|(SELF%s_ENABLE_TS%02d<<%d)" % (str(itr) if (itr!=None) else "", ch, ch%8)
                elif ch < 24:
                    self.CHAC2 += "|(SELF%s_ENABLE_TS%02d<<%d)" % (str(itr) if (itr!=None) else "", ch, ch%8)
                elif ch < 32:
                    self.CHAC3 += "|(SELF%s_ENABLE_TS%02d<<%d)" % (str(itr) if (itr!=None) else "", ch, ch%8)
                elif ch < 36:
                    self.CHAC4 += "|(SELF%s_ENABLE_TS%02d<<%d)" % (str(itr) if (itr!=None) else "", ch, ch%8)
                else:
                    logging.error("Cannot use TS%02d" % ch)
            self.num_sensors = len(en)
        
        logging.info(self.name)
        logging.info(self.CR0)
        logging.info(self.CR1)
        logging.info(self.SDPRS)
        logging.info(self.SST)
        logging.info(self.DCLKC)
        logging.info(self.CHAC0)
        logging.info(self.CHAC1)
        logging.info(self.CHAC2)
        logging.info(self.CHAC3)
        logging.info(self.CHAC4)
        logging.info(self.CHTRC0)
        logging.info(self.CHTRC1)
        logging.info(self.CHTRC2)
        logging.info(self.CHTRC3)
        logging.info(self.CHTRC4)
        logging.info("\n"+"\n".join(self.sensor))
        return
    
    def write(self, template, output=None, generate=True):
        self.output = template % { 'name':self.name,
                                'CR0': self.CR0,
                                'CR1': self.CR1,
                                'SDPRS': self.SDPRS,
                                'SST':self.SST,
                                'DCLKC':self.DCLKC,
                                'CHAC0':self.CHAC0,
                                'CHAC1':self.CHAC1,
                                'CHAC2':self.CHAC2,
                                'CHAC3':self.CHAC3,
                                'CHAC4':self.CHAC4,
                                'CHTRC0':self.CHTRC0,
                                'CHTRC1':self.CHTRC1,
                                'CHTRC2':self.CHTRC2,
                                'CHTRC3':self.CHTRC3,
                                'CHTRC4':self.CHTRC4,
                                'sensor_setting':"\n\t".join(self.sensor),
                                'sensor_count': (self.num_sensors * (2 if self.mode == 0 else 4)),
                                'pclk':self.pclk,
                                'corr_pri':self.corr_pri,
                                'corr_sec':self.corr_sec,
                                'corr_del':self.corr_del,
                                'generate':"1" if generate == True else "0",
                                'id': "SELF" if self.mode==0 else ("MUTUAL%d" % self.itr)
                                }
        logging.debug("Output shown below:\n" + self.output)
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
    
    def write_xml(self, template=xml_template, outfile=None, generate=True):
        
        for pclkbdiv in range(0, 3):
            ctsusdpa = get_ctsusdpa(self.pclk, 500000, pclkbdiv)
            if ctsusdpa < 32:
                break
        self.xml = []
        output = template % { 'name':self.name,
                               'pclk':self.pclk,
                               'id': "self" if self.mode==0 else ("mutual%d" % self.itr),
                               'pclkdiv': (1 << pclkbdiv),
                               'ts00':"receive" if ( 0 in self.rx) else "transmit" if ((self.tx!=None) and( 0 in self.tx)) else "unused",
                               'ts01':"receive" if ( 1 in self.rx) else "transmit" if ((self.tx!=None) and( 1 in self.tx)) else "unused",
                               'ts02':"receive" if ( 2 in self.rx) else "transmit" if ((self.tx!=None) and( 2 in self.tx)) else "unused",
                               'ts03':"receive" if ( 3 in self.rx) else "transmit" if ((self.tx!=None) and( 3 in self.tx)) else "unused",
                               'ts04':"receive" if ( 4 in self.rx) else "transmit" if ((self.tx!=None) and( 4 in self.tx)) else "unused",
                               'ts05':"receive" if ( 5 in self.rx) else "transmit" if ((self.tx!=None) and( 5 in self.tx)) else "unused",
                               'ts06':"receive" if ( 6 in self.rx) else "transmit" if ((self.tx!=None) and( 6 in self.tx)) else "unused",
                               'ts07':"receive" if ( 7 in self.rx) else "transmit" if ((self.tx!=None) and( 7 in self.tx)) else "unused",
                               'ts08':"receive" if ( 8 in self.rx) else "transmit" if ((self.tx!=None) and( 8 in self.tx)) else "unused",
                               'ts09':"receive" if ( 9 in self.rx) else "transmit" if ((self.tx!=None) and( 9 in self.tx)) else "unused",
                               'ts10':"receive" if (10 in self.rx) else "transmit" if ((self.tx!=None) and(10 in self.tx)) else "unused",
                               'ts11':"receive" if (11 in self.rx) else "transmit" if ((self.tx!=None) and(11 in self.tx)) else "unused",
                               'ts12':"receive" if (12 in self.rx) else "transmit" if ((self.tx!=None) and(12 in self.tx)) else "unused",
                               'ts13':"receive" if (13 in self.rx) else "transmit" if ((self.tx!=None) and(13 in self.tx)) else "unused",
                               'ts14':"receive" if (14 in self.rx) else "transmit" if ((self.tx!=None) and(14 in self.tx)) else "unused",
                               'ts15':"receive" if (15 in self.rx) else "transmit" if ((self.tx!=None) and(15 in self.tx)) else "unused",
                               'ts16':"receive" if (16 in self.rx) else "transmit" if ((self.tx!=None) and(16 in self.tx)) else "unused",
                               'ts17':"receive" if (17 in self.rx) else "transmit" if ((self.tx!=None) and(17 in self.tx)) else "unused",
                               'ts18':"receive" if (18 in self.rx) else "transmit" if ((self.tx!=None) and(18 in self.tx)) else "unused",
                               'ts19':"receive" if (19 in self.rx) else "transmit" if ((self.tx!=None) and(19 in self.tx)) else "unused",
                               'ts20':"receive" if (20 in self.rx) else "transmit" if ((self.tx!=None) and(20 in self.tx)) else "unused",
                               'ts21':"receive" if (21 in self.rx) else "transmit" if ((self.tx!=None) and(21 in self.tx)) else "unused",
                               'ts22':"receive" if (22 in self.rx) else "transmit" if ((self.tx!=None) and(22 in self.tx)) else "unused",
                               'ts23':"receive" if (23 in self.rx) else "transmit" if ((self.tx!=None) and(23 in self.tx)) else "unused",
                               'ts24':"receive" if (24 in self.rx) else "transmit" if ((self.tx!=None) and(24 in self.tx)) else "unused",
                               'ts25':"receive" if (25 in self.rx) else "transmit" if ((self.tx!=None) and(25 in self.tx)) else "unused",
                               'ts26':"receive" if (26 in self.rx) else "transmit" if ((self.tx!=None) and(26 in self.tx)) else "unused",
                               'ts27':"receive" if (27 in self.rx) else "transmit" if ((self.tx!=None) and(27 in self.tx)) else "unused",
                               'ts28':"receive" if (28 in self.rx) else "transmit" if ((self.tx!=None) and(28 in self.tx)) else "unused",
                               'ts29':"receive" if (29 in self.rx) else "transmit" if ((self.tx!=None) and(29 in self.tx)) else "unused",
                               'ts30':"receive" if (30 in self.rx) else "transmit" if ((self.tx!=None) and(30 in self.tx)) else "unused",
                               'ts31':"receive" if (31 in self.rx) else "transmit" if ((self.tx!=None) and(31 in self.tx)) else "unused",
                               'ts32':"receive" if (32 in self.rx) else "transmit" if ((self.tx!=None) and(32 in self.tx)) else "unused",
                               'ts33':"receive" if (33 in self.rx) else "transmit" if ((self.tx!=None) and(33 in self.tx)) else "unused",
                               'ts34':"receive" if (34 in self.rx) else "transmit" if ((self.tx!=None) and(34 in self.tx)) else "unused",
                               'ts35':"receive" if (35 in self.rx) else "transmit" if ((self.tx!=None) and(35 in self.tx)) else "unused",
                               'rand':self.rand,
                               'crand':random.randint(10000000,99999999),
                               }
        
        self.xml.append(output)
        
        for itr in range(0, self.num_sensors):
            self.sensordata[itr].write()
            self.xml.append(self.sensordata[itr].xml)
            
        for itr in range(0, self.num_sensors):
            self.sensordata[itr].write_requires(self.rand)
            self.xml.append(self.sensordata[itr].xml_stack)
            
        self.xml = '\n'.join(self.xml)
        
        logging.info("XML output shown below:\n" + self.xml)
        
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
    
    def correction(self, corr_del, corr_pri, corr_sec=None):
        self.corr_del = corr_del
        self.corr_pri = corr_pri
        self.corr_sec = (0 if corr_sec == None else corr_sec)
        return

def read(infile, tx=None, rx=None):
    """" Create a CTSU instances from by reading Workbench6 generated file (r_ctsu.h). """
    try:
        infile = open(infile, 'r');
        file_lines_ctsu = infile.readlines();
        infile.close();
    except IOError:
        logging.error("Could not access input file:%s" % infile)
        raise
        
    ctsu_search_patterns = []
    ctsu_search_patterns.append(r"(#define\s*SELF_METHOD_NUM\s*\((\d{1})\))")                    ##00
    ctsu_search_patterns.append(r"(#define\s*MUTUAL_METHOD_NUM\s*\((\d{1,2})\))")                ##01

    for line in file_lines_ctsu:
        for ctsu_search_pattern in ctsu_search_patterns:
            search_pattern = re.compile(ctsu_search_pattern)
            match = re.search(search_pattern,line)
            if match:
                if 0 == ctsu_search_patterns.index(ctsu_search_pattern):
                    num_self = int(match.group(2))
                    logging.info("Found SELF_METHOD_NUM=%d" % num_self)
                elif 1 == ctsu_search_patterns.index(ctsu_search_pattern):
                    num_mutual = int(match.group(2))
                    logging.info("Found MUTUAL_METHOD_NUM=%d" % num_mutual)

    enabled_channels_rx = []
    enabled_channels_tx = []
    enabled_channels_en = []

    if(rx!=None):
        ## Make sure that user is passing in expected arguments ##
        assert ((num_mutual > 0) or (num_self > 0))
        

        
    if(tx!=None):
        ## Make sure that user is passing in expected arguments ##
        try:
            assert num_mutual > 0
            assert rx!=None
        except AssertionError:
            logging.error("Malformed argument. TX channel list provided without RX channel list or when MUTUAL_METHOD_NUM==0")
            raise

    for itr in range(0, num_mutual):
        logging.info("-----Checking MUTUAL%d-----",itr);
        ctsu_sfr_mutual_settings = [];
        en_channels = []
        tx_channels = []
        rx_channels = []
        ## Look for widgets in Mutual-Capacitance mode ##
        mutual_search_patterns = []
        mutual_search_patterns.append(r"(#define\s*MUTUAL"+str(itr)+"_ENABLE_TS(\d{2})\s*\((\d{1})\))")    ##00
        mutual_search_patterns.append(r"(#define\s*MUTUAL"+str(itr)+"_FUNCTION_TS(\d{2})\s*\((.*)\))")     ##01

        for mutual_search_pattern in mutual_search_patterns:
            search_pattern = re.compile(mutual_search_pattern)
            for line in file_lines_ctsu:
                match = re.search(search_pattern,line)
                if match:
                    if 0 == mutual_search_patterns.index(mutual_search_pattern):
                        if match.group(3)=="1":
                            en_channels.append(int(match.group(2)))
                    if 1 == mutual_search_patterns.index(mutual_search_pattern):
                        if match.group(3)=="RECEPTION_FUNCITON" and int(match.group(2)) in en_channels:
                            logging.info("TS%s is in RX mode" % match.group(2))
                            rx_channels.append(int(match.group(2)))
                        elif match.group(3)=="TRANSMISSION_FUNCITON" and int(match.group(2)) in en_channels:
                            logging.info("TS%s is in TX mode" % match.group(2))
                            tx_channels.append(int(match.group(2)))

        
        tx_channels.sort();
        rx_channels.sort();
        
        if tx != None:
            if True == set(tx).issubset(set(tx_channels)):
                tx_channels = tx
                logging.info("Using user provided subset TS pins as TX: %s" % tx_channels)


        if rx != None:
            if True == set(rx).issubset(set(rx_channels)):
                rx_channels = rx
                logging.info("Using user provided subset TS pins as RX: %s" % rx_channels)

        enabled_channels_tx = tx_channels
        enabled_channels_rx = rx_channels
        enabled_channels_en = tx_channels + rx_channels;
        
        logging.info(enabled_channels_en)
        logging.info(enabled_channels_tx)
        
        ctsu_sensors = []
        
        for ch in range(0, len(tx_channels)*len(rx_channels)):
            ctsu_sensor = SENSOR(255, 255, ch, 0, 0, 0, 0, 0, 0, 1000, 100)
            search_pattern_ssdiv = r"(#define\s*CTSUSSDIV_MUTUAL"+str(itr)+"_KEY%(key_idx)02d\s*\((0[xX][0-9a-fA-F]+)\))" % {'key_idx' : ch}      ##00
            search_pattern_so    = r"(#define\s*CTSUSO_MUTUAL"+str(itr)+"_KEY%(key_idx)02d\s*\((0[xX][0-9a-fA-F]+)\))"    % {'key_idx' : ch}      ##01
            search_pattern_snum  = r"(#define\s*CTSUSNUM_MUTUAL"+str(itr)+"_KEY%(key_idx)02d\s*\((\d{1})\))"    % {'key_idx' : ch}                ##02
            search_pattern_sdpa  = r"(#define\s*CTSUSDPA_MUTUAL"+str(itr)+"_KEY%(key_idx)02d\s*\((\d{1,2}|0[xX][0-9a-fA-F]+)\))"  % {'key_idx' : ch}      ##03
            search_pattern_ricoa = r"(#define\s*(CTSURICOA_MUTUAL"+str(itr)+"|CTSURICOA_MUTUAL"+str(itr)+"_KEY%(key_idx)02d)\s*\((0[xX][0-9a-fA-F]+)\))" % {'key_idx' : ch}      ##04
            search_pattern_icog  = r"(#define\s*CTSUICOG_MUTUAL"+str(itr)+"_KEY%(key_idx)02d\s*\((\d{1})\))"    % {'key_idx' : ch}                ##05
            
            mutual_search_patterns = []
            mutual_search_patterns.append(search_pattern_ssdiv)    ##00
            mutual_search_patterns.append(search_pattern_so)       ##01
            mutual_search_patterns.append(search_pattern_snum)     ##02
            mutual_search_patterns.append(search_pattern_sdpa)     ##03
            mutual_search_patterns.append(search_pattern_ricoa)    ##04
            mutual_search_patterns.append(search_pattern_icog)     ##05
            
            for mutual_search_pattern in mutual_search_patterns:
                search_pattern = re.compile(mutual_search_pattern)
                for line in file_lines_ctsu:
                    match = re.search(search_pattern,line)
                    if match:
                        if 0 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.ssdiv = int(match.group(2),16)
                        if 1 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.so    = int(match.group(2),16)
                        if 2 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.snum  = int(match.group(2))
                        if 3 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.sdpa  = int(match.group(2),16)
                        if 4 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.ricoa = int(match.group(3),16)
                        if 5 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.icog  = int(match.group(2),16)
            
            ctsu_sensors.append(ctsu_sensor)
        
        ctsu = CTSU(ctsu_sensors, 0, enabled_channels_en, itr, enabled_channels_tx, enabled_channels_rx)
        CTSU.configs.append(ctsu)

    enabled_channels_rx = []
    enabled_channels_tx = [] 

    if num_self > 0:
        logging.info("-----Checking SELF-----");
        try:
            assert tx== None
        except AssertionError:
            logging.error("Malformed argument. TX channel list should not be passed if SELF_METHOD_NUM > 0 in r_ctsu.h.")
            return;

        ## Look for channels in Self-capacitance mode ##
        self_search_patterns = []
        ctsu_self_sfr_settings = [];
        self_search_patterns.append(r"(#define\s*SELF_ENABLE_TS(\d{2})\s*\((\d{1})\))")                 ##00
        for self_search_pattern in self_search_patterns:
            search_pattern = re.compile(self_search_pattern)
            for line in file_lines_ctsu:
                match = re.search(search_pattern,line)
                if match:
                    if 0 == self_search_patterns.index(self_search_pattern):
                        if match.group(3)=="1":
                            logging.info("Found TS%s Enabled" % match.group(2))
                            channel_num = match.group(2)
                            enabled_channels_rx.append(int(channel_num))

        logging.info("RX channel list: %s", str(enabled_channels_rx))
        if rx != None:
            keep_channels_rx = []
            for channel in rx:
                if channel in enabled_channels_rx:
                    logging.info("Keeping TS%02d" % channel)
                    keep_channels_rx.append(channel)
                else:
                    ## Malformed argument ##
                    logging.error("TS%02d was not enabled" % channel)
                    return;
            enabled_channels_rx = keep_channels_rx;
            
        ctsu_sensors = []
            
        for ch in enabled_channels_rx:
            ctsu_sensor = SENSOR(255, 255, ch, 0, 0, 0, 0, 0, 0, 1000, 100)
            search_pattern_ssdiv = r"(#define\s*CTSUSSDIV_TS%(key_idx)02d\s*\((0[xX][0-9a-fA-F]+)\))" % {'key_idx' : ch}      ##00
            search_pattern_so    = r"(#define\s*CTSUSO_TS%(key_idx)02d\s*\((0[xX][0-9a-fA-F]+)\))"    % {'key_idx' : ch}      ##01
            search_pattern_snum  = r"(#define\s*CTSUSNUM_TS%(key_idx)02d\s*\((\d{1})\))"    % {'key_idx' : ch}                ##02
            search_pattern_sdpa  = r"(#define\s*CTSUSDPA_TS%(key_idx)02d\s*\((\d{1,2}|0[xX][0-9a-fA-F]+)\))"  % {'key_idx' : ch}      ##03
            search_pattern_ricoa = r"(#define\s*(CTSURICOA_TS|CTSURICOA_TS%(key_idx)02d)\s*\((0[xX][0-9a-fA-F]+)\))" % {'key_idx' : ch}      ##04
            search_pattern_icog  = r"(#define\s*CTSUICOG_TS%(key_idx)02d\s*\((\d{1})\))"    % {'key_idx' : ch}
            
            mutual_search_patterns = []
            mutual_search_patterns.append(search_pattern_ssdiv)    ##00
            mutual_search_patterns.append(search_pattern_so)       ##01
            mutual_search_patterns.append(search_pattern_snum)     ##02
            mutual_search_patterns.append(search_pattern_sdpa)     ##03
            mutual_search_patterns.append(search_pattern_ricoa)    ##04
            mutual_search_patterns.append(search_pattern_icog)     ##05
            
            for mutual_search_pattern in mutual_search_patterns:
                search_pattern = re.compile(mutual_search_pattern)
                for line in file_lines_ctsu:
                    match = re.search(search_pattern,line)
                    if match:
                        if 0 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.ssdiv = int(match.group(2),16)
                        if 1 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.so    = int(match.group(2),16)
                        if 2 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.snum  = int(match.group(2))
                        if 3 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.sdpa  = int(match.group(2),16)
                        if 4 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.ricoa = int(match.group(3),16)
                        if 5 == mutual_search_patterns.index(mutual_search_pattern):
                            ctsu_sensor.icog  = int(match.group(2),16)
                            
            ctsu_sensors.append(ctsu_sensor)
                           
#         ctsu = CTSU(0, enabled_channels_rx, num_mutual)
        
        ctsu = CTSU(ctsu_sensors, 0, enabled_channels_rx)
        CTSU.configs.append(ctsu)

def copy_clean_header(infile, outfile):
    """ Remove unused definitions from the CTSU settings header file. """
    ## Read Original File ##
    try:
        infile = open(infile, 'r');
        file_lines_ctsu = infile.readlines();
        infile.close();
    except IOError:
        logging.error("Could not access input file:%s" % infile)
        raise

    logging.info("Dir Name: %s" % os.path.dirname(outfile))
    outpath = os.path.dirname(outfile);
    outfile = outpath + "/r_ctsu_tuning.h"
    ## File Clean up ##
    ctsu_stdinth_add_index = [line for line in file_lines_ctsu if "Includes" in line]
    ctsu_stdinth_add_index = file_lines_ctsu.index(ctsu_stdinth_add_index[0])+ 2
    file_lines_ctsu.insert(ctsu_stdinth_add_index, "#include <stdint.h>\n\n")

    ctsu_clean_start_index = [line for line in file_lines_ctsu if "Global variables" in line]
    ctsu_clean_end_index = [line for line in file_lines_ctsu if "#endif    // __R_CTSU_H__" in line]

    clean_start_index = file_lines_ctsu.index(ctsu_clean_start_index[0]) + 2
    clean_end_index = file_lines_ctsu.index(ctsu_clean_end_index[0])
    del file_lines_ctsu[clean_start_index:clean_end_index]


    matches = [line for line in file_lines_ctsu if "#include \"r_cg_macrodriver.h\"" in line]
    if matches:
        for match in matches:
            index = file_lines_ctsu.index(match)
            del file_lines_ctsu[index]
    ## Copy clean file ##
    try:
        if not os.path.exists(outpath):
            os.makedirs(outpath);
        outfile = open(outfile, 'w+');
        for line in file_lines_ctsu:
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

def get_ctsusdpa(pclkb, target_freq, ctsuclk):
    pclkb_actual = pclkb/(1<<ctsuclk);
    sdpa_setting = ((pclkb_actual / target_freq)>>1) - 1;
    return sdpa_setting

def get_ctsussc(target_freq):
    ctsussdiv = 0
    
    if target_freq < 4000000:
        ctsussdiv = 1
    if target_freq < 2000000:
        ctsussdiv = 2
    if target_freq < 1330000:
        ctsussdiv = 3
    if target_freq < 1000000:
        ctsussdiv = 4
    if target_freq < 800000:
        ctsussdiv = 5
    if target_freq < 670000:
        ctsussdiv = 6
    if target_freq < 570000:
        ctsussdiv = 7
    if target_freq < 500000:
        ctsussdiv = 8
    if target_freq < 440000:
        ctsussdiv = 9
    if target_freq < 400000:
        ctsussdiv = 10
    if target_freq < 360000:
        ctsussdiv = 11
    if target_freq < 330000:
        ctsussdiv = 12
    if target_freq < 310000:
        ctsussdiv = 13
    if target_freq < 290000:
        ctsussdiv = 14
    if target_freq < 270000:
        ctsussdiv = 15

    return ctsussdiv << 8

def get_ctsusnum(target_freq):
    ctsusnum = 7
       
    if target_freq < 4000000:
        ctsusnum = 3
    if target_freq < 2000000:
        ctsusnum = 1
    if target_freq < 1000000:
        ctsusnum = 0
        
    return ctsusnum

def get_ctsuso0(targetfreq, bias):
    ctsuso0 = (get_ctsusnum(targetfreq) << 10 | (bias & 0x3FF))
    return ctsuso0

def get_ctsuicog(targetfreq):
    return 1

def get_ctsusricoa(mode):
    return 0x3F if mode == 1 else 0x5F

def get_ctsuso1(pclkb, targetfreq, ctsuclk, mode):
    ctsusdpa = get_ctsusdpa(pclkb, targetfreq, ctsuclk)
    ctsuicog = get_ctsuicog(targetfreq)
    ctsuricoa = get_ctsusricoa(mode)
    return (ctsuicog << 13) | (ctsusdpa << 8) | ctsuricoa

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=
                                     """
                                     Create a CTSU configuration instance from a Workbench6 auto-generated file (r_ctsu.h).
                                     """)
    parser.add_argument('-t', '--tx', dest='tx', nargs='+', type=int, help='(optional)Specify TS pin numbers to use as Transmit Pins for the CTSU.')
    parser.add_argument('-r', '--rx', dest='rx', nargs='+', type=int, help='(optional)Specify TS pin numbers to use as Receive Pins for the CTSU.')
    parser.add_argument('-o', '--output', dest='outfile', default="./output.c", help='Specify full path and file name for C output. E.g.: ./r_ctsu_rx_config_self01.c')
    parser.add_argument('-l', '--log', dest='logfile', help='Specify where logger information should be output.')
    parser.add_argument('-i', '--input', dest='infile', help='Specify full path to r_ctsu.h. E.g.: ./TouchAPI_XXXX/CTSU/r_ctsu.h')
    parser.add_argument('-x', '--xml', dest='xmlgen', action='store_true', default=False, help='Generate XML for importing to ISDE')    

    parser.add_argument('-g', '--generate', dest='generate', action='store_true', help='Generate Preprocessor values. --input value is ignored.')
    parser.add_argument('-f', '--frequency', dest='freq', nargs='+', type=int, help='Target drive frequency. Provide a common setting or setting for each sensor.')
    parser.add_argument('-b', '--bias', dest='offset', nargs='+', type=int, help='CTSUSO SFR setting. Provide a common setting or setting for each sensor. ')
    parser.add_argument('-p', '--pclkb', dest='pclkb', type=int, help='PCLKB setting used for the microcontroller.')
    parser.add_argument('-d', '--div', dest='pclkbdiv', type=int, help='PCLKB Divisor setting for the CTSU SFR CTSUCLK[1:0].')
    parser.add_argument('-v', '--txvsel', dest='txvsel', type=int, default=0, help='CTSUTXVSEL value.')
    parser.add_argument('-c', '--count', dest='count', type=int, help='Identification counter for the settings')
    parser.add_argument('--version', action='version', version='%(prog)s 2.1')
    
    args = parser.parse_args()
    
    in_file = args.infile;
    out_file = args.outfile;

    if args.logfile is not None:
        logging.basicConfig(filename=args.logfile, level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
    else:
        logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

    if args.generate==True:
        """Generate parameters using information provided in arguments"""       
        generate(args.pclkb, args.offset, args.freq, args.rx, args.txvsel, args.count, args.tx)
    else:
        assert(in_file!=None)
        """ Generate parameters by reading a r_ctsu.h file"""
        read(in_file, args.tx, args.rx)
        copy_clean_header(in_file, out_file)

    filename, file_extension = os.path.splitext(out_file)
    
    logging.info("Number of Configurations read := %d" % len(CTSU.configs))

    itr = 0;
    for ctsu in CTSU.configs:
        ctsu.write(CTSU.template, filename+ str(itr)+file_extension)
        if args.xmlgen==True:
            ctsu.write_xml(CTSU.xml_template, "./out.xml")
        itr+=1
