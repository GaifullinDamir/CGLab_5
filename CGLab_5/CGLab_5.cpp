#include <iostream>
#include <gl\glut.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <D:/Learning/glaux/Glaux.h>
#pragma comment(lib, "D:/Learning/glaux/Glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")
//GLfloat ObjectAngle = 0;
//GLfloat LightAngle = 0;
//GLfloat myAmbient[] = { 0.10588, 0.058824, 0.113725, 1 };
//GLfloat myDiffuse[] = { 0.427451, 0.470588, 0.541176, 1 };
//GLfloat mySpecular[] = { 0.3333, 0.3333, 0.521569, 1 };
//GLfloat myShininess[] = { 9.84615 };
//bool FrontSide = true;
//GLuint list1 = 0, list2 = 0, list3 = 0;
//AUX_RGBImageRec* img1, * img2, * img3, * img4;
//
//
//void init(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60, 1, 1, 10);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void MyFigure() {
//	img1 = auxDIBImageLoadA("texture1.bmp");
//	img2 = auxDIBImageLoadA("texture2.bmp");
//	img3 = auxDIBImageLoadA("texture3.bmp");
//	img4 = auxDIBImageLoadA("texture1.bmp");
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	list1 = glGenLists(1);
//	glNewList(list1, GL_COMPILE);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img1->sizeX, img1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img1->data);
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_DEPTH_TEST);
//
//	glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient); //параметры материала
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img4->sizeX, img4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img4->data);
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(0, 0, 1);
//	glEnd();
//	//грань f1
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0.707, -0.707); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0.5, 0.5, 0.5);
//	glEnd();
//		
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img1->sizeX, img1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img1->data);
//	//грань f2
//	glBegin(GL_POLYGON);
//	glNormal3f(-0.707, 0.707, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); glVertex3f(0.5, 0.5, 0.5);
//	glEnd();
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img2->sizeX, img2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img2->data);
//	//// грань f3
//	glBegin(GL_POLYGON);
//	glNormal3f(0.707, 0.707, 0); glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(0.5, 0.5, 0.5);
//	glEnd();
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img3->sizeX, img3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img3->data);
//	//// грань f4
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0.707, 0.707); glVertex3f(1, 0, 1); glVertex3f(0, 0, 1); glVertex3f(0.5, 0.5, 0.5);
//	glEnd();
//
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
//	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
//	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
//	glEnd();
//	glEndList();
//}
//
//void mydisplay()
//{
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//	gluLookAt(0, 3, 3, 0, 0, 0, 0, 1, 0);
//	glPushMatrix();
//	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
//	glRotatef(LightAngle, 0, 1, 0);
//	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
//	glEnable(GL_LIGHTING); // Включение расчета освещенности
//	glEnable(GL_LIGHT0); // включаем этот конкретный источник
//	GLfloat myAmbient[] = { 0.8, 0.2, 0.4, 1.0 };
//	GLfloat myDiffuse[] = { 0.8, 0.8, 0.2, 1.0 };
//	GLfloat mySpecular[] = { 1.0, 0.8, 0.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, myAmbient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, myDiffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, mySpecular);
//	glPopMatrix();
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glPushMatrix();
//	glRotatef(LightAngle, 0, 1, 0);
//	glBegin(GL_LINES);
//	glColor3f(1, 1, 0); glVertex3f(myLightPosition[0], myLightPosition[1],
//		myLightPosition[2]);
//	glEnd();
//	glPopMatrix();
//	glRotatef(ObjectAngle, 0, 1, 0);
//	if (FrontSide)
//	{
//		glCullFace(GL_BACK);
//		glEnable(GL_CULL_FACE);
//	}
//	else
//	{
//		glCullFace(GL_FRONT);
//		glEnable(GL_CULL_FACE);
//	}
//	glCallList(list1);
//	glPopMatrix();
//	glDisable(GL_LIGHTING);
//	glCallList(list2);
//	glRotatef(LightAngle, 0, 1, 0);
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); glVertex3f(myLightPosition[0], myLightPosition[1], myLightPosition[2]);
//	glEnd();
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void sobitie(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'o':
//	{
//		ObjectAngle += 5;
//		glutPostRedisplay();
//	}
//	case 'l':
//	{
//		LightAngle += 5;
//		if (ObjectAngle > 360)
//			ObjectAngle = 0;
//		glutPostRedisplay();
//	}
//	case 'f': {
//		FrontSide = true;
//		break;
//	}
//	case  'b': {
//		FrontSide = false;
//		break;
//	}
//	}
//
//	glutPostRedisplay();
//}
//
//void klik(int button, int state, int x, int y) {
//	if (button == GLUT_LEFT_BUTTON)
//		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
//	else if (button == GLUT_RIGHT_BUTTON)
//		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//}
//
//int main(int argc, char* argv[]) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//	glutInitWindowSize(800, 800);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("new window");
//	glutDisplayFunc(mydisplay);
//	glutKeyboardFunc(sobitie);
//	glutMouseFunc(klik);
//	init();
//	MyFigure();
//	glutMainLoop();
//}

GLfloat myAmbient[] = { 0.10588, 0.058824, 0.113725, 1 };
GLfloat myDiffuse[] = { 0.427451, 0.470588, 0.541176, 1 };
GLfloat mySpecular[] = { 0.3333, 0.3333, 0.521569, 1 };
GLfloat myShininess[] = { 9.84615 };

GLfloat ratio = 4.0 / 3.0;
GLfloat angle = 0.0, plusangle = 0.0;
AUX_RGBImageRec* image1, * image2, * image3, * image4;
int ch1 = 0, ch2 = 0;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	
}
void reshape(int width, int height)
{
	if (ratio > width / height) glViewport(0, 0, width, width / ratio);
	else glViewport(0, 0, height * ratio, height);
}


