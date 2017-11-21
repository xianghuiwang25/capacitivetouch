import os
import sys
import argparse
import logging
import xml

import ctsu_config

if sys.version_info >= (3, 0):
    from tkinter import *
    import tkinter,tkFileDialog
    import tkMessageBox
else :
    from Tkinter import *
    import Tkinter,tkFileDialog
    import tkMessageBox
    
def getText(nodelist):
    rc = []
    for node in nodelist:
        if node.nodeType == node.TEXT_NODE:
            rc.append(node.data)
    return ''.join(rc)

def xml_read(srcdir, dstdir, instdir, xmlFile):
    if os.access(".", os.R_OK):
        if xmlFile==None:
            cfgFile = r"./fit_generator.xml"
        else:
            cfgFile = xmlFile
            
        if os.path.isabs(cfgFile)==False:
           cfgFile = os.path.abspath(cfgFile) 
        if os.path.isfile(cfgFile):
            xmlip = open(cfgFile, "r")
            doc = xml.dom.minidom.parse(xmlip)
            srcdir = getText(doc.getElementsByTagName("project")[0].childNodes)
            dstdir = getText(doc.getElementsByTagName("output")[0].childNodes)
            instdir = getText(doc.getElementsByTagName("install")[0].childNodes)
            xmlip.close()
            
    return (srcdir, dstdir, instdir, cfgFile)

def xml_write(srcdir, dstdir, instdir, xmlFile):
    
    def replaceText(node, newText):
        if node.firstChild.nodeType != node.TEXT_NODE:
            raise Exception("node does not contain text")
    
        node.firstChild.replaceWholeText(newText)
        return
    
    if os.access(".", os.W_OK):
        XML = """
        <config>
            <project>path</project>
            <output>path</output>
            <install>path</install>
        </config>
        """
        
        doc = xml.dom.minidom.parseString(XML)
        replaceText(doc.getElementsByTagName("project")[0], srcdir)
        replaceText(doc.getElementsByTagName("output")[0], dstdir)
        replaceText(doc.getElementsByTagName("install")[0], instdir)
            
        cfgFile = xmlFile
        
        if os.path.isabs(cfgFile)==False:
            cfgFile = os.path.abspath(cfgFile)
        
        try:
            outfile = open(cfgFile, 'w')
            doc.writexml(outfile)
            outfile.close()
    
        except IOError:
            logging.error("Failed to write output to file:%s" % outfile)
            raise;

