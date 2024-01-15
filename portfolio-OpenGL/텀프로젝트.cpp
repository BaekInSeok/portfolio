#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
int speed = 0;    //속도조절을 위한 변수
int accel = 1;    //가속을 위한 변수
int stop = 0;     //정지 기능을 위한 변수
int number = 0;   //시점에 번호를 매기기위한 변수
double i = 0.1;   //회전 시에 쓰이는 변수
double e = 0.1;   //확대 축소 시에 쓰이는 변수
double rad = 11;  //태양을 중심으로 원을 그릴때 반지름을 11로 정함.
GLfloat ratio = 0;//클릭시에 뷰포트의 높/너비를 저장하는 변수
double zview = -(rand() % 11);    //랜덤 시점의 z축값 0부터 -11로 됨
double yview = -(rand() % 11);    //랜덤 시점의 y축값 0부터 -11로 됨
double xview = (rand() % 11)-5;   //랜덤 시점의 x축값 -5부터 5까지
double colors[10][3] = {          //색깔의 난수화를 위해 배열에 미리 설정된 값을 넣어 프로그램 시작시 정해진 값들로 행성의 색이 나타나고 특정한 행동으로 바꿀수있다.
	1, 0, 0,
	0.4, 0.4, 0.4,
	1, 1, 0.0,
	0.0, 1.0, 1.0,
	1.0, 1.0, 1.0,
	1.0, 0.2, 0.0,
	1.0, 1.0, 0.5,
	1.0, 0.5, 0.5,
	0.2, 0.5, 0.5,
	0.2, 0.8, 0.5
};


void MyTimer(int Value) {
	if (stop == 0){           //만약 stop이라는 변수가 0이면
		speed = (speed + accel);  //speed를 증가 시킴으로서 회전
	}
	else {
		speed = speed + 0;    //그렇지 않으면 speed변수는 증가하지 않는다
	}
	if (speed == INT_MAX) speed = 0; //만약 속도가 int형의 최댓값에 도달하면 회전을 처음부터 한다
	glutPostRedisplay();
	glutTimerFunc(10, MyTimer, 1);
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glScalef(1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glInitNames();

	glPushName(100);//태양의 네임을 100으로 설정
	glPushMatrix();                     //배열에 푸쉬
	glTranslatef(0.0, -11.0, -11.0);    //태양(중심)의 위치를 카메라가 보고있는곳으로 수정
	glColor3f(colors[0][0], colors[0][1], colors[0][2]);//행성의 색깔을 1번째 배열의 RGB값으로 설정.
	glutWireSphere(1.0, 10, 5);     //태양의 크기가 1.0임
	glPopName();//배열에 팝

	glPushName(101);//수성의 네임을 101로 설정
	glPushMatrix();
	glColor3f(colors[1][0], colors[1][1], colors[1][2]);
	glRotatef(speed * 0.25, 0.0, 1.0, 0.0);   //0.25 의 속도로 회전한후
	glTranslatef(1.3, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.1, 10, 8);      //수성의 크기를 0.1으로
	glPopMatrix();
	glPopName();

	glPushName(102);//금성의 네임을 102로 설정
	glPushMatrix();
	glColor3f(colors[2][0], colors[2][1], colors[2][2]);
	glRotatef(speed * 0.6, 0.0, 1.0, 0.0);   //0.6 의 속도로 회전한후
	glTranslatef(2.3, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.25, 10, 8);      //금성의 크기를 0.25로
	glPopMatrix();
	glPopName();

	glPushName(103);//지구의 네임을 103으로 설정
	glPushMatrix();
	glColor3f(colors[3][0], colors[3][1], colors[3][2]);
	glRotatef(speed, 0.0, 1.0, 0.0);  //1 의 속도로 회전한후
	glTranslatef(3.3, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.25, 10, 8);      //지구의 크기를 0.25로
	glPopName();
	//여기서 달은 지구 주위에서 공전을 하기 때문에 배열을 pop하지 않는다.
	glPushName(104);//달의 네임을 104로 설정.
	glColor3f(colors[4][0], colors[4][1], colors[4][2]);
	glRotatef(speed * 0.07, 1.0, 0.0, 0.0); //0.07 의 속도로 회전한후
	glTranslatef(0.5, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.06, 10, 8);      //달의 크기를 0.07으로
	glPopMatrix();
	glPopName();

	glPushName(105);//화성의 네임을 105로설정
	glPushMatrix();
	glColor3f(colors[5][0], colors[5][1], colors[5][2]);
	glRotatef(speed * 1.9, 0.0, 1.0, 0.0); //1.9 의 속도로 회전한후
	glTranslatef(4.3, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.125, 10, 8);     //화성의 크기를 0.125로
	glPopMatrix();
	glPopName();

	glPushName(106);//목성의 네임을 106으로 설정
	glPushMatrix();
	glColor3f(colors[6][0], colors[6][1], colors[6][2]);
	glRotatef(speed * 0.5, 0.0, 1.0, 0.0); //0.5 의 속도로 회전한후
	glTranslatef(5.3, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.3, 10, 8);     //목성의 크기를 0.3로
	glPopMatrix();
	glPopName();

	glPushName(107);//토성의 네임을 107로 설정
	glPushMatrix();
	glColor3f(colors[7][0], colors[7][1], colors[7][2]);
	glRotatef(speed * 0.6, 0.0, 1.0, 0.0); //0.6 의 속도로 회전한후
	glTranslatef(5.9, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.3, 10, 8);     //토성의 크기를 0.3로
	glPopMatrix();
	glPopName();

	glPushName(108);//천왕성의네임을 108로 설정
	glPushMatrix();
	glColor3f(colors[8][0], colors[8][1], colors[8][2]);
	glRotatef(speed * 0.3, 0.0, 1.0, 0.0); //0.3 의 속도로 회전한후
	glTranslatef(6.2, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.1, 10, 8);     //천왕성의 크기를 0.1로
	glPopMatrix();
	glPopName();

	glPushName(109);//해왕성의 네임을 109로 설정
	glPushMatrix();
	glColor3f(colors[9][0], colors[9][1], colors[9][2]);
	glRotatef(speed * 0.8, 0.0, 1.0, 0.0); //0.8 의 속도로 회전한후
	glTranslatef(6.2, 0.0, 0.0);      //다시 각도에 맞는 위치로 이동
	glutWireSphere(0.1, 10, 8);     //해왕성의 크기를 0.1로
	glPopMatrix();
	glPopName();

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int new_w, int new_h) {

	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	ratio = (GLfloat)new_w / (GLfloat)new_h; //뷰포트 클릭값에서 쓰일 ratio를 정해준다.
	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0); //정해진 카메라의 위치, 시야

	glutPostRedisplay();
}


