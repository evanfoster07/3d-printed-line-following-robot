## April 15, 2026
- Solder pins onto TB6612FNG motor driver modules and test connections
- Verify motor driver function and test motors with simple control test logic

## April 17, 2026
- Wire and test sensors with breadboard and Serial Monitor readouts 
- Adjust sensor potentiometers to equalize measurement distances 

## April 22, 2026
- Start circuit schematic and create custom simplified modules in KiCAD
- Next: Finish KiCAD schematic

## April 23, 2026
- Finish custom simplified KiCAD models and implement in schematic
- Make wire connections in schematic and re-organize pin positions for readability
- Learned net labels greatly reduce wire clutter
- Next: Finish soldering components onto perfboard and write control logic 

## April 29, 2026
- Finished soldering main motor driver / control logic 
- Attached switch to control battery power delivery
- Tested hardware on perfboard with simple code 
- Next: Finish soldering (IR sensors) and implement line-following control 

## April 30, 2026
- Finished soldering IR sensor data and power wiring
- Tested sensor readings via Serial Monitor
- Implemented line-following control code
- Performed line-following tests with black construction paper 
- Implemented a search sequence when no sensors detect line 
- Issues: power brownouts began to occur at startup due to supply voltage sag despite power rail decoupling
- Next: finish documentation and confirm proper functionality with fresh batteries 