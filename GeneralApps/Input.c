#include <stdio.h>



int get_result(int x, int y, char z)
{
	if (z == '+') return (x + y);
	else if (z == '-') return (x - y);
}

int main(void)
{
	int x, y, result;
	char z;
	printf("정수를 입력하시오:");
	scanf_s("%d", &x);
	printf("정수를 입력하시오:");
	scanf_s("%10d", &y);

	char remaining = getchar();

	printf("기호를 입력하시오:");
	scanf_s("%*c%c", &z, 1);

	result = get_result(x, y, z);
	printf("%d", result);
	return 0;

}
