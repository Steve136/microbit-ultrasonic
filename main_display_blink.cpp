#include "MicroBit.h"
MicroBit uBit;

DigitalInOut pingPin(MICROBIT_PIN_P1); //Set the Ping pin on the HC-SR04 to PIN 1 on the Microbit.
DigitalInOut echoPin(MICROBIT_PIN_P0); //Set the Echo pin on the HC-SR04 to PIN 0 on the Microbit.

MicroBitImage Level1("0,0,0,0,0\n0,0,0,0,0\n0,0,255,0,0\n0,0,0,0,0\n0,0,0,0,0\n"); //1 Dot.
MicroBitImage Level2("0,0,0,0,0\n0,255,255,255,0\n0,255,0,255,0\n0,255,255,255,0\n0,0,0,0,0\n");
MicroBitImage Level3("255,255,255,255,255\n255,0,0,0,255\n255,0,0,0,255\n255,0,0,0,255\n255,255,255,255,255\n");

long msToIn(long microseconds);
long msToCm(long microseconds);
long readSensor();

int main() {
   uBit.init();
   
    while(1) {
        //Perform a read of the sensor.
        long ms = readSensor();
        long inch = msToIn(ms);
        if (inch < 2) {
            uBit.display.print(Level1);
        } else if (inch > 1 && inch < 5) {
            uBit.display.print(Level2);
        } else {
            uBit.display.print(Level3);
        }
        
        //Print out the results, converting to Inches and CM
        uBit.serial.printf("Sensor Returned: Inches: %ld, CM: %ld\n", msToIn(ms), msToCm(ms));
        uBit.sleep(500);
    }
}

long msToIn(long microseconds) {
    
    return microseconds / 147;
}
 
long msToCm(long microseconds) {
    return microseconds / 59;
}

long readSensor() {
     Timer t;
     pingPin.output();
     pingPin = 0;
     uBit.sleep(0.2);
     pingPin = 1;
     uBit.sleep(0.5);
     pingPin = 0;
        
     echoPin.input();

     while (!echoPin); 
     t.start();
     while (echoPin); 
     long duration = t.read_us();
        
     t.stop();
     t.reset();
     return duration;
}