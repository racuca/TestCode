#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_LINE 80
#define MAX_STR 3
int main()
{
	int i;
	char colors[MAX_STR][MAX_LINE] = { "red", "blue", "white" };
	char color[MAX_LINE] = "red";
	char* ptr[MAX_STR];
	char c = 'c';
	char* p = &c;
	char (*wholeptr)[MAX_STR];

	//printf("%s %s\n", colors[0], &colors[0]);
	//printf("%p %p\n", color, &color);

	for (i = 0; i < MAX_STR; i++)
	{
		ptr[i] = colors[i];
		printf("%p ", ptr[i]);
	}
	printf("\n");
	for (i = 0; i < MAX_STR; i++)
	{
		wholeptr = &colors[i];
		printf("%p ", wholeptr[i]);
	}
	printf("\n");



	for (i = 0; i < MAX_STR; i++)
	{
		ptr[i] = &colors[i];
		printf("%p ", ptr[i]);
	}
	printf("\n");

	for (i = 0; i < MAX_STR; i++)
		printf("%s ", &colors[i][0]);
	printf("\n");
	for (i = 0; i < MAX_STR; i++)
		printf("%s ", colors[i]);
	printf("\n");

	for (i = 0; i < MAX_STR; i++)
		printf("%s ", ptr[i]);

	return 0;
}