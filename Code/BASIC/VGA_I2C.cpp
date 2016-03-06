//
//  VGA_I2C.cpp
//  Main_ATmega_new
//
//  Created by David Liberda on 1/20/16.
//  Copyright © 2016 David Liberda. All rights reserved.
//

#include "VGA_I2C.hpp"

#include "host.h"

#include "Arduino.h"
#include "Wire.h"

/*

void initI2C(void)
{
    Wire.begin();
}

void sendCharWithPos(int pos, char letter)
{
    char posChar[10];
    sprintf(posChar, "%ld", pos);
    Wire.beginTransmission(8);
    Wire.write('p');
    Wire.write('\32');
    Wire.write(posChar);
    Wire.write('\32');
    Wire.write(letter);
    Wire.write('\3');
    Wire.endTransmission();
}

void sendChar(char letter)
{
    Wire.beginTransmission(8);
    Wire.write('o');
    Wire.write('\32');
    Wire.write(letter);
    Wire.write('\3');
    Wire.endTransmission();
}

void setPos(int pos)
{
    char posChar[10];
    sprintf(posChar, "%ld", pos);
    Wire.beginTransmission(8);
    Wire.write('s');
    Wire.write('\32');
    Wire.write(posChar);
    Wire.write('\3');
    Wire.endTransmission();
}

void clearScreen(void)
{
    Wire.beginTransmission(8);
    Wire.write('c');
    Wire.write('\3');
    Wire.endTransmission();
}

*/

// START - I2C

char letter = 65;

void sendCharI2C() {
    Wire.write(letter);
    digitalWrite(13, LOW);
}

void sendMessage(char message) {
    letter = message;
    digitalWrite(13, HIGH);
    delay(1);
}

// *** //

void sendChar(char a) {
    sendMessage(a);
}

void setPos(int pos) {
    sendMessage('\2');
    char a = '0' + (pos/1000)%10;
        sendMessage( a );
    char b = '0' + (pos/100)%10;
        sendMessage( b );
    char c = '0' + (pos/10)%10;
        sendMessage( c );
    char d = '0' + (pos/1)%10;
        sendMessage( d );
    sendMessage('\1');
}

void sendCharWithPos(int pos, char a)
{
    setPos(pos);
    sendChar(a);
}

// *** //

void initI2C(void)
{
    // set up I2C data pin
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    
    // set up I2C
    Wire.begin(8);
    Wire.onRequest(sendCharI2C);
}

// END - I2C