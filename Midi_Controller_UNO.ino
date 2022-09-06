// Author: Valentin Cedeño
// Email: valentinccomp@gmail.com
// Last revision: Sept. 6, 2022.

#include <MIDI.h> // FortySevenEffects MIDI Library.
#define input 0

MIDI_CREATE_DEFAULT_INSTANCE();

bool b_1_old = HIGH;
bool b_2_old = HIGH;
bool b_3_old = HIGH;
bool b_4_old = HIGH;
bool b_5_old = HIGH;
bool b_6_old = HIGH;
bool b_7_old = HIGH;
bool b_8_old = HIGH;

bool b_1_new;
bool b_2_new;
bool b_3_new;
bool b_4_new;
bool b_5_new;
bool b_6_new;
bool b_7_new;
bool b_8_new;

// Potentiometers
int pot_cc[] = {0,1,56,57,58,59,60,61,62,63,64,65,67,68,69,70};// MIDI CC values for the 16 potentiometers.

int pot_old_value[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int pot_new_value[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup() {

// Pin Modes

pinMode(8, OUTPUT);// Multiplexer's address: Bit 0
pinMode(9, OUTPUT);// Multiplexer's address: Bit 1
pinMode(10, OUTPUT);// Multiplexer's address: Bit 2
pinMode(11, OUTPUT);// Multiplexer's address: Bit 3

pinMode(2, INPUT_PULLUP);// Buttons 
pinMode(4, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(12, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(13, INPUT_PULLUP);

MIDI.begin(); // *

}

void multiplexer_1() {

	for (int i = 0; i < 16; i++){
  
		digitalWrite(8, HIGH && (i & B00000001));
		digitalWrite(9, HIGH && (i & B00000010));
		digitalWrite(10, HIGH && (i & B00000100));
		digitalWrite(11, HIGH && (i & B00001000));
	
		pot_new_value[i] = analogRead(input);
		
		
   
		if(pot_new_value[i] - pot_old_value[i] >= 10 || pot_old_value[i] - pot_new_value[i] >= 10){
  
			pot_old_value[i] = pot_new_value[i];
			pot_new_value[i] = (map(pot_new_value[i], 0, 1023, 0, 127));
			pot_new_value[i] = (constrain(pot_new_value[i], 0, 127));
  
			MIDI.sendControlChange(pot_cc[i], pot_new_value[i], 1);
		}
   
	}
}

void loop() {

multiplexer_1();
 
b_1_new = digitalRead(b_1);
b_2_new = digitalRead(b_2);
b_3_new = digitalRead(b_3);
b_4_new = digitalRead(b_4);
b_5_new = digitalRead(b_5);
b_6_new = digitalRead(b_6);
b_7_new = digitalRead(b_7);
b_8_new = digitalRead(b_8);
 
if(b_1_new != b_1_old){
	
	if(b_1_old == LOW){
		MIDI.sendNoteOn(60, 127, 1); // Note C5 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(60, 0, 1); // Note C5 Off - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_1_old = b_1_new;
}

if(b_2_new != b_2_old){
	
	if(b_2_new == LOW){
		MIDI.sendNoteOn(62, 127, 1);// Note D5 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(62, 0, 1);// Note D5 Off - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_2_old = b_2_new;
}

if(b_3_new != b_3_old){
	
	if(b_3_new == LOW){
		MIDI.sendNoteOn(64, 127, 1);// Note E5 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(64, 0, 1);// Note E5 Off - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_3_old = b_3_new;
}

if(b_4_new != b_4_old){
	
	if(b_4_new == LOW){
		MIDI.sendNoteOn(65, 127, 1);// Note F5 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(65, 0, 1);// Note F5 Off - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_4_old = b_4_new;
}

if(b_5_new != b_5_old){
	if(b_5_new == LOW){
		
		MIDI.sendNoteOn(67, 127, 1);// Note G5 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(67, 0, 1);// Note G5 Off - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_5_old = b_5_new;
}

if(b_6_new != b_6_old){
	if(b_6_new == LOW){
			
		MIDI.sendNoteOn(69, 127, 1);// Note A5 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(69, 0, 1);// Note A5 Off - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_6_old = b_6_new;
}

if(b_7_new != b_7_old){
	if(b_7_new == LOW){
		
		MIDI.sendNoteOn(71, 127, 1);// Note B5 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(71, 0, 1);// Note B5 Off - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_7_old = b_7_new;
}

if(b_8_new != b_8_old){
	if(b_8_new == LOW){
		
		MIDI.sendNoteOn(72, 127, 1);// Note C6 On - MIDI Value: 127 - MIDI Channel: 1
	}
	else{
		MIDI.sendNoteOff(72, 0, 1);// Note C6 On - MIDI Value: 0 - MIDI Channel: 1
	}
	
	b_8_old = b_8_new;
}

}
