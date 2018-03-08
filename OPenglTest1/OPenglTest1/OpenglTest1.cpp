#include"GL\glut.h"
#include<iostream>

//方块位置
GLfloat ix = 0.0f;
GLfloat iy = 0.0f;

//方块尺寸
GLfloat csize = 25;

//x移动步数
GLfloat xstep = 1.0f;
//y移动步数
GLfloat ystep = 1.0f;

//窗口宽度
GLfloat WindowHeight;
//窗口高度
GLfloat WindowWidth;

void Rendersence(void)
{	//窗口清除
	glClear(GL_COLOR_BUFFER_BIT);
	//设置方块颜色
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(ix, iy, ix + csize, iy - csize);
	//刷新绘图命令
	glutSwapBuffers();
}

//移动逻辑控制函数相当于DX的switch循环
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
	//刷新窗口
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}
void setUpRC(void)
{
	//设置背景颜色
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void changeSize(GLsizei w, GLsizei h)
{
	GLfloat a;
	//防止除数为0
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0, 0, w, h);	
	glMatrixMode(GL_PROJECTION);
	//重置坐标位置
	glLoadIdentity();

	a = (GLfloat)w / (GLfloat)h;
	if (w <= h)
	{
		WindowWidth = 100;
		WindowHeight = 100 / a;
		//设置裁剪空间大小
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
	//调用重新渲染函数
	glutReshapeFunc(changeSize);
	glutTimerFunc(33, TimerFunction, 1);
	setUpRC();
	glutMainLoop();
	return 0;
}
