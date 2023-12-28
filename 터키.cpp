#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//컴퓨터소프트웨어공학과
//20184045_백인석

void display_white_circle()						//하얀색 원을 그리는 함수
{
	glColor3f(1.0, 1.0, 1.0);

	glShadeModel(GL_SMOOTH);

	double radius = 4.0;						//반지름은 4로 설정

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)				//360번
	{
		double angle = i * 3.141592 / 180;		//각도를 설정
		double x = radius * cos(angle);			//선분을 그을 x값과 y값 설정
		double y = radius * sin(angle);			
		glVertex2f(x-4, y);						//원점에서 -4만큼을 중심으로 설정
	}
	glEnd();
	glFlush();
	glutSwapBuffers();

}
void display_red_circle()						//빨간색 원을 그리는 함수
{
	glColor3f(1.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);

	double radius = 3.2;						//반지름은 3.2로 설정

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i * 3.141592 / 180;		//각도를 설정
		double x = radius * cos(angle);			//선분을 그을 x값과 y값 설정
		double y = radius * sin(angle);
		glVertex2f(x - 3, y);					//원점에서 -3만큼을 중심으로 설정
	}
	glEnd();
	glFlush();
	glutSwapBuffers();

}

void display_star()								//별을 그리는 함수
{
	glColor3f(1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);

	glBegin(GL_POLYGON);						//삼각형은 다섯개를 사용
	glVertex3f(-0.1, 0.0, 0.0);					//첫번째 삼각형
	glVertex3f(0.851, 0.309, 0.0);
	glVertex3f(0.851, -0.309, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.485, 0.81, 0.0);				//두번째 삼각형
	glVertex3f(0.97, 0.28, 0.0);
	glVertex3f(0.485, -0.18, 0.0);
	glEnd();

	glBegin(GL_POLYGON);		
	glVertex3f(0.485, 0.18, 0.0);				//세번째 삼각형
	glVertex3f(0.861, -0.319, 0.0);
	glVertex3f(1.5, 0.55, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.851, 0.309, 0.0);				//네번째 삼각형
	glVertex3f(0.49, -0.18, 0.0);
	glVertex3f(1.6, -0.4, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.485, 0.18, 0.0);				//다섯번째 삼각형
	glVertex3f(1.05, 0.18, 0.0);
	glVertex3f(0.485, -0.81, 0.0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void display_all()								//위 3가지 도형을 모두 띄우는 함수
{
	glColor3f(1.0, 1.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glutSwapBuffers();
	double radius = 4.0;

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i * 3.141592 / 180;		//하얀색원을 먼저 그린다
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex2f(x - 4, y);
	}
	glEnd();
	glFlush();

	radius = 3.2;
	glColor3f(255.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i * 3.141592 / 180;		//두번째원을 나중에 그림으로서 빨간원이 하얀원 위에있게한다.
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex2f(x - 3, y);
	}
	glEnd();
	glFlush();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.0, 0.0);
	glVertex3f(0.851, 0.309, 0.0);
	glVertex3f(0.851, -0.309, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.485, 0.81, 0.0);
	glVertex3f(0.97, 0.28, 0.0);
	glVertex3f(0.485, -0.18, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.485, 0.18, 0.0);
	glVertex3f(0.861, -0.319, 0.0);
	glVertex3f(1.5, 0.55, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.851, 0.309, 0.0);
	glVertex3f(0.49, -0.18, 0.0);
	glVertex3f(1.6, -0.4, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.485, 0.18, 0.0);
	glVertex3f(1.05, 0.18, 0.0);
	glVertex3f(0.485, -0.81, 0.0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void display()
{
	glColor3f(1.0, 0.0, 0.0);						//배경을 빨간색으로
	glutSwapBuffers();

}

void init()
{
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	float  WidthFactor = (float)new_w / 250.0;
	float  HeightFactor = (float)new_h / 250.0; 

		glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-5.0 * WidthFactor, 5.0 * WidthFactor, -5.0 * HeightFactor, 5.0 * HeightFactor);
}

void keyboardProcess(unsigned char Key, int x, int y)
{
	switch (Key)
	{
		case'1':
		printf("숫자1를 입력\n");						//키보드에서 1을 입력시
		display_white_circle();						//첫번째(하얀)원이 그려진다.
		break;
		case'2':
		printf("숫자2를 입력\n");						//키보드에서 2를 입력시
		display_red_circle();						//두번째(빨간)원이 그려진다.
		break;
		case'3':
		printf("숫자3를 입력\n");						//키보드에서 3을 입력시
		display_star();								//별이 그려진다.
		break;
		case 0x0D :									//키보드에서 엔터(0x0D)를 입력시
		display_all();								//3가지 모두 그려진다.
		break;
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(600, 400);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("02 Reshape Callback");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardProcess);
	glutReshapeFunc(reshape);
	glutMainLoop();


	return 0;
}