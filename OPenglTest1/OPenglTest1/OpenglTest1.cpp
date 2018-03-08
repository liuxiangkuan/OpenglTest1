#include"GL\glut.h"
#include<iostream>

//����λ��
GLfloat ix = 0.0f;
GLfloat iy = 0.0f;

//����ߴ�
GLfloat csize = 25;

//x�ƶ�����
GLfloat xstep = 1.0f;
//y�ƶ�����
GLfloat ystep = 1.0f;

//���ڿ��
GLfloat WindowHeight;
//���ڸ߶�
GLfloat WindowWidth;

void Rendersence(void)
{	//�������
	glClear(GL_COLOR_BUFFER_BIT);
	//���÷�����ɫ
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(ix, iy, ix + csize, iy - csize);
	//ˢ�»�ͼ����
	glutSwapBuffers();
}

//�ƶ��߼����ƺ����൱��DX��switchѭ��
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
	//ˢ�´���
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}
void setUpRC(void)
{
	//���ñ�����ɫ
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void changeSize(GLsizei w, GLsizei h)
{
	GLfloat a;
	//��ֹ����Ϊ0
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0, 0, w, h);	
	glMatrixMode(GL_PROJECTION);
	//��������λ��
	glLoadIdentity();

	a = (GLfloat)w / (GLfloat)h;
	if (w <= h)
	{
		WindowWidth = 100;
		WindowHeight = 100 / a;
		//���òü��ռ��С
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
	//����������Ⱦ����
	glutReshapeFunc(changeSize);
	glutTimerFunc(33, TimerFunction, 1);
	setUpRC();
	glutMainLoop();
	return 0;
}
