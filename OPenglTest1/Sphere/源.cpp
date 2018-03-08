#include"GL\glut.h"


void RenderSence(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static GLfloat fElect = 0.0f;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -100.0f);

	glColor3ub(255, 0, 0);
	glutSolidSphere(10.0f, 15, 15);


	glColor3ub(255, 255, 0);
	glPushMatrix();
	glRotatef(fElect, 0.0f, 1.0f, 0.0f);
	glTranslatef(50.0f, 0.0f, 0.0f);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();


	fElect += 10.0f;
	if (fElect>=360)
	{
		fElect = 0.0f;
	}
	glutSwapBuffers();
}


void setupRC()
{
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void Changesize(int w, int h)
{
	GLfloat nRange = 100.0f;
	if (h==0)
	{
		h = 1;
	}

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w<=h)
	{
		glOrtho(-nRange, nRange, nRange*w / h, -nRange*w / h, -nRange*2.0f, nRange*2.0f);
	}
	else
	{
		glOrtho(-nRange*w / h, nRange*w / h, nRange, -nRange, -nRange*2.0f, nRange*2.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void TimerFun(int value)
{
	glutPostRedisplay();
	glutTimerFunc(100, TimerFun, 1);
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("hello");
	glutReshapeFunc(Changesize);
	glutDisplayFunc(RenderSence);
	glutTimerFunc(500, TimerFun, 1);
	setupRC();

	glutMainLoop();
}