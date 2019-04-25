#include "MIDIUSB.h"
//#include "PitchToNote.h"
#define NUM_BUTTONS  15

//Button Definitions
const uint8_t BUTTON1 = 0;
const uint8_t BUTTON2 = 1;
const uint8_t BUTTON3 = 2;
const uint8_t BUTTON4 = 3;
const uint8_t BUTTON5 = 4;
const uint8_t BUTTON6 = 5;
const uint8_t BUTTON7 = 6;
const uint8_t BUTTON8 = 7;
const uint8_t BUTTON9 = 8;
const uint8_t BUTTON10 = 9;
const uint8_t BUTTON11 = 10;
const uint8_t BUTTON12 = 11;
const uint8_t BUTTON13 = 12;
const uint8_t BUTTON14 = 13;
const uint8_t BUTTON15 = A0;

const uint8_t buttons[NUM_BUTTONS] = {BUTTON1, BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8, BUTTON9, BUTTON10, BUTTON11, BUTTON12, BUTTON13, BUTTON14, BUTTON15};
boolean changeStates[NUM_BUTTONS] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
boolean currentStates[NUM_BUTTONS] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};


//Define the pitches, so we don’t have to keep looking
// up the hex / midi chart
//NOTES
//MIDI number 48 = middle C (C4)
//MIDI number 69 = A 440 (A4)



void setup()
{
 //Initialize pins - ONLY INITIALIZE PINS YOU ARE USING!!!
  for (int i = 0; i < NUM_BUTTONS; i++)
    pinMode(buttons[i], INPUT);
//      pinMode(BUTTON2, INPUT);
//      pinMode(BUTTON3, INPUT);
}


void loop()
{ 
  //Read all of the buttons into state array
  for (int i = 0; i < NUM_BUTTONS; i++){
    if(digitalRead(buttons[i]) == HIGH) {currentStates[i] = true;}
      else {currentStates[i] = false;}
  }


  //MAIN ACTIVITY LOOP
  for (int i = 0; i < NUM_BUTTONS; i++){
    //If the button is pressed 
    if(currentStates[i] == true) {  
      //If this is the first reading after pressing 
      if(currentStates[i] != changeStates[i]){ 
      //send command to start corresponding note 
             noteOn(0, i+48, 64);//channel 0, middle C, 64 velocity
              MidiUSB.flush();
        } 
    }
    //If the button is not pressed 
    else{ 
        //if this is the first reading after releasing
        if(currentStates[i] != changeStates[i]){
            //send the command to stop corresponding note 
            noteOff(0, i+48, 64);
             MidiUSB.flush();
        } 
    } 
  }

  //Keep a record of the previous state, so we can monitor
  //button state changes
  for (int i = 0; i < NUM_BUTTONS; i++){
    changeStates[i] = currentStates[i];
  }


}

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).
void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
