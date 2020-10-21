#include<stdio.h>
#include <stdlib.h>

int main(void)
{
	char array[] = { 'a', 'b', 'c', 'd', '\0' };
	char array1[] = { 'A', 'B' ,'C', 'D', 'E' };

	int arraylen = strlen(array);
	int array1len = strlen(array1);

	printf("%d %d %s\n", arraylen, sizeof(array), array);
	printf("%d %d %s\n", array1len, sizeof(array), array1);


	return 0;
}