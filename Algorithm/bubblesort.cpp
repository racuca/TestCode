#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATACOUNT 50

int main() {
	time_t t;
	int buffer[DATACOUNT];
	srand(time(&t));
	puts("���� �� ����Ʈ : ");
	for (int i = 0; i < DATACOUNT; i++) {
		buffer[i] = rand() % 99;
		printf("%d ", buffer[i]);
	}
	printf("\n");
	// ���� ���� �˰���
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
	puts("���� �� ����Ʈ : ");
	for (int i = 0; i < DATACOUNT; i++) {
		printf("%d ", buffer[i]);
	}
	printf("\n");
	printf("��ȸ�� : %d\n", comparecount);
	getchar();
}