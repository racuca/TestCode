#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c, z;
	int x1, x2, g;

	printf("판별식의 결과에 따라 실근,중근,허근을 알려줍니다.\n");

	printf(" ax^+bx+c=0\n");


	printf("상수 a를 입력하세요 : ");
	scanf("%f", &a);

	printf("상수 b를 입력하세요 : ");
	scanf("%f", &b);

	printf("상수 c를 입력하세요 : ");
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

		printf("두 실근을 갖습니다.두 실근은 %d, %d입니다\n", x1, x2);

		break;
	case'0':
		x1 = (-b + (sqrt(b * b - 4 * a * c)) / 2 * a);

		printf("중근을 갖습니다.중근은 %d 입니다 \n", x1);

		break;
	case'-1':
		printf("허근으로 계산이 불가능합니다.\n");

		break;
	}
}