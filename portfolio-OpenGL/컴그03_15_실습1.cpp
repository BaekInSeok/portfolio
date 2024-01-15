#include <GL/glut.h>
#include <stdlib.h>

//��ǻ�ͼ���Ʈ������а�
//20184045_���μ�

void display(void)
{
	glColor3f(1.0, 1.0, 1.0); //������� ����

	//�簢���� ��ǥ�Է�
	glBegin(GL_POLYGON);            //��, ��, ����� �׸��� ���� ���.
		glVertex3f(0.25, 0.25, 0.0); //������ xyz ��ǥ ���� 
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	glFlush(); //�簢���� ȭ�鿡 �׸�
}

void init(void)
{
	glClearColor( 0.0, 0.0, 0.0, 0.0); //���������� ���������� ����. �������� ����� ���ﶧ ���� ������ ����. 4���� �μ��� RGBA�� ���� ����� ������ ���� (0~1);
	glClear(GL_COLOR_BUFFER_BIT); //������۸� ���, �μ��� � ���۸� ������ ����.
	glMatrixMode(GL_PROJECTION); //����� ��ĸ�带 ����.
	glLoadIdentity(); //�������

	//��������
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); //���������� ���� ��������, �ְ� ������� ǥ�� �Ұ�.
	}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut ���¸� �ʱ�ȭ GLUT���̺귯���� �ʱ�ȭ�ϰ� ������� �����Ͽ� �ϳ��� ��������. � glut �Լ����� ���� ����Ǿ����.
	//���÷��̸������ ����: Single buffer & RGBA color ��� ����.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//â�� ũ��� ��ġ ����
	glutInitWindowSize(250, 250); //�׷����� ����� �������� ũ�⸦ ����
	glutInitWindowPosition(100, 100); //ȭ�� �»���� �������� �Ͽ� x,y ��ġ�� �������� �»���� ��ġ ��Ŵ


	glutCreateWindow("01 �簢�� �׸��� "); //������ ����, ������ ����� ������ ���ڿ��� �μ��� ����. glutmainLoop()�� ȣ���Ǳ� �������� �����찡 ���÷��̵��� ����.
	init();

	//�ʿ��� �Լ� ���
	glutDisplayFunc(display); //�ݹ��Լ�
	glutMainLoop(); //�̺�Ʈ ó������ ����, ���� �̺�Ʈó�� ����. �̺�Ʈ�� �߻��ϸ� ��ġ�ϴ� �ݹ��Լ��� ��ϵǾ� �������, ��ϵ��Լ��� �ڵ����� ȣ��.
	return 0;
	}