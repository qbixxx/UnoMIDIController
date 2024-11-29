# Arduino-Uno-MIDI-Controller
MIDI controller based on the Arduino Uno development board and the CD4067 16 channel analog multiplexer. The device can be configured to be plug and play by creating a MIDI Device script for some DAWs such as Ableton for instant recognition.

What makes this project special is that it uses multiplexing for the analog input signal reading. In this codebase, there are 16 potentiometers that are being scanned by only one analog input pin of the six available. This means that in theory you could connect a 4067 multiplexer to all the analog input pins, allowing you to read a total of 96 potentiometers simultaneously.

Dependencies:
-  [FortySevenEffects MIDI Library](https://github.com/FortySevenEffects/arduino_midi_library)
-  To make the UNO a MIDI class compliant device, use [mocolufa](https://github.com/kuwatay/mocolufa) (Only for 16u2 UNO boards)

Potentiometer values: 500 Kohm (Linear)

SCHEMATIC.- (PDF): [schematic.pdf](https://github.com/SSMTBPSSCNTPGTS/Arduino-Uno-MIDI-Controller/files/7755505/output.pdf)

![output_page-0001](https://user-images.githubusercontent.com/89623002/146935323-eefda356-657d-44a9-914d-c8104fda27a6.jpg)


https://user-images.githubusercontent.com/89623002/147885847-e971e248-e7a7-4c77-9603-ff16ea4fe2ea.mp4



https://user-images.githubusercontent.com/89623002/147886057-9e963b5f-dcb2-49f2-9e51-6054598d2537.mp4

