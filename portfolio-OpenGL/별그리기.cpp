#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

//컴퓨터소프트웨어공학과
//20184045_백인석
#define POINT 100                       //마우스 좌표의 구조체 개수를 100으로 설정


GLfloat Red = 0.0f;
GLfloat Green = 0.0f;
GLfloat Blue = 0.0f;

GLint index = 1;                       //기본색상이 하얀색이므로 팔레트배열의 2번쨰부터 시작.
GLfloat Delta = 0.0f;
unsigned char PALETTE[9][3] =
{
    {255,255,255},
    {0,255,255},
    {255,0,255},
    {192,192,192},
    {128,128,128},
    {128,0,0},
    {0,128,0},
    {0,0,128},
    {0,0,0}
};
GLfloat pt[POINT][2] = { 0, };          //포인터의 좌표가 들어갈 이차원 배열을 초기화 한다.
GLfloat width = 600;                    //윈도우 창의 가로 길이를 600으로 한다.
GLfloat height = 400;                   //윈도우 창의 높이를 400으로 한다.
GLint n = 0;                            //마우스 포인터의 좌표에 사용될 정수를 0으로 초기화 시킨다.
GLfloat angle = 0.0;
GLint rot_di = 1;                       //회전 방향의 정수를 1로 초기화시킨다.

void idleprocess()
{
    angle += 0.001;
    if (angle > 360.0) angle = 0.0f;
    glutPostRedisplay();
}

void display(void)
{
    
    int i;
    glClear(GL_COLOR_BUFFER_BIT);            
    glLineWidth(5.0f);                  //별들이 연결되는 선의 굵기를 지정한다.
    glEnableClientState(GL_VERTEX_ARRAY);//배열사용을 가능하게 한다.


    glRotatef(angle, 0, 0, rot_di);     //전역으로 설정한 rot_di방향으로 회전하게한다.
    
    for (i = 0; i < n; i++) {           //마우스 클릭 이벤트에서 넘어가는 n의 값만큼 반복을 하게된다.
        glBegin(GL_TRIANGLES);
        
        glVertex2f(pt[i][0] - 0.05f, pt[i][1] - 0.05f);
        glVertex2f(pt[i][0] + 0.05f, pt[i][1] - 0.05f);
        glVertex2f(pt[i][0], pt[i][1] + 0.1f);
        glEnd();

        glBegin(GL_TRIANGLES);                              //클릭되는 좌표에 삼각형 두개를 그린다.
        
        glVertex2f(pt[i][0] - 0.05f, pt[i][1] + 0.05f);
        glVertex2f(pt[i][0] + 0.05f, pt[i][1] + 0.05f);
        glVertex2f(pt[i][0], pt[i][1] - 0.1f);
        glEnd();

        if (i > 0) {
            glBegin(GL_LINES);                              //새로 생성되는 별과 그 전에 생성된 별을 열결하는 선을 그린다.
            
            glVertex2f(pt[i][0], pt[i][1]);
            glVertex2f(pt[i - 1][0], pt[i - 1][1]);
            glEnd();
        }

    }


    glEnd();
    glFlush();
    glutSwapBuffers();
}

void mousebutton(int button, int state, int x, int y)
{
     
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {     //만약 마우스 왼쪽을 눌렀다 뗀다면
        
        pt[n][0] = x / width -0.5;                              //회전축을 맞추기위해 길이에서 0.5만큼 좌표를 이동
        pt[n][1] = (height - y) / height -0.5;                  //또한 회전축을 맞추기위해 높이에서 0.5만큼의 좌표를 이동
        n++;                                                    //배열의 n값을 증가
        display();                                              //위의 display함수를 실행한다.
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {    //만약 마우스 오른쪽을 눌렀다 뗀다면
        
        glutIdleFunc(idleprocess);                              //회전을 시킨다
        rot_di = rot_di * -1;                                   //rot_di를 마이너스로 바꾸면서 한번더 우클릭을 했을떄 회전이 반대방향으로 실행된다.
    }
    
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {   //만약 마우스 휠을 눌렀다 뗀다면
        if (index > 8) {                                        //컬러팔레트의 순서가 8을 넘어가면
            index = 0;                                          //다시 첫번째로 돌아온다
        }
        Red = PALETTE[index][0] / 255.0f;                       //현재 인덱스의 순서에있는 색들을 
        Green = PALETTE[index][1] / 255.0f;
        Blue = PALETTE[index][2] / 255.0f;

        glColor3f(Red, Green, Blue);                            //현재 색깔로 지정해준다
        display();                                              //그리고 다시한번 디스플레이를 한다.
        index++;                                                //한번더 누르면 색깔이 계속 바뀌게 하기위해 인덱스를 늘려준다.
    }


}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void reshape(int new_w, int new_h)
{

    width = new_w;
    height = new_h;

    if (height == 0) height = 1;

    glViewport(0, 0, width, height);
    float  WidthFactor = (float)width / 250.0;
    float  HeightFactor = (float)height / 250.0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(1,1,0);
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("01 사각형 그리기 ");
    init();
   
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mousebutton);
    glutMainLoop();
    return 0;
}