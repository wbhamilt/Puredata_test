# digitalfretboard
This is the codebase for a project intended to build a synthesizer with a button layout that mimicked that of a guitar fretboard.
The project was made up of a Arduino midi controller that was connected to a laptop running Pure Data.
[inclde links to images]

# PD files/Poly Synth
These files are intended to be run by Pure Data - https://puredata.info/. 

# Arduino Nano Sketch
This is a file that existed for a version of the midi controller that used an Arduino Nano. The Arduino Nano does NOT have an ATmega32U4,
so an external female midi end must be connected to the board.

# Arduino Leonardo Sketch
The final version of this project was build on an Arduino Leonardo, which allowed it to be recognized as a USB device over midi using the MIDIUSB library.