void popMenu(int value)
{
	switch (value)
	{
	case 0://기본 메뉴를 선택하면
		i = 0.1;
		glLoadIdentity();
		gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);  //기본시점의 좌표
		glutPostRedisplay();
		number = 0;//기본시점은 0번
		i = 0.1;//회전에쓰이는 i변수를 초기화
		e = 0.1;//확대축소에 쓰이는 e변수를 초기화
		break;

	case 1://두번째 메뉴를 선택하면
		i = 0.1;
		glLoadIdentity();
		gluLookAt(0.0, 0.0, -11, 0.0, -11.0, -11, 1.0, 1.5, 0.0);   //위 시점의 좌표
		glutPostRedisplay();
		number = 1;//위 시점은 1번
		i = 0.1;//회전에 쓰이는 i변수를 초기화
		e = 0.1;//확대축소에 쓰이는 e변수를 초기화
		break;

	case 2://세번재 메뉴를 선택하면
		i = 0.1;
		glLoadIdentity();
		gluLookAt(-11.0, -11.0, -11, 0.0, -11.0, -11, 1.0, 1.5, 0.0);   //옆 시점의 좌표
		glutPostRedisplay();
		number = 2;//옆시점은 2번
		i = 0.1;//회전에 쓰이는 i변수를 초기화
		e = 0.1;//확대축소에 쓰이는 e변수를 초기화
		break;
	case 3://4번째 메뉴를 선택하면
		i = 0.1;
		glLoadIdentity();
		gluLookAt(0.0, -11.0, 0.0, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //앞 시점의 좌표
		glutPostRedisplay();
		number = 3;//앞시점은 3번
		i = 0.1;//회전에 쓰이는 i변수를 초기화
		e = 0.1;//확대축소에 쓰이는 e변수를 초기화
		break;
	case 4://다섯번째 메뉴를 선택하면
		i = 0.1;
		zview = -(rand() % 11);  //여기서 메뉴를 새로 띄울때마다 시점이 랜덤으로 바뀌어야하기 때문에
		yview = -(rand() % 11);  //랜덤시점의 변수를 다시 정해준다.
		xview = (rand() % 11) - 5;
		glLoadIdentity();
		gluLookAt(xview, yview, zview, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //랜덤 시점의 좌표
		glutPostRedisplay();
		number = 4;//랜덤시점은 4번
		i = 0.1;//회전에 쓰이는 i변수를 초기화
		e = 0.1;//확대축소에 쓰이는 e변수를 초기화
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 32:            //스페이스 바를 누르면
		if (stop == 0) {//stop이 0일시에
			stop = 1;   //stop을 1로 바꿈으로서 정지
			break;
		}
		else if (stop == 1) {  //stop이 1일떄
			stop = 0;          //stop을 0으로 바꿔서 다시 회전 시작
			break;
		}
	case '+':            //+를 누르면
		accel++;         //accel이 증가하면서 속도가 증가
		break;
	case '-':            //+를 누르면
		accel--;         //accel이 감소하면서 속도가 감소
		break;
	}
}//회전및 확대 축소는 카메라의 이동으로 이루어 져야 하기 떄문에 아래와 같은 방식으로 확대축소회전을 실행,

void special_key(int key, int x, int y) { //방향키 입력을 위해 specialfunc를 사용
	switch (key)
	{						  
	case 100:                 //방향키 왼쪽버튼을 누르면 왼쪽으로 회전
		if (number == 0) {//0번째 시점인 기본시점인 경우에
			glLoadIdentity();
			double angle = i * 3.141592 / 180;//원을 그리기 위해 angle과
			double x = 11 * cos(angle);//x * 반지름
			double y = 11 * sin(angle);//y * 반지름 값을 구해 연속으로 이동시 원을 그릴수 있게 정한다.
			gluLookAt(0.1 -y, 0.1 +(x - 11), 0.1 + (x-11), 0.0, -11, -11, 1.0, 1.5, 0.0);   //기본 시점의 좌표 Lookat에서 보는 시점은 물체의 중심인 0,-11,-11로 고정한다.
			i = i + 1;//그리고 i값을 바꿔 카메라의 시점이 원점으로 이동하게 설정한다.
			glutPostRedisplay();//믿의 4개의 시점도 방법이 동일하다.
			break;
		}
		if (number == 1) {//1번째 시점인 위시점인 경우에
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle) ;
			double y = rad * sin(angle) ;
			gluLookAt(0.0, 0.0+(x-11), -11 -y, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //위 시점의 좌표
			i = i + 1;
			glutPostRedisplay();
			break;
		}
		if (number == 2) {//2번째 시점인 옆시점인 경우에
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle);
			double y = rad * sin(angle);
			gluLookAt(-11.0-(x-11), -11.0, -11 - y, 0.0, -11.0, -11, 1.0, 1.5, 0.0);   //옆 시점의 좌표
			i = i + 1;
			glutPostRedisplay();
			break;
		}
		if (number == 3) {//3번째 시점인 앞시점인 경우에
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle);
			double y = rad * sin(angle);
			gluLookAt(0.0-y, -11.0, 0.0+(x-11), 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //앞 시점의 좌표
			i = i + 1;
			glutPostRedisplay();
			break;
		}
		if (number == 4) {//4번째 시점인 랜덤시점인 경우에
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle);
			double y = rad * sin(angle);
			gluLookAt(xview-y , yview+y, zview, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //랜덤 시점의 좌표
			i = i + 1;
			glutPostRedisplay();
			break;
		}
	/// ///////////////////////////////////////////////////////////////////////////////////
	case 101:                 //방향키 위쪽버튼을 누르면 확대
		if (number == 0) {//0번째 시점인 기본시점인 경우에
			glLoadIdentity();
			gluLookAt(0.1, 0.1-e, 0.1-e, 0.1, 0.0-e, 0.0-e, 1.0, 1.5, 0.0);   //기본 시점의 좌표에서 카메라의 위치가 원점에 가깝게 이동하고
			e = e + 0.1;													  //바라보는 위치도 카메라 이동에 맞춰서 이동한다. 동시에 e값을 0.1로해서 한번누를때마다 0.1씩 이동한다.
			glutPostRedisplay();			//밑의 3개의 시점도 방식이 동일하지만 랜덤시점은 다름
			break;
		}
		if (number == 1) {
			glLoadIdentity();
			gluLookAt(0.0, 0.0 - e, -11, 0.0 , -11.0 -e, -11.0, 1.0, 1.5, 0.0);   //위 시점의 좌표
			e = e + 0.1;
			glutPostRedisplay();
			break;
		}
		if (number == 2) {
			glLoadIdentity();
			gluLookAt(-11.0 +e, -11.0, -11, 0.0 +e, -11.0, -11, 1.0, 1.5, 0.0);   //옆 시점의 좌표
			e = e + 0.1;
			glutPostRedisplay();
			break;
		}
		if (number == 3) {
			glLoadIdentity();
			gluLookAt(0.0, -11.0, 0.0-e, 0.0, -11.0, -11.0-e, 1.0, 1.5, 0.0);   //앞 시점의 좌표
			e = e + 0.1;
			glutPostRedisplay();
			break;
		}
		if (number == 4) {//랜덤시점에서의 확대
			glLoadIdentity();
			if (xview > 0) xview -= 0.1;
			if (xview < 0) xview += 0.1;
			if (xview == 0) xview = xview;
			if (yview > -11) yview -= 0.1;			//시점이 랜덤이기 때문에 하나의 축만 확대를 하면 확대가 되지 않는다.
			if (yview < -11) yview += 0.1;			//그래서 물체의 원점을 정해놓고 그 원점을 향해 점점 접근하는방식을 사용했다.
			if (yview == -11) yview = yview;
			if (zview > -11) zview -= 0.1;
			if (zview < -11) zview += 0.1;
			if (zview == -11) zview = zview;
			gluLookAt(xview, yview, zview, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //랜덤 시점의 좌표
			e = e + 0.1;
			glutPostRedisplay();
			break;
		}
	/// ///////////////////////////////////////////////////////////////////////////////////
	case 102:                 //방향키 오른쪽버튼을 누르면
		if (number == 0) {       //위의 왼쪽 방향으로 회전하는 방식과 같지만 반대로 i값이 감소를 한다.
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = 11 * cos(angle);
			double y = 11 * sin(angle);
			gluLookAt(0.1 - y, 0.1 + (x - 11), 0.1 + (x - 11), 0.0, -11, -11, 1.0, 1.5, 0.0);   //기본 시점의 좌표
			i = i - 1;
			glutPostRedisplay();
			break;
		}
		if (number == 1) {
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle);
			double y = rad * sin(angle);
			gluLookAt(0.0, 0.0 + (x - 11), -11 - y, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //위 시점의 좌표
			i = i - 1;
			glutPostRedisplay();
			break;
		}
		if (number == 2) {
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle);
			double y = rad * sin(angle);
			gluLookAt(-11.0 - (x - 11), -11.0, -11 - y, 0.0, -11.0, -11, 1.0, 1.5, 0.0);   //옆 시점의 좌표
			i = i - 1;
			glutPostRedisplay();
			break;
		}
		if (number == 3) {
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle);
			double y = rad * sin(angle);
			gluLookAt(0.0 - y, -11.0, 0.0 + (x - 11), 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //앞 시점의 좌표
			i = i- 1;
			glutPostRedisplay();
			break;
		}
		if (number == 4) {
			glLoadIdentity();
			double angle = i * 3.141592 / 180;
			double x = rad * cos(angle);
			double y = rad * sin(angle);
			gluLookAt(xview - y, yview + y, zview, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //랜덤 시점의 좌표
			i = i - 1;
			glutPostRedisplay();
			break;
		}
	/// ///////////////////////////////////////////////////////////////////////////////////
	case 103:                 //방향키 아래쪽버튼을 누르면	
		if (number == 0) {	  //확대하는 방식과 같지만 이번에는 e값을 감소시킴으로서 카메라를 뒤로 뺌
			glLoadIdentity();
			gluLookAt(0.1, 0.1 - e, 0.1 - e, 0.1, 0.0 - e, 0.0 - e, 1.0, 1.5, 0.0);   //기본 시점의 좌표
			e = e - 0.1;
			glutPostRedisplay();
			break;
		}
		if (number == 1) {
			glLoadIdentity();
			gluLookAt(0.0, 0.0 - e, -11, 0.0, -11.0 - e, -11.0, 1.0, 1.5, 0.0);   //위 시점의 좌표
			e = e - 0.1;
			glutPostRedisplay();
			break;
		}
		if (number == 2) {
			glLoadIdentity();
			gluLookAt(-11.0 + e, -11.0, -11, 0.0 + e, -11.0, -11, 1.0, 1.5, 0.0);   //옆 시점의 좌표
			e = e - 0.1;
			glutPostRedisplay();
			break;
		}
		if (number == 3) {
			glLoadIdentity();
			gluLookAt(0.0, -11.0, 0.0 - e, 0.0, -11.0, -11.0 - e, 1.0, 1.5, 0.0);   //앞 시점의 좌표
			e = e - 0.1;
			glutPostRedisplay();
			break;
		}
		if (number == 4) {
			glLoadIdentity();
			if (xview > 0) xview += 0.1;
			if (xview < 0) xview -= 0.1;
			if (xview == 0) xview = xview;
			if (yview > -11) yview += 0.1;
			if (yview < -11) yview -= 0.1;
			if (yview == -11) yview = yview;  //확대시의 방식과 같지만 값의 증감이 다르다.
			if (zview > -11) zview += 0.1;
			if (zview < -11) zview -= 0.1;
			if (zview == -11) zview = zview;
			gluLookAt(xview, yview, zview, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);   //랜덤 시점의 좌표
			e = e + 0.1;
			glutPostRedisplay();
			break;
		}
	}
}

double f_rand(void) //0부터 1사이의 실수를 정하기 위한 함수
{
	double a;//double형 a를 하나 선언 후
	a = rand() / (double)RAND_MAX;//난수를 하나 생성후 난수의 최댓값으로 나누고 a에 저장
	return a;//0부터 1사이의 소수가 a로 반환된다.
}


void ProcessSelect(GLuint index[64]) //밑에서 나올 함수인 selectobject에서 특정한 행성이 선택 되었을때 나오는 값.
{
	switch (index[3]) {
	case 100://아까 해의 네임을 100으로 정해둠
		printf("해");//해가 선택되면
		colors[0][0] = f_rand();//colors 배열의 3개를 f_rand함수로 0부터 1사이의 난수로 설정한다.
		colors[0][1] = f_rand();
		colors[0][2] = f_rand();
		break;
	case 101://아까 수성의 네임을 101으로 정해둠
		printf("수성");//수성이 선택되면
		colors[1][0] = f_rand();
		colors[1][1] = f_rand();
		colors[1][2] = f_rand();
		break;
	case 102://아까 금성의 네임을 102으로 정해둠
		printf("금성");//금성이 선택되면
		colors[2][0] = f_rand();
		colors[2][1] = f_rand();
		colors[2][2] = f_rand();
		break;
	case 103://아까 지구의 네임을 103으로 정해둠
		printf("지구");//지구가 선택되면
		colors[3][0] = f_rand();
		colors[3][1] = f_rand();
		colors[3][2] = f_rand();
		break;
	case 104://아까 달의 네임을 104으로 정해둠
		printf("달");//달이 선택되면
		colors[4][0] = f_rand();
		colors[4][1] = f_rand();
		colors[4][2] = f_rand();
		break;
	case 105://아까 화성의 네임을 105으로 정해둠
		printf("화성");//화성이 선택되면
		colors[5][0] = f_rand();
		colors[5][1] = f_rand();
		colors[5][2] = f_rand();
		break;
	case 106://아까 목성의 네임을 106으로 정해둠
		printf("목성");//목성이 선택되면
		colors[6][0] = f_rand();
		colors[6][1] = f_rand();
		colors[6][2] = f_rand();
		break;
	case 107://아까 토성의 네임을 107으로 정해둠
		printf("토성");//토성이 선택되면
		colors[7][0] = f_rand();
		colors[7][1] = f_rand();
		colors[7][2] = f_rand();
		break;
	case 108://아까 천왕성의 네임을 108으로 정해둠
		printf("천왕성");//천왕성이 선택되면
		colors[8][0] = f_rand();
		colors[8][1] = f_rand();
		colors[8][2] = f_rand();
		break;
	case 109://아까 해왕성의 네임을 109으로 정해둠
		printf("해왕성");//해왕성이 선택되면.
		colors[9][0] = f_rand();
		colors[9][1] = f_rand();
		colors[9][2] = f_rand();
		break;
	}
}

void SelectObjects(GLint x, GLint y)//행성을 마우스로 클릭해 선택하는 함수. 매개변수로 마우스의 x축 y축을 가져온다.
{
	GLuint selectBuff[64];                                //정해둔 물체의 name이 이 배열에 저장됨.
	GLint hits, viewport[4];                              //glviewport함수에서 사용될 뷰포트외 hits변수를 선언
	glSelectBuffer(64, selectBuff);                       //selectBuff에서 사용될 메모리 버퍼를 잡아준다.
	glGetIntegerv(GL_VIEWPORT, viewport);                 //ViewPort의 영역에관한 값들을 viewport배열에 저장
	glMatrixMode(GL_PROJECTION);                          //매트릭스 모드를 PROJECTION으로
	glPushMatrix();                                       //PROJECTIONMODE의 행렬값을 푸쉬해 저장한다
	glRenderMode(GL_SELECT);                              //렌더링 모드를 select로 지정
	glLoadIdentity();                                     //PROJECTOIN 행렬을 초기화
	gluPickMatrix(x, viewport[3] - y, 20,20, viewport);      //마우스가 클릭한 위치와 뷰포트값으로 picking행렬을 생성 그리고 선택영역을 가로세로 20픽셀로 설정한다.
	gluPerspective(60.0, ratio, 1.0, 20.0);             //투영값을 초기값으로 돌려놓음.
	glMatrixMode(GL_MODELVIEW);                           //다시 물체를 화면에 그리기 위해 모드를 MODELVIEW로
	glLoadIdentity();                                     //다시한번 PROJECTION 행렬을 초기화
	if(number == 0)gluLookAt(0.1, 0.1, 0.1, 0.1, 0.0, 0.0, 1.0, 1.5, 0.0);       //보고있던 시점에 따라 Lookat의 값들을 다시 원래대로 돌려놓음.
	if (number == 1)gluLookAt(0.0, 0.0, -11, 0.0, -11.0, -11, 1.0, 1.5, 0.0);
	if (number == 2)gluLookAt(-11.0, -11.0, -11, 0.0, -11.0, -11, 1.0, 1.5, 0.0);
	if (number == 3)gluLookAt(0.0, -11.0, 0.0, 0.0, -11.0, -11.0, 1.0, 1.5, 0.0);
	display();                                        //display를 호출에 다시한번 select버퍼에 그려준다.
	hits = glRenderMode(GL_RENDER);                       //다시한번 render버퍼에 그려준다.
	ProcessSelect(selectBuff);                 //클릭했을떄 선택된 물체를 확인하고 특정한 행위를 하는 ProcessSelect를 실행한다.
	glMatrixMode(GL_PROJECTION);                          //모드를 PROJECTION으로 설정
	glPopMatrix();                                        //아까 저장해두었던 PROJECTION의 행렬값을 다시 불러온다.
	glMatrixMode(GL_MODELVIEW);                           //다시한번 MODELVIEW
}

void mousebutton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {     //만약 마우스 왼쪽을 눌렀다 뗀다면
		SelectObjects(x, y);									//selectobject함수를 실행한다. 매개변수로는 마우스의 x축y축 값이 들어간다.
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("A");

	init();

	int submenu = glutCreateMenu(popMenu);
	glutAddMenuEntry("기본", 0);
	glutAddMenuEntry("위", 1);
	glutAddMenuEntry("옆", 2);
	glutAddMenuEntry("앞", 3);
	glutAddMenuEntry("무작위", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutTimerFunc(10, MyTimer, 1);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mousebutton);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_key);

	glutMainLoop();
	return 0;

}