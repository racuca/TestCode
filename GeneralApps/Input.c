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
	printf("������ �Է��Ͻÿ�:");
	scanf_s("%d", &x);
	printf("������ �Է��Ͻÿ�:");
	scanf_s("%10d", &y);

	char remaining = getchar();

	printf("��ȣ�� �Է��Ͻÿ�:");
	scanf_s("%*c%c", &z, 1);

	result = get_result(x, y, z);
	printf("%d", result);
	return 0;

}
