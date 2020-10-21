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
	printf("배열 요소의 개수: ");
	scanf("%d", &gesu);
	printf("배열 요소를 입력하라.\n");
	for (i = 0; i < 3; i++)
		scanf("%d", &yoso[i]);
	printf("삽입 위치: ");
	scanf("%d", &w); //w=0 
	printf("삽입 값: ");
	scanf("%d", &gap); //gap=9
	printf("결과 배열\n");
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