void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle, 0.0, 1.0, 0.0);

	image1 = auxDIBImageLoadA("texture1.bmp");
	image2 = auxDIBImageLoadA("texture2.bmp");
	image3 = auxDIBImageLoadA("texture1.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 }; // Источник света в CKw
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция источника света будет преобразована в CKe*/
	glLightfv(GL_LIGHT0, GL_AMBIENT, myAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, myDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mySpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);

	glEnable(GL_LIGHTING); // Включение расчета освещенности
	glEnable(GL_LIGHT0); // включаем этот конкретный источник

	glPushMatrix();	

	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glPopMatrix(); // Восстанавливаем VM=Fwe
	// грань dawn
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0); 
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(1, 0, 1);
	glTexCoord2f(1, 1); glVertex3f(0, 0, 1);
	glEnd();
	//грань f1
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0.707, -0.707); 
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0, 0, 1);
	glTexCoord2f(1, 0); glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	//грань f2
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);
	glBegin(GL_POLYGON);
	glNormal3f(-0.707, 0.707, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	//// грань f3
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);
	glBegin(GL_POLYGON);
	glNormal3f(0.707, 0.707, 0);
	glTexCoord2f(0, 0); glVertex3f(1, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1, 0, 1);
	glTexCoord2f(1, 0); glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	//// грань f4
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);
	glBegin(GL_POLYGON);
	glNormal3f(0, 0.707, 0.707);
	glTexCoord2f(0, 0); glVertex3f(1, 0, 1);
	glTexCoord2f(0, 1); glVertex3f(0, 0, 1);
	glTexCoord2f(1, 0); glVertex3f(0.5, 0.5, 0.5);
	glEnd();

	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение

	glBegin(GL_LINES); //Рисуем координатные оси разного цвета в CKe
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
	glEnd();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void myIdle()
{
	angle += plusangle; if (angle > 360.0) angle = 0;
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
	if (key == '0') {
		if (ch1 % 2 == 0) plusangle = 2;
		else plusangle = 0;
		ch1++;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Пример текстурирования");
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutReshapeFunc(reshape);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();

}
