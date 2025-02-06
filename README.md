# Arduino UNO MIDI Controller
MIDI controller based on the Arduino Uno development board and the CD4067 16 channel analog multiplexer. The device can be configured to be plug and play by creating a MIDI Device script for some DAWs such as Ableton for instant recognition.

What makes this project special is that it uses [time-division multiplexing](https://en.wikipedia.org/wiki/Multiplexing#Time-division_multiplexing) for the analog input signal reading. In this codebase, there are 16 potentiometers that are being scanned by only one analog input pin of the six available. Arduino boards, including the Arduino Uno, do not support true concurrency. This means that they can only read one analog input at a time. If you wanted to connect 16 potentiometers directly, you would need 16 separate analog pins — but the Arduino Uno only has 6 analog input pins.

To overcome this limitation, this project uses a CD4067 multiplexer. Instead of dedicating one pin per potentiometer, the multiplexer allows all 16 potentiometers to be read using a single analog input pin. This is achieved through time-division multiplexing, where the Arduino rapidly switches between the 16 inputs, reading them one-by-one. Since the switching is fast, it appears as if all potentiometers are being read at once.

This approach allows for efficient use of limited hardware resources while enabling support for a large number of input devices. In fact, by connecting a multiplexer to each of the 6 analog input pins of the Arduino, you could theoretically read up to 96 potentiometers simultaneously.

## Dependencies:
-  [FortySevenEffects MIDI Library](https://github.com/FortySevenEffects/arduino_midi_library)
-  To make the UNO a MIDI class compliant device, use [mocolufa](https://github.com/kuwatay/mocolufa) (Only for 16u2 UNO boards)

Potentiometer values: 500 Kohm (Linear)

## SCHEMATIC.- (PDF): [schematic.pdf](https://github.com/SSMTBPSSCNTPGTS/Arduino-Uno-MIDI-Controller/files/7755505/output.pdf)
![output_page-0001](https://user-images.githubusercontent.com/89623002/146935323-eefda356-657d-44a9-914d-c8104fda27a6.jpg)

## PCB.- (PDF scan): [PCB.pdf](https://github.com/user-attachments/files/18695484/PCB.pdf)


https://user-images.githubusercontent.com/89623002/147885847-e971e248-e7a7-4c77-9603-ff16ea4fe2ea.mp4



https://user-images.githubusercontent.com/89623002/147886057-9e963b5f-dcb2-49f2-9e51-6054598d2537.mp4

