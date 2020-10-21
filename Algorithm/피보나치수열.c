#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 피보나치 수열 구현
// 수열의 구할 개수를 

void Fibonacci(int);

void Fibonacci(int num, int* p, int order)
{
	if (order > num)
		return;

	int fn_1 = *(p - 1);
	int fn_2 = *(p - 2);

	*p = fn_1 + fn_2;

	Fibonacci(num, (p + 1), order + 1);
}

int main(void)
{
	int num = 0;

	printf("수열의 개수를 입력하세요 : ");
	scanf("%d", &num);

	int* p = (int*)malloc(sizeof(int) * num);

	*p = 1;
	*(p + 1) = 1;

	Fibonacci(num, (p + 2), 2);

	for (int i = 0; i < num; i++) {
		printf("%d ", *(p + i));
	}

}

