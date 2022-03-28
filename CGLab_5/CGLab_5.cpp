#include <gl\glut.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
GLfloat myAmbient[] = { 0.10588, 0.058824, 0.113725, 1 };
GLfloat myDiffuse[] = { 0.427451, 0.470588, 0.541176, 1 };
GLfloat mySpecular[] = { 0.3333, 0.3333, 0.521569, 1 };
GLfloat myShininess[] = { 9.84615 };

GLfloat angle = 0, plusangle = 0;
GLfloat angle2 = 0, plusangle2 = 0;
int ch1 = 0, ch2 = 0;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myDisplay()
{
    glPushMatrix(); //Сохраняем VM = 1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //вместе с очисткой буфера цвета предусмотреть очистку буфера глубины
    glEnable(GL_DEPTH_TEST); //включение режима удаления невидимых (проверка глубины)
    gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0); // VM=Fwe // позиция наблюдателя

    GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 }; // Источник света в CKw
    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция источника света будет преобразована в CKe*/
    glLightfv(GL_LIGHT0, GL_AMBIENT, myAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, myDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, mySpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);

    glEnable(GL_LIGHTING); // Включение расчета освещенности
    glEnable(GL_LIGHT0); // включаем этот конкретный источник

    glPushMatrix(); //Сохраняем VM=Fwe
    //    Рисуем направление к источнику света в CKe
    glBegin(GL_LINES); glColor3f(0, 0, 0); glVertex3f(1, 2, 2); glVertex3f(0.0, 0.0, 0.0); glEnd();
    glRotatef(angle2, 0, 1, 0);
    glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
    glPopMatrix(); // Восстанавливаем VM=Fwe

    glPushMatrix(); //Сохраняем VM=Fwe
    glRotatef(angle, 0, 1, 0); // VM=Fwe*R

    // грань dawn
    glBegin(GL_POLYGON);
    glNormal3f(0, -1, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(0, 0, 1);
    glEnd();
    //грань f1
    glBegin(GL_POLYGON);
    glNormal3f(0, 0.707, -0.707); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0.5, 0.5, 0.5);
    glEnd();
    //грань f2
    glBegin(GL_POLYGON);
    glNormal3f(-0.707, 0.707, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); glVertex3f(0.5, 0.5, 0.5);
    glEnd();
    //// грань f3
    glBegin(GL_POLYGON);
    glNormal3f(0.707, 0.707, 0); glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(0.5, 0.5, 0.5);
    glEnd();
    //// грань f4
    glBegin(GL_POLYGON);
    glNormal3f(0, 0.707, 0.707); glVertex3f(1, 0, 1); glVertex3f(0, 0, 1); glVertex3f(0.5, 0.5, 0.5);
    glEnd();

    glPopMatrix(); // Восстанавливаем VM=Fwe
    glDisable(GL_LIGHTING); //Выключаем освещение

    glBegin(GL_LINES); //Рисуем координатные оси разного цвета в CKe
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
    glEnd();



    glPopMatrix();
    glutSwapBuffers();
    //    usleep(50000);
}

void myReshape(int width, int height)
{
    if (width / height < 1) glViewport(0, 0, width, width);
    else glViewport(0, 0, height, height);
}

void myIdle()
{
    angle += plusangle; if (angle > 360.0) angle = 0;
    angle2 += plusangle2; if (angle2 > 360.0) angle2 = 0;
    glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
    if (key == 'o') {
        if (ch1 % 2 == 0) plusangle = 0.5;
        else plusangle = 0;
        ch1++;
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //устанавливая режим дисплея в функции main( ), предусмотрено использование буфера глубины
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Задание 2, 4 лабораторная работа.");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keys);
    glutReshapeFunc(myReshape);
    glutIdleFunc(myIdle);
    init();
    glutMainLoop();
}