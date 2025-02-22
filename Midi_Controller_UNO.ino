#include <MIDI.h> // FortySevenEffects MIDI Library.
#define MUX_INPUT_PIN 0  // Analog input used for the multiplexer

MIDI_CREATE_DEFAULT_INSTANCE();

// Arrays for button pins and their respective MIDI note numbers
const byte buttonPins[8]   = {2, 4, 6, 12, 3, 5, 7, 13};
const byte noteNumbers[8]  = {60, 62, 64, 65, 67, 69, 71, 72};

// Old and new states for each button
bool buttonOld[8] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
bool buttonNew[8];

// Arrays for potentiometers
int potCC[16]         = {0, 1, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 67, 68, 69, 70};
int potOldValue[16]   = {0};
int potNewValue[16]   = {0};

void setup() {
  // Set multiplexer address pins as outputs
  pinMode(8,  OUTPUT);
  pinMode(9,  OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  // Set all button pins as INPUT_PULLUP
  for (byte i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Start the MIDI library
  MIDI.begin();
}

// Reads the 16-channel multiplexer and sends Control Change messages when values change
void readMultiplexer() {
  for (int i = 0; i < 16; i++) {
    // Select the current multiplexer channel using address pins
    digitalWrite(8,  (i & B0001) ? HIGH : LOW);
    digitalWrite(9,  (i & B0010) ? HIGH : LOW);
    digitalWrite(10, (i & B0100) ? HIGH : LOW);
    digitalWrite(11, (i & B1000) ? HIGH : LOW);

    // Read the analog value from the multiplexer output
    int rawValue = analogRead(MUX_INPUT_PIN);

    // Check if the value has changed significantly (threshold = 10)
    if (abs(rawValue - potOldValue[i]) >= 10) {
      // Update the old value
      potOldValue[i] = rawValue;

      // Map from [0..1023] to [0..127] and constrain to [0..127]
      int mappedValue = map(rawValue, 0, 1023, 0, 127);
      mappedValue = constrain(mappedValue, 0, 127);

      // Send MIDI Control Change
      MIDI.sendControlChange(potCC[i], mappedValue, 1);
    }
  }
}

// Reads all button states and sends Note On/Off messages upon change
void readButtons() {
  for (byte i = 0; i < 8; i++) {
    // Read the current state of the button
    buttonNew[i] = digitalRead(buttonPins[i]);

    // Only act if there's a change in state
    if (buttonNew[i] != buttonOld[i]) {
      // Ternary operator to send NoteOn if button is LOW, otherwise NoteOff
      (buttonNew[i] == LOW)
        ? MIDI.sendNoteOn(noteNumbers[i], 127, 1)
        : MIDI.sendNoteOff(noteNumbers[i], 0, 1);

      // Update the old state
      buttonOld[i] = buttonNew[i];
    }
  }
}

void loop() {
  // Read and process all 16 multiplexer channels (potentiometers)
  readMultiplexer();

  // Read and process the 8 buttons
  readButtons();
}
