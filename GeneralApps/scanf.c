#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c, z;
	int x1, x2, g;

	printf("�Ǻ����� ����� ���� �Ǳ�,�߱�,����� �˷��ݴϴ�.\n");

	printf(" ax^+bx+c=0\n");


	printf("��� a�� �Է��ϼ��� : ");
	scanf("%f", &a);

	printf("��� b�� �Է��ϼ��� : ");
	scanf("%f", &b);

	printf("��� c�� �Է��ϼ��� : ");
	scanf("%f", &c);

	z = b * b - 4 * a * c;

	if (z > 0) g = 1;
	if (z == 0) g = 0;
	if (z < 0) g = -1;

	switch (g)
	{
	case'1':

		x1 = (-b + (sqrt(b * b - 4 * a * c)) / 2 * a);
		x2 = (-b + (sqrt(b * b - 4 * a * c)) / 2 * a);

		printf("�� �Ǳ��� �����ϴ�.�� �Ǳ��� %d, %d�Դϴ�\n", x1, x2);

		break;
	case'0':
		x1 = (-b + (sqrt(b * b - 4 * a * c)) / 2 * a);

		printf("�߱��� �����ϴ�.�߱��� %d �Դϴ� \n", x1);

		break;
	case'-1':
		printf("������� ����� �Ұ����մϴ�.\n");

		break;
	}
}