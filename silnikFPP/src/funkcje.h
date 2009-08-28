/*
 * funkcje.h
 *
 *  Created on: 2009-08-28
 *      Author: 1234
 */

#ifndef FUNKCJE_H_
#define FUNKCJE_H_
#include "zmienne.h"
void Reshape(int, int);
void pressKey(int key, int x, int y);
void releaseKey(int key, int x, int y);
void processNormalKeys(unsigned char key, int x, int y);
void upNormalKeys(unsigned char key, int x, int y);
void mouse(int a, int b);

//void pressKey(int, int , int);
#endif /* FUNKCJE_H_ */
