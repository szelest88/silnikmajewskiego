#include <windows.h>              // musi by�, nie mo�na u�y� <stdio.h> zamiast tego
#define GLUT_DISABLE_ATEXIT_HACK  // musi by� u�yte przed includowaniem "glut.h"
#include "zmienne.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
using namespace std;

#ifndef MENUS_H_
#define MENUS_H_

void function1(int a);

void createMenus();

#endif /* MENUS_H_ */