class launcher():
    ########### Go button ############
    def bgo_callback(self):
        """ Gather required inputs """
        pclkb_freq = self.pclkb_freq.get();
        target_freq = { "4MHz":4000000, "2MHz":2000000, "1MHz":1000000, "0.5MHz":500000 }[self.target_freq_entry.get()];
        pclkb_div = {"1":0, "2":1, "4":2}[self.pclkb_div_entry.get()];
        mode = {"Self":0, "Mutual":1}[self.mode_entry.get()];
        
        ctsussdiv = ctsu_config.get_ctsussc(target_freq)>>8;
        ctsusnum = ctsu_config.get_ctsusnum(target_freq);
        ctsusdpa = ctsu_config.get_ctsusdpa(pclkb_freq,target_freq,pclkb_div);
        ctsuricoa = ctsu_config.get_ctsusricoa(mode);
        ctsuicog = ctsu_config.get_ctsuicog(target_freq);
        
        if ctsusdpa < 32:
            self.ctsusdpa.set(hex(ctsusdpa))
        else:
            self.ctsusdpa.set("Increment PCLKB divisor")
        
        self.ctsussdiv.set(hex(ctsussdiv))
        self.ctsusnum.set(hex(ctsusnum))        
        self.ctsuricoa.set(hex(ctsuricoa))
        self.ctsuicog.set(hex(ctsuicog))
        
        return
    
    def __init__(self, pclkb=None, pclkb_div=None, target_freq=None):
        """ Initializes the GUI window """
        self.pclkb = pclkb
        self.pclkb_div = pclkb_div
        self.target_freq = target_freq
        if self.pclkb == None:
            self.pclkb = "24000000"
        if self.pclkb_div == None:
            self.pclkb_div = "1"
        if self.target_freq == None:
            self.target_freq = "4MHz"
    
        self.execute = False
        # Create the window
        current_row=0
        
        self.root = Tk()
        self.root.title("CTSU SFR Calculator 1.0 ")
        
        root = self.root
        
        
        self.intro = Label(root, fg="red", justify=LEFT)
        self.intro.config(text="""Instructions:
            1. Select the target frequency for sensor operation.
            2. Provide PCLKB frequency used in your Synergy Project.
            3. Provide PCLKB divisor value input to the CTSU V2 HAL driver.
            4. Press Calculate to view CTSU SFR values."""
        )
        self.intro.grid(row=current_row, columnspan=2, sticky=W, padx=10, pady=10)
        
        current_row += 1

        
        ################# Target Frequency Selector ##################
        Label(root, text="Select Target Frequency for Sensor:", fg="dark red").grid(row=current_row, sticky=W, columnspan=2, padx=10)
        current_row += 1
        
        self.target_freq_options = [ "4MHz", "2MHz", "1MHz", "0.5MHz" ]
        option = self.target_freq_options
        self.target_freq_entry = StringVar(root)
        self.target_freq_entry.set(option[option.index(self.target_freq)] if self.target_freq in option else option[0]) # default value
        self.w = apply(OptionMenu, (root, self.target_freq_entry) + tuple(option))
        self.w.grid(row=current_row, column=0, sticky=W,padx=10)
        
        self.mode_options = [ "Self", "Mutual" ]
        option = self.mode_options
        self.mode_entry = StringVar(root)
        self.mode_entry.set(option[0]) # default value
        self.w = apply(OptionMenu, (root, self.mode_entry) + tuple(option))
        self.w.grid(row=current_row, column=1, sticky=W,padx=10)
        
        # Add a blank space
        Label(root, text="  ").grid(row=current_row)
        current_row += 1
        
        ############# PCLKB Frequency ###############
        Label(root, text="Provide PCLKB Frequency:", fg="dark red").grid(row=current_row, sticky=W, columnspan=2, padx=10)
        Label(root, text="PCLKB Divisor used:", fg="dark red").grid(row=current_row, column=1, sticky=W, columnspan=2, padx=10)
        current_row += 1
        self.pclkb_freq = IntVar()
        self.pclkb_freq.set(int(self.pclkb))
        self.pclkb_freq_entry = Entry(root, width=30, textvariable=self.pclkb_freq)
        self.pclkb_freq_entry.grid(row=current_row, column=0, padx=10)
        
        self.pclkb_div_options = [ "1", "2", "4" ]
        option = self.pclkb_div_options
        self.pclkb_div_entry = StringVar(root)
        self.pclkb_div_entry.set(option[option.index(self.pclkb_div)] if self.pclkb_div in option else option[0]) # default value
        self.pclkb_div = apply(OptionMenu, (root, self.pclkb_div_entry) + tuple(option))
        self.pclkb_div.grid(row=current_row, column=1, sticky=W,padx=10)
        
        current_row += 1
        
        
        ############# CTSUSSDIV[3:0] ###############
        Label(root, text="CTSUSSDIV[3:0]:", fg="dark green").grid(row=current_row, sticky=W, columnspan=2, padx=10)
        self.ctsussdiv = StringVar()
        self.ctsussdiv_entry = Entry(root, width=50, textvariable=self.ctsussdiv)
        self.ctsussdiv_entry.insert(0, "0x00")
        self.ctsussdiv_entry.grid(row=current_row, column=1, padx=10)
        current_row += 1
        
        ############# CTSUSNUM[5:0] ###############
        Label(root, text="CTSUSNUM[5:0]:", fg="dark green").grid(row=current_row, sticky=W, columnspan=2, padx=10)
        self.ctsusnum = StringVar()
        self.ctsusnum_entry = Entry(root, width=50, textvariable=self.ctsusnum)
        self.ctsusnum_entry.insert(0, "0x00")
        self.ctsusnum_entry.grid(row=current_row, column=1, padx=10)
        current_row += 1
        
        ############# CTSUICOG[1:0] ###############
        Label(root, text="CTSUICOG[1:0]:", fg="dark green").grid(row=current_row, sticky=W, columnspan=2, padx=10)
        self.ctsuicog = StringVar()
        self.ctsuicog_entry = Entry(root, width=50, textvariable=self.ctsuicog)
        self.ctsuicog_entry.insert(0, "0x00")
        self.ctsuicog_entry.grid(row=current_row, column=1, padx=10)
        current_row += 1
        
        ############# CTSUSDPA[4:0] ###############
        Label(root, text="CTSUSDPA[4:0]:", fg="dark green").grid(row=current_row, sticky=W, columnspan=2, padx=10)
        self.ctsusdpa = StringVar()
        self.ctsusdpa_entry = Entry(root, width=50, textvariable=self.ctsusdpa)
        self.ctsusdpa_entry.insert(0, "0x00")
        self.ctsusdpa_entry.grid(row=current_row, column=1, padx=10)
        current_row += 1
        
        ############# CTSURICOA[7:0] ###############
        Label(root, text="CTSURICOA[7:0]:", fg="dark green").grid(row=current_row, sticky=W, columnspan=2, padx=10)
        self.ctsuricoa = StringVar()
        self.ctsuricoa_entry = Entry(root, width=50, textvariable=self.ctsuricoa)
        self.ctsuricoa_entry.insert(0, "0x00")
        self.ctsuricoa_entry.grid(row=current_row, column=1, padx=10)
        current_row += 1
        
        
        # Add a blank space
        Label(root, text="  ").grid(row=current_row)
        current_row += 1

        Button(root, text="Calculate", width=10, command=self.bgo_callback, fg="dark blue").grid(row=current_row, column=1, padx=10, sticky=E)
        current_row += 1
        
        
        # Add a blank space
        Label(root, text="  ").grid(row=current_row)
        current_row += 1
        return
    
    def run(self):
        self.root.mainloop()
        return
        
if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Show CTSU SFR settings in a GUI',
                                     epilog="Sample: python -B ctsu_sft_calculator.py --help")

    parser.add_argument('-i', '--input', dest='pclkb', default="24000000", help='PCLKB Frequency.')               
    parser.add_argument('-d', '--divisor', dest='pclkb_div', default="1", help='PCLKB Divisor')     
    parser.add_argument('-o', '--output', dest='target_freq', default="4MHz", help='Sensor Target Frequency (4MHz, 2MHz, 1MHz, or 0.5MHz)')
    
    args = parser.parse_args()
    
    pclkb = args.pclkb
    pclkb_div = args.pclkb_div
    target_freq = args.target_freq

    main_launcher = launcher(pclkb, pclkb_div, target_freq)
    main_launcher.run()
    
    sys.exit(1)