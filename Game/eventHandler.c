//
//  eventHandler.c
//  
//
//  Created by Julia Heinz on 12.11.14.
//
//

#include <stdio.h> 

#define INPUTTYPES 4
#define INPUTADDRESS_1   0  //joystick
#define INPUTADDRESS_2   0  //shooting button
#define INPUTADDRESS_3   0  // pause
#define INPUTADDRESS_4   0  //Gamespeed

int inputbuffer[INPUTTYPES];
unsigned int* inputaddresses[]={INPUTADDRESS_1,INPUTADDRESS_2,INPUTADDRESS_3,INPUTADDRESS_4};

void filleventbuffer()
{
    int i;
    for (i=0; i<INPUTTYPES; i++){
        inputbuffer[i] = *inputaddresses[i];
        *inputaddresses[i] = 0;
    }
}

int checkEventBuffer()
{
    return 0;
}

int movement()
{
    return 0;
}

char isShooting()
{
    return inputbuffer[1];
}

int is_paused()
{
    return inputbuffer[2];
}

int gamespeed()
{
    return inputbuffer[3];
}




