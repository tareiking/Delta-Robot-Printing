//
//  stepperControl.h
//  Delta Sim
//
//  Created by Zak Henry on 9/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef _STEPPER_CONTROL // if this class hasn't been defined, the program can define it
#define _STEPPER_CONTROL // by using this if statement you prevent the class to be called more 
// than once which would confuse the compiler

#include "ofMain.h"

#define NUM_BYTES 1

class StepperControl {
    
    vector<char>buffer;
    
    bool stepper0Ready, stepper1Ready, stepper2Ready;
    bool stepper0Connected, stepper1Connected, stepper2Connected;
    
public:
    
    StepperControl(); //constructor
    void setupDevices();
    
    ofSerial serial0, serial1, serial2;
    
    bool println(int stepper, string line);
    
    void setStepper(int stepper, float angle, float speed);
    
    void update();
    
    bool readUntil(int stepper, string& rResult, char cUntil);
    
    bool readBytes(int stepper, string& rResult, int bytesToRead);
    
    bool robotReadyForData();
    
    string message, messageBuffer;
    unsigned char bytesReturned[1];
    void read(ofSerial& serialPort, int portNum);
    
};


#endif 