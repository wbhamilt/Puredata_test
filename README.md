# digitalfretboard
This is the codebase for a project intended to build a synthesizer with a button layout that mimicked that of a guitar fretboard. The project was made up of a Arduino midi controller that was connected to a laptop running Pure Data. The midi controller has a 3 x 5 button grid where notes are laid out as if the lowest note is the 7th fret on the low E string (giving the player a comfortable position for C major). The three buttons at the bottom of the device are for shifting all the pitches an ocatave up, an octave down, and for sending a MIDI control signal. 

The physical device can be seen here - https://imgur.com/a/J5b2XA1

# PD files/Poly Synth
The project is a working midi controller which can be used with any software that supports midi. For demonstration purposes, we used several Pure Data patches to make the device sound like a synthesizer.

Pure Data - https://puredata.info/ 

# Arduino Nano Sketch
This is a file that existed for a version of the midi controller that used an Arduino Nano. The Arduino Nano does NOT have an ATmega32U4, so an external female midi end must be connected to the board. The file that is left here is from a version that only supported 5 buttons, and the code was unfinished and unedited. It is based on this project, which is a useful reference to anyone trying to build an arduino nano midi controller - https://simonmackinnon.tumblr.com/post/66270961212/arduino-midi-controller-with-illuminated-arcade

# Arduino Leonardo Sketch
The final version of this project was build on an Arduino Leonardo, which allowed it to be recognized as a USB device over midi using the MIDIUSB library. During the build process, we faced some confusion as to which button was plugged into which port on the arduino, and the array called "notes" exists to correct problems associated with that confusion. This file specifies a 5 octave range. This is the code that was used in the final product.
