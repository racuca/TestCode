#include <stdio.h>
#include <string.h>
#include <memory.h>

int main() {

	char c[][10] = { "test", "test1" };
	char ccc[] = { "testesttest" };
	char test[5][5];
	char *cp[10];
	char *pointc[2] = { "point1", "point2" };
	char *s;

	int score[10];
	int *pscore;

	cp[0] = c[0];
	cp[1] = c[1];

	printf("%s %s\n", cp[0], cp[1]);

	pscore = score;
	*pscore = 10;
	*(pscore + 1) = 11;
	*(pscore + 2) = 12;

	printf("%d %d %d\n", score[0], score[1], score[2]);
	
	s = (char*)malloc(1000);

	getchar();

	return 0;
}