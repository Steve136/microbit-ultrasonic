#include "MicroBit.h"
MicroBit uBit;

int delayMS = 5000;

long msToCm(long ms) {
    return (ms / 59);
}

void onPulse(MicroBitEvent evt) { 
    long duration = evt.timestamp;
    uBit.serial.printf("\nDistance: %ldcm.", msToCm(duration));
 } 

int main() {
   uBit.init();
   uBit.serial.send("\nStarting up...");

   uBit.io.P0.eventOn(MICROBIT_PIN_EVENT_ON_PULSE);
   uBit.messageBus.listen(MICROBIT_ID_IO_P0, MICROBIT_PIN_EVT_PULSE_HI, onPulse); 

    while(1) {
        uBit.serial.printf("\nSending Pulse..");
        uBit.io.P1.setDigitalValue(0);
        uBit.sleep(0.2);
        uBit.io.P1.setDigitalValue(1);
        uBit.sleep(0.5);
        uBit.io.P1.setDigitalValue(0);
        
        uBit.sleep(delayMS);
    }
}