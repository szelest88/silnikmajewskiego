#include <windows.h>              // musi by�, nie mo�na u�y� <stdio.h> zamiast tego
#define GLUT_DISABLE_ATEXIT_HACK  // musi by� u�yte przed includowaniem "glut.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//#include "zmienne.h"
#include "funkcje.h"
#include "menus.h"

//do commita
using namespace std;
//dupa

float kat = 0.0;
float katpion = 0.0; // added
float deltaKat = 0.0;
float deltaKatpion=0.0; //added
float ratio;
float x = 0.0f, y = 1.75f, z = 5.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaRuch = 0;
float deltaSkret;
float ang2;

//do commita
using namespace std;

void rysujDomek() {
	glColor3f(1, 0, 0);
	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();

}

void zorientujMnie(float ang, float angpion) { //scd arg added
	lx = sin(ang);
	lz = -cos(ang);
	ly = sin(angpion);//added
	glLoadIdentity();

	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0, 0.0f);

}

void PlaskiRuch(int i) {
	x += i * lx * 0.05;
	z += i * lz * 0.05;
	glLoadIdentity();

	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0, 0.0f);

}

void Draw() {

	if (deltaRuch)
		PlaskiRuch(deltaRuch);

	if (deltaKat || deltaKatpion) {
		kat += deltaKat;

		zorientujMnie(kat + ang2, katpion);

	}


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST); //w��czamy testowanie g��boko�ci

	glColor3f(0.9, 0.9, 0.9); // ustalamy kolor na jasno-szary
	// ziuuu, teraz rysujemy pod�o�e
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i * 10, 1, j * 10);
			rysujDomek();
			glPopMatrix();
		}
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1, 0, 1);

	glVertex3f(x + lx, y + ly-0.04, z + lz);
	glVertex3f(x + lx, y + ly+0.04, z + lz);

		glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

static void idle() {
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);

	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("Press Q to exit");

	glutReshapeFunc(Reshape); //argumentem glutReshapefunc() jest funkcja, wykonywana przez bibliotek� GLUT w momencie
	//zmiany rozmiaru okna, kt�ra to z kolei otrzymuje w parametrach now� szeroko�� i wysoko��
	//okna (dwa razy int).
	glClearColor(0, 0, 1, 0);

	glutDisplayFunc(Draw);
	glutIgnoreKeyRepeat(0);
	glutKeyboardFunc(processNormalKeys);
	glutKeyboardUpFunc(upNormalKeys);
	glutSetCursor(GLUT_CURSOR_NONE); //doda�em, ukrywa kursor myszy
	glutPassiveMotionFunc(mouse);

	createMenus();

	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutIdleFunc(idle);
	glutMainLoop();

	return 0;
}
