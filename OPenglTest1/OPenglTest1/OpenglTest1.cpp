#include"GL\glut.h"
#include<iostream>

GLfloat ix = 0.0f;
GLfloat iy = 0.0f;
GLfloat csize = 25;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat WindowHeight;
GLfloat WindowWidth;


void Rendersence(void)
{	//´°¿ÚÇå³ý
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(ix, iy, ix + csize, iy - csize);
	//Ë¢ÐÂ»æÍ¼ÃüÁî
	glutSwapBuffers();
}

void TimerFunction(int value)
{
	if (ix>WindowWidth - csize || ix<-WindowWidth)
	{
		xstep = -xstep;
	}
	if (iy>WindowHeight || iy<-WindowHeight + csize)
	{
		ystep = -ystep;
	}
	ix += xstep;
	iy += ystep;

	if (ix>(WindowWidth - csize + xstep))
	{
		ix = WindowWidth - csize - 1;
	}
	else if (ix<-(WindowWidth + xstep))
	{
		ix = -WindowWidth - 1;
	}
	if (iy>(WindowHeight + ystep))
	{
		iy = WindowHeight - 1;
	}
	else if (iy<-(WindowHeight - csize + ystep))
	{
		iy = -WindowHeight + csize - 1;
	}
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}
void setUpRC(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void changeSize(GLsizei w, GLsizei h)
{
	GLfloat a;
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0, 0, w, h);
	//ÖØÖÃ×ø±êÎ»ÖÃ
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	a = (GLfloat)w / (GLfloat)h;
	if (w <= h)
	{
		WindowWidth = 100;
		WindowHeight = 100 / a;
		glOrtho(-100.0, 100.0, -100.0 / a, 100.0 / a, 1.0, -1.0);
	}
	else
	{
		WindowWidth = 100 * a;
		WindowHeight = 100;
		glOrtho(-100.0*a, 100.0*a, -100.0, 100.0, 1.0, -1.0);
	}



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("first");
	glutDisplayFunc(Rendersence);
	glutReshapeFunc(changeSize);
	glutTimerFunc(33, TimerFunction, 1);
	setUpRC();
	glutMainLoop();
	return 0;
}
