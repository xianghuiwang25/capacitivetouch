Here are the parameters I would like to see either locked, hidden or removed in this light version.  I realize that some of these aren’t possible but getting them in an email.

-Sensor ICO Variation Correction 
-Sensor ICO Calibration capability 
-Transmit Power supply pin (should be locked to optimal setting)
-High Pass noise reduction Function (should be locked to optimal setting)
-Variable drift rate (it’s always disabled now anyway)
-CTSU Information buffer names shouldn’t be configurable (I don’t understand the usecase), but if we want them to be configurable then we should remove or update verbiage from Workbench6 to CTW or whatever they’re inherited from. 

-The SFR settings:
CTSUSSDIV
CTSUSNUM
CTSUICOG
CTSUDPA
CTSURICOA
CTSUSO

I would prefer the PCLKB divisor, and CLK freq be inherited but I remember hearing that wasn’t possible. 

And I’m guessing we should probably have a better word for Receive and Transmit Chanel, since they’re not super intuitive.  


I still have questions about:
Paused Drift Compensations – Why do we include this function in a simple solution, and how do we configure it (what’s the use case).
Calibration upper and lower limit (I know I verbally requested those but don’t have them in my notes)
Offset Adjustment interval and threshold (I know I verbally requested those but don’t have them in my notes)
