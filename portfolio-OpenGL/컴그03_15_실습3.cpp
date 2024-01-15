#include <GL/glut.h>
#include <stdlib.h>

//��ǻ�ͼ���Ʈ������а�
//20184045_���μ�

void display(void)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);            //��, ��, ����� �׸��� ���� ���.
	glVertex3f(-0.75, -0.75, 0.0);
	glVertex3f(0.75, -0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(-0.75, 0.75, 0.0);
	glEnd();
	glFlush(); //�簢���� ȭ�鿡 �׸�
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	float WidthFactor = (float)new_w / 250.0;
	float HeightFactor = (float)new_h / 250.0;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho2D(-1.0 * WidthFactor,1.0 * WidthFactor, -1.0 * HeightFactor, 1.0* HeightFactor);
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //���������� ���������� ����. �������� ����� ���ﶧ ���� ������ ����. 4���� �μ��� RGBA�� ���� ����� ������ ���� (0~1);
	glClear(GL_COLOR_BUFFER_BIT); //������۸� ���, �μ��� � ���۸� ������ ����.
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut ���¸� �ʱ�ȭ GLUT���̺귯���� �ʱ�ȭ�ϰ� ������� �����Ͽ� �ϳ��� ��������. � glut �Լ����� ���� ����Ǿ����.
	//���÷��̸������ ����: Single buffer & RGBA color ��� ����.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//â�� ũ��� ��ġ ����
	glutInitWindowSize(550, 550); //�׷����� ����� �������� ũ�⸦ ����
	glutInitWindowPosition(100, 100); //ȭ�� �»���� �������� �Ͽ� x,y ��ġ�� �������� �»���� ��ġ ��Ŵ


	glutCreateWindow("01 �簢�� �׸��� "); //������ ����, ������ ����� ������ ���ڿ��� �μ��� ����. glutmainLoop()�� ȣ���Ǳ� �������� �����찡 ���÷��̵��� ����.
	init();

	//�ʿ��� �Լ� ���
	glutDisplayFunc(display); //�ݹ��Լ�
	glReshapeFunc(reshape);
	glutMainLoop(); //�̺�Ʈ ó������ ����, ���� �̺�Ʈó�� ����. �̺�Ʈ�� �߻��ϸ� ��ġ�ϴ� �ݹ��Լ��� ��ϵǾ� �������, ��ϵ��Լ��� �ڵ����� ȣ��.
	return 0;
}