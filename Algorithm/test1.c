#include "stdio.h"

int main() {

	int a = 10;
	char c = 'a';
	short s = -250;

	char array1[10] = "Hello1!";
	char array2[10] = {"Hello2!"};
	char array3[] = {"Test"};
	char array4[10] = { "" };

	printf("%d %c %d\n", a, c, s);
	printf("%s -  %s -  %s\n", array1, array2, array3);
	printf("%d,%d,%d,%d\n", strlen(array1), strlen(array2), strlen(array3), strlen(array4));
	printf("%d,%d,%d,%d\n", sizeof(array1), sizeof(array2), sizeof(array3), sizeof(array4));
	getch();

	return 0;

}