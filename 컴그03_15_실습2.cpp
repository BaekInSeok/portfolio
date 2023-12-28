#include <GL/glut.h>
#include <stdlib.h>

//컴퓨터소프트웨어공학과
//20184045_백인석

void display(void)
{

	//사각형의 좌표입력
	glBegin(GL_POLYGON);            //선, 점, 면등을 그리기 위해 사용.
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.1, 0.7, 0.0);
	glVertex3f(0.9, 0.7, 0.0);
	glVertex3f(0.5, 0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);            //선, 점, 면등을 그리기 위해 사용.
	glColor3f(1.0, 0, 0);
	glVertex3f(0.1, 0.16, 0.0);
	glVertex3f(0.9, 0.16, 0.0);
	glVertex3f(0.5, 0.9, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.25, 0.55, 0.0);
	glVertex3f(0.75, 0.55, 0.0);
	glVertex3f(0.5, 0.1, 0.0);
	glEnd();
	glBegin(GL_POLYGON);            //선, 점, 면등을 그리기 위해 사용.
	glColor3f(1, 0, 0);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.5, 0.7, 0.0);
	glEnd();
	glFlush(); //사각형을 화면에 그림
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //윈도우배경을 검은색으로 설정. 윈더우의 배경을 지울때 사용될 색상을 지정. 4개의 인수는 RGBA각 색상 요소의 강도를 지정 (0~1);
	glClear(GL_COLOR_BUFFER_BIT); //색상버퍼를 사용, 인수로 어떤 버퍼를 지울지 지정.
	glMatrixMode(GL_PROJECTION); //사용할 행렬모드를 지정.
	glLoadIdentity(); //단위행렬

	//직교투영
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); //직교투영을 위한 버뮈설정, 멀고 가까움은 표현 불가.
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut 상태를 초기화 GLUT라이브러리를 초기화하고 윈도우와 연결하여 하나의 세션형성. 어떤 glut 함수보다 먼저 실행되어야함.
	//디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//창의 크기와 위치 설정
	glutInitWindowSize(550, 550); //그래픽을 출력할 윈도우의 크기를 지정
	glutInitWindowPosition(100, 100); //화면 좌상단을 원점으로 하여 x,y 위치에 윈도우의 좌상단을 위치 시킴


	glutCreateWindow("01 사각형 그리기 "); //윈도우 생성, 윈도우 상단의 제목을 문자열을 인수로 지정. glutmainLoop()가 호툴되기 전까지는 윈도우가 디스플레이되지 않음.
	init();

	//필요한 함수 등록
	glutDisplayFunc(display); //콜백함수
	glutMainLoop(); //이벤트 처리엔진 시작, 무한 이벤트처리 루프. 이벤트가 발생하면 일치하는 콜백함수가 등록되어 있을경우, 등록된함수가 자동으로 호출.
	return 0;
}