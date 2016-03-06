//
//  VGA_I2C.hpp
//  Main_ATmega_new
//
//  Created by David Liberda on 1/20/16.
//  Copyright © 2016 David Liberda. All rights reserved.
//

#ifndef VGA_I2C_hpp
#define VGA_I2C_hpp

#include <stdio.h>

/*

void initI2C(void);

void sendCharWithPos(int, char);
void sendChar(char);

void setPos(int);

void clearScreen(void);
 
*/

void initI2C(void);

void sendChar(char);
void setPos(int);

void sendCharWithPos(int, char);

#endif
