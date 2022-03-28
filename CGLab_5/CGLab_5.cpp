#include <iostream>
#include <gl\glut.h>
#include <atlbase.h>
#include <atlconv.h>
#include <string>
#include <cmath>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <C:\\Users\\Рабочий стол\\glaux.h>
#pragma comment(lib, "C:\\Users\\Рабочий стол\\GLAUX.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")
GLfloat ratio = 4.0/3.0;
GLfloat angle = 0.0;
void init()
{ 	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, ratio, 0.01f, 110.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 2.0, -2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	AUX_RGBImageRec *image = auxDIBImageLoad("image.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}
void reshape(int width, int height)
{	 if (ratio > width/height) glViewport(0, 0, width, width/ratio);
	 else glViewport(0, 0, height*ratio, height); 
} 
void display()
{	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glPushMatrix();
		glRotatef(angle, 0.0, 1.0, 0.0);
		glBegin(GL_TRIANGLES);
			// грань 0
			glTexCoord2f(0, 0); glVertex3f(1, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(0, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(0, 0, 1);
			// грань 1
			glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(0, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(1, 0, 0);
			// грань 2
			glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(0, 0, 1);
			glTexCoord2f(0, 1); glVertex3f(0, 1, 0);
			// грань 3
			glTexCoord2f(0, 0); glVertex3f(1, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(0, 0, 1);
			glTexCoord2f(1, 0); glVertex3f(0, 0, 0);
		glEnd();
	 glPopMatrix();
	 glFlush();
	 glutSwapBuffers();
}
void idle()
{	 angle += 0.5f;
	 if (angle > 360.0) angle = 0.0;
	 glutPostRedisplay();
}
int main(int argc, char* argv[])
{	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	 glutInitWindowPosition(0, 0);
	 glutInitWindowSize(640, 480);
	 glutCreateWindow("Пример текстурирования");
	 glutDisplayFunc(display);
	 glutReshapeFunc(reshape);
	 glutIdleFunc(idle);
	 init();
	 glutMainLoop();
	 return 0;
}
