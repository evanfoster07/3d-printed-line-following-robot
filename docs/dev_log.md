## Early April 
- Began CAD wheel modelling, testing prototypes, hubcap designs, and wheel shaft fits
- Tested online print-in-place ball bearing models for rear wheels 
- Designed chassis including the following features:
    - Motor and perfboard mounting spots using M2 screws
    - Battery holder with slots to accomodate wiring 
    - Slots in bottom of chassis to accomodate sensor wiring and screw holes for mounting
- Designed a IR sensor holder to mount onto bottom of chassis, allowing range potentiometer tuning while securing sensors
- Printed and assembled all mechanical components, ensuring proper alignment and fit

## April 15, 2026
- Soldered pins onto TB6612FNG motor driver modules and tested connections
- Verified motor driver function and tested motors with simple control test logic

## April 17, 2026
- Wired and tested sensors with breadboard and Serial Monitor readouts 
- Adjusted sensor potentiometers to equalize measurement distances 

## April 22, 2026
- Started circuit schematic and create custom simplified modules in KiCAD
- Next: Finish KiCAD schematic

## April 23, 2026
- Finished custom simplified KiCAD models and implemented in schematic
- Made wire connections in schematic and re-organized pin positions for readability
- Learned net labels greatly reduce wire clutter
- Next: finish soldering components onto perfboard and write control logic 

## April 29, 2026
- Finished soldering main motor driver / control logic 
- Attached switch to control battery power delivery
- Tested hardware on perfboard with simple code 
- Next: finish soldering (IR sensors) and implement line-following control 

## April 30, 2026
- Finished soldering IR sensor data and power wiring
- Tested sensor readings via Serial Monitor
- Implemented line-following control code
- Performed line-following tests with black construction paper 
- Implemented a search sequence when no sensors detect line 
- Issues: power brownouts began to occur at startup due to supply voltage sag despite power rail decoupling
- Next: finish documentation and confirm proper functionality with fresh batteries 

## May 2, 2026
- Completed the majority of GitHub README.md, including hardware, electronics, control system and design documentation 
as well as certain challenges and future improvements 
- Cleaned up control code and organized actively used / utility functions 
- Next: add CAD, hardware, and wiring images to GitHub repository and start demonstration video 

