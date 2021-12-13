// Author: Valentin Cedeño Compagnucci
// Email: valentinccomp@gmail.com
// Last revision: December 11, 2021.

#include <MIDI.h> // FortySevenEffects MIDI Library.
#define input 0

MIDI_CREATE_DEFAULT_INSTANCE();

//************************************ Multiplexer's 4 Bit Address Bus ********************************************
int pin_0_mux = 8;
int pin_1_mux = 9;
int pin_2_mux = 10;
int pin_3_mux = 11;

//************************************************* Buttons ********************************************************
int b_1 = 2;
int b_2 = 4;
int b_3 = 6;
int b_4 = 12;
int b_5 = 3;
int b_6 = 5;
int b_7 = 7;
int b_8 = 13;

bool b_1_old = HIGH;
bool b_2_old = HIGH;
bool b_3_old = HIGH;
bool b_4_old = HIGH;
bool b_5_old = HIGH;
bool b_6_old = HIGH;
bool b_7_old = HIGH;
bool b_8_old = HIGH;

//***************************************** Potentiometers *********************************************************
int pot_cc[] = {0,1,56,57,58,59,60,61,62,63,64,65,67,68,69,70};// MIDI CC values for the 16 potentiometers.

int pot_old_value[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int pot_new_value[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup() {

//******************************************* Pin Modes *************************************************************
pinMode(input,INPUT); // Analog input.

pinMode(pin_0_mux, OUTPUT);// Multiplexer's address: Bit 0
pinMode(pin_1_mux, OUTPUT);// Multiplexer's address: Bit 1
pinMode(pin_2_mux, OUTPUT);// Multiplexer's address: Bit 2
pinMode(pin_3_mux, OUTPUT);// Multiplexer's address: Bit 3

pinMode(b_1, INPUT_PULLUP);// Buttons 
pinMode(b_2, INPUT_PULLUP);
pinMode(b_3, INPUT_PULLUP);
pinMode(b_4, INPUT_PULLUP);
pinMode(b_5, INPUT_PULLUP);
pinMode(b_6, INPUT_PULLUP);
pinMode(b_7, INPUT_PULLUP);
pinMode(b_8, INPUT_PULLUP);

MIDI.begin(); // *

}

void multiplexer_1() {

	for (int i = 0; i < 16; i++){
  
		digitalWrite(pin_0_mux, HIGH && (i & B00000001));
		digitalWrite(pin_1_mux, HIGH && (i & B00000010));
		digitalWrite(pin_2_mux, HIGH && (i & B00000100));
		digitalWrite(pin_3_mux, HIGH && (i & B00001000));
	
		pot_new_value[i] = analogRead(input);
	}
}

void loop() {

multiplexer_1();

for(int i=0; i<16; i++){	
	
	if(pot_new_value[i] - pot_old_value[i] >= 10 || pot_old_value[i] - pot_new_value[i] >= 10){
	
		pot_old_value[i] = pot_new_value[i];
		pot_new_value[i] = (map(pot_new_value[i], 0, 1023, 0, 127));
		pot_new_value[i] = (constrain(pot_new_value[i], 0, 127));
	
		MIDI.sendControlChange(pot_cc[i], pot_new_value[i], 1);
	}
}

 
bool b_1_new = digitalRead(b_1);
bool b_2_new = digitalRead(b_2);
bool b_3_new = digitalRead(b_3);
bool b_4_new = digitalRead(b_4);
bool b_5_new = digitalRead(b_5);
bool b_6_new = digitalRead(b_6);
bool b_7_new = digitalRead(b_7);
bool b_8_new = digitalRead(b_8);
 
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
