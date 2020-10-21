#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATACOUNT 50

int main() {
	time_t t;
	int buffer[DATACOUNT];
	srand(time(&t));
	puts("정렬 전 리스트 : ");
	for (int i = 0; i < DATACOUNT; i++) {
		buffer[i] = rand() % 99;
		printf("%d ", buffer[i]);
	}
	printf("\n");
	// 버블 정렬 알고리즘
	int lastpos = DATACOUNT;
	int comparecount = 0;
	for (int k = 0; k < DATACOUNT; k++)
	{
		for (int i = 0; i < lastpos - 1; i++)
		{
			comparecount++;
			if (buffer[i] > buffer[i + 1]) {
				int temp = buffer[i];
				buffer[i] = buffer[i + 1];
				buffer[i + 1] = temp;
			}
		}
		lastpos--;
	}
	puts("정렬 후 리스트 : ");
	for (int i = 0; i < DATACOUNT; i++) {
		printf("%d ", buffer[i]);
	}
	printf("\n");
	printf("비교회수 : %d\n", comparecount);
	getchar();
}