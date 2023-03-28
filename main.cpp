/**
 * @file    main.cpp
 * @brief   Program that switch an alarm LED on if there is gas detected or switch it off otherwise
 * @author  Axel Metzinger
 * @date    28/03/2023
 */

#include "mbed.h"
#include "arm_book_lib.h"
#include <cstdio>
#include <cstdlib>

/**
 * Main function of the program
 * @return EXIT_SUCCESS if there was no error anything else otherwise
 */
int main() {
    // Creation and initialization of the differents objects
    DigitalIn gasDetector(D2);  // DigitalIn is the class, gasDetector the name of the object of this class

    DigitalOut alarmLed(LED1);  // DigitalOut is the class, alarmLed the name of the object of this class

    gasDetector.mode(PullDown); // gasDetector is an object, .mode() is a methode used on gasDetector

    alarmLed = OFF;             // alarmLed the name of the object and of is an alias to an int/bool


    while (true) {
        if ( gasDetector == ON ) {                                      // gasDetector is an object of the class DigitalIn
            alarmLed = ON;                                              // alarmLed is an object of the class DigitalOut
            printf("There is some gas, the alarm is on\n");             // printf is a internal standard method
        } else {
            alarmLed = OFF;                                             // alarmLed is an object of the class DigitalOut
            printf("There is currently no gas, the alarm is off\n");    // printf is a internal standard method
        }
    }

    return EXIT_SUCCESS;    // Supposedly unreachable due to the infinite loop
}