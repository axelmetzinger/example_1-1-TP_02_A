#include "mbed.h"
#include "arm_book_lib.h"
#include <cstdio>

int main()
{
    DigitalIn gasDetector(D2);  // DigitalIn is the class, gasDetector the name of the object of this class

    DigitalOut alarmLed(LED1);  // DigitalOut is the class, alarmLed the name of the object of this class

    gasDetector.mode(PullDown); // gasDetector is an object, .mode() is a methode used on gasDetector

    alarmLed = OFF;             // alarmLed the name of the object and of is an alias to an int/bool

while (true) {                                                          // while loop, true is a bool
        if ( gasDetector == ON ) {                                      // gasDetector is an object of the class DigitalIn
            alarmLed = ON;                                              // alarmLed is an object of the class DigitalOut
            printf("There is some gas, the alarm is on\n");             // printf is a internal standard method
        } else {
            alarmLed = OFF;                                             // alarmLed is an object of the class DigitalOut
            printf("There is currently no gas, the alarm is off\n");    // printf is a internal standard method
        }
    }
}