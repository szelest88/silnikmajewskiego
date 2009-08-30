#include <windows.h>              // musi byæ, nie mo¿na u¿yæ <stdio.h> zamiast tego
#define GLUT_DISABLE_ATEXIT_HACK  // musi byæ u¿yte przed includowaniem "glut.h"
#include "zmienne.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
using namespace std;

void function1(int a){
	switch (a){
	case 1: exit(0);break;
	}

}

void createMenus(){
	int submenu1 = glutCreateMenu(function1);
	glutAddMenuEntry("Zupa z ¿ó³wia", 1);
	glutAddMenuEntry("Zupa z trupa", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}
