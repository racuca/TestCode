#include <stdio.h>

int main()
{
	char str[100];
	char ch;

	int i, k;
	int star;

	printf("���ڸ� ���� �� �Է� : ");
	scanf_s("%s", str);

	i = 0;
	ch = str[i];
	int len = strlen(str);
	while (ch != '\0') {
		star = (int)ch - 48;

		for (k = 0; k < star; k++)
			printf("*");

		printf("\n");

    	i = i + 1;
		if (i >= len)
			break;

		ch = str[i];
	}
	return 0;

}