#define _CRT_SECURE_WARNINGS
#include<stdio.h>


int main()
{
	int i;
	int gesu;
	int yoso[3];
	int f[4];
	int w;
	int gap;
	printf("�迭 ����� ����: ");
	scanf("%d", &gesu);
	printf("�迭 ��Ҹ� �Է��϶�.\n");
	for (i = 0; i < 3; i++)
		scanf("%d", &yoso[i]);
	printf("���� ��ġ: ");
	scanf("%d", &w); //w=0 
	printf("���� ��: ");
	scanf("%d", &gap); //gap=9
	printf("��� �迭\n");
	for (i = 1; i < 4; i++)
	{
		if (i < w)
		{
			f[i] = yoso[i];
		}
		else if (i > w)
			f[i] = yoso[i - 1];
	}
	f[w] = gap;

	for (i = 0; i < 4; i++)
		printf("%d\n", f[i]);


	return 0;
}