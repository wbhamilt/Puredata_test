//button is on pin 3
#define BUTTON1 3
#define BUTTON2 4
#define BUTTON3 5
#define BUTTON4 6//only 3 buttons
#define BUTTON5 7
#define BUTTON6 9

//Use the AO as a “shift” key to double 
// the number of usable pitches/button
#define SHIFT_KEY A0

//For now, all midi commands are on pin 2
#define CMD_1 (0x90)

//With medium velocity
#define VEL_1 0x45
#define VEL_2 0x45
#define VEL_3 0x45
#define VEL_4 0x45
#define VEL_5 0x45
#define VEL_6 0x45

//Define the pitches, so we don’t have to keep looking
// up the hex / midi chart
//#define PITCH_1 0x3F //D#
//#define PITCH_2 0x40 //E
//#define PITCH_3 0x41 //F
//#define PITCH_4 0x3E //D
//#define PITCH_5 0x3D //C#
//#define PITCH_6 0x3C //Middle C (C4)
//#define PITCH_7 0x45 //A
//#define PITCH_8 0x46 //A#
//#define PITCH_9 0x47 //B 
//#define PITCH_10 0x44 //G#
//#define PITCH_11 0x43 //G
//#define PITCH_12 0x42 //F#


#define PITCH_4 0x3F //D#
#define PITCH_5 0x40 //E
#define PITCH_6 0x41 //F
#define PITCH_3 0x3E //D
#define PITCH_2 0x3D //C#
#define PITCH_1 0x3C //Middle C (C4)
#define PITCH_7 0x45 //A
#define PITCH_8 0x46 //A#
#define PITCH_9 0x47 //B 
#define PITCH_10 0x44 //G#
#define PITCH_11 0x43 //G
#define PITCH_12 0x42 //F#

boolean changeState1 = false; 
boolean changeState2 = false; 
boolean changeState3 = false; 
boolean changeState4 = false; 
boolean changeState5 = false; 
boolean changeState6 = false; 


boolean currentState1 = false;
boolean currentState2 = false; 
boolean currentState3 = false; 
boolean currentState4 = false; 
boolean currentState5 = false; 
boolean currentState6 = false; 


void setup()
{
    //Set up the digi IOs as inputs for the buttons
    pinMode(BUTTON1, INPUT); 
 

    // Set MIDI baud rate:
    Serial.begin(31250);

}

//void loop()
//{ 
//    //Read all of the buttons, then store into state bool vars
//    if(digitalRead(BUTTON1) == HIGH) {currentState1 = true;}
//    else {currentState1 = false;} 
//   
//
//    //Flush the serial buffer
//   Serial.flush();
//
//    //If the button is pressed 
//    if(currentState1 == true) { 
//     
//      //If this is the first reading after pressing 
//      if(currentState1 != changeState1){ 
//      //send command to start corresponding note 
//           writeNote(CMD_1, PITCH_1, VEL_1); 
//        } 
//    }
//    //If the button is not pressed 
//    else{ 
//        //if this is the first reading after releasing
//        if(currentState1 != changeState1){
//            //send the command to stop corresponding note 
//            stopNote(CMD_1, PITCH_1); 
//        } 
//    } 
//
//    
//
////Keep a record of the previous state, so we can monitor
////button state changes
//changeState1 = currentState1;
//
//}

//NEW LOOP
void loop()
{ 
    //Read all of the buttons, then store into state bool vars
    if(digitalRead(BUTTON1) == HIGH) {currentState1 = true;}
      else {currentState1 = false;} 
    if(digitalRead(BUTTON2) == HIGH) {currentState2 = true;}
      else {currentState2 = false;} 
    if(digitalRead(BUTTON3) == HIGH) {currentState3 = true;}
      else {currentState3 = false;} 
    if(digitalRead(BUTTON4) == HIGH) {currentState4 = true;}
      else {currentState4 = false;} 
    if(digitalRead(BUTTON5) == HIGH) {currentState5 = true;}
      else {currentState5 = false;} 
    if(digitalRead(BUTTON6) == HIGH) {currentState6 = true;}
      else {currentState6 = false;}

    //Flush the serial buffer
   Serial.flush();

    //BUTTON 1
    //If the button is pressed 
    if(currentState1 == true) {  
      //If this is the first reading after pressing 
      if(currentState1 != changeState1){ 
      //send command to start corresponding note 
             writeNote(CMD_1, PITCH_1, VEL_1); 
        } 
    }
    //If the button is not pressed 
    else{ 
        //if this is the first reading after releasing
        if(currentState1 != changeState1){
            //send the command to stop corresponding note 
            stopNote(CMD_1, PITCH_1); 
        } 
    } 

    //BUTTON 2
    //Repeats for each button/LED/pitch
    if(currentState2 == true) { 
        if(currentState2 != changeState2) { 
            writeNote(CMD_1, PITCH_2, VEL_2);
        } 
    }
    else{
        if(currentState2 != changeState2){ 
            stopNote(CMD_1, PITCH_2); 
        } 
    } 
    
     //BUTTON 3
    if(currentState3 == true) { 
        if(currentState3 != changeState3) { 
            writeNote(CMD_1, PITCH_3, VEL_3);
        } 
    }
    else{
        if(currentState3 != changeState3){ 
        stopNote(CMD_1, PITCH_3); 
        } 
    } 
     
     
    //BUTTON 4
    if(currentState4 == true) { 
        if(currentState4 != changeState4) { 
          writeNote(CMD_1, PITCH_4, VEL_4);
        } 
    }
    else{
        if(currentState4 != changeState4){ 
          stopNote(CMD_1, PITCH_4); 
        } 
    } 


    //BUTTON 5
    if(currentState5 == true) { 
      if(currentState5 != changeState5) {     
        writeNote(CMD_1, PITCH_5, VEL_5);
      } 
    }
    else{
      if(currentState5 != changeState5){ 
        stopNote(CMD_1, PITCH_5); 
      } 
    } 
    
    //BUTTON 6
    if(currentState6 == true) { 
      if(currentState6 != changeState6) { 
        writeNote(CMD_1, PITCH_6, VEL_6);
        } 
      }
      else{
        if(currentState6 != changeState6){ 
        stopNote(CMD_1, PITCH_6); 
      } 
    } 

//Keep a record of the previous state, so we can monitor
//button state changes
changeState1 = currentState1;
changeState2 = currentState2;
changeState3 = currentState3;
changeState4 = currentState4;
changeState5 = currentState5;
changeState6 = currentState6;


}



void writeNote(byte command, byte pitch, byte velocity)
{
//Check if our “Shift” key has been pressed
if(digitalRead(SHIFT_KEY) == HIGH)
{
//Play the pitch in the higher section of the octive
Serial.write(command);
Serial.write(pitch+6);
        Serial.write(velocity); 
    }
    else
    {
//otherwise play the pitch from the lower section
        // of the octave
        Serial.write(command);
        Serial.write(pitch);
        Serial.write(velocity); 
    }

}

void stopNote(byte command, byte pitch)
{
//No way to know (without keeping track of which pitch was 
// played for each button) which pitch to turn off,
//So switch them both off
Serial.write(command);
Serial.write(pitch);
Serial.write(0x00); 

Serial.write(command);
Serial.write(pitch+6);
Serial.write(0x00); 
}
