#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printhead();
int printscore(FILE *f);
int appendscore(FILE *f, int cnt);

int num;

struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
	int sum;
	double avg;
};
typedef struct personscore pscore;

void menu()
{
	printf("�Ʒ��� �޴��� ����ּ��� \n");
	printf("1. �Է� \n");
	printf("2. ��� \n");
	printf("3. ���� \n");
	printf("4. ���� \n");
	printf("0. ���� \n");
}

int appendscore(FILE *f, int cnt)
{
	pscore score = { 0 };
	char line[80];
	num = cnt;

	printf("�߰��� �̸��� ����(�߰�, �⸻, ����)�� �Է��ϼ���.\n\n");
	while (getchar() != '\n');
	fgets(line, 80, stdin);
	while (!feof(stdin)) {
		sscanf_s(line, "%s %d %d %d", score.name, 40, &score.mid, &score.final, &score.quiz);
		score.sum = score.mid + score.final + score.quiz;
		score.avg = (double)score.sum / 3;
		score.number = ++cnt;
		fwrite(&score, sizeof(pscore), 1, f);
		fgets(line, 80, stdin);
	}

	return cnt;
}

int ranking(pscore* st, int tmp)
{
	int rank = 1;
	int i;
	float sum;
	float sum1;
	extern num;

	for (i = 0; i < num; i++)
	{
		sum = (float)((*(st + i)).sum);
		sum1 = (float)((*(st + tmp)).sum);
		if (sum1 < sum)
		{
			rank++;
		}
	}
	return rank;
}

int printscore(FILE *f)
{
	int i = 0;
	rewind(f);
	pscore score;
	pscore* st = &score;

	int readcnt = fread(&score, sizeof(pscore), 1, f);
	if (readcnt == 0) {
		printf("����� ���� ������ �ϳ��� �����ϴ�. >>\n");
		return 0;
	}
	printhead();
	while (!feof(f)) {
		fprintf(stdout, "%6d%18s%8d%8d%8d%8d%8.1f%6d\n",
			score.number, score.name, score.mid, score.final, score.quiz, score.sum, score.avg, ranking(st, i));
		fread(&score, sizeof(pscore), 1, f);
	}
	fprintf(stdout, "%s\n", "  --------------------------------------------------------------------");

	return 1;
}
void printhead()
{
	printf("\n������ ���� ������ >>\n");
	fprintf(stdout, "%s\n", "  _____________________________________________________________________");
	fprintf(stdout, "%8s%15s%10s%8s%8s%8s%7s%7s\n", "��ȣ", "�̸�", "�߰�", "�⸻", "����", "�հ�", "���", "����");
	fprintf(stdout, "%s\n", "  ---------------------------------------------------------------------");
}



int main()
{
	char fname[] = "score.bin";
	FILE *f;
	int cnt = 0;
	long offset = 0;
	int selMenu;

	if ((f = fopen(fname, "ab+")) == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}

	int readcnt = printscore(f);
	if (readcnt == 1)
	{
		pscore score;
		offset = (long) sizeof(pscore);
		fseek(f, -offset, SEEK_END);
		fread(&score, sizeof(pscore), 1, f);
		cnt = score.number;
		printf("\n���� ������ ��ȣ�� %d�� �Դϴ�. \n\n", cnt);
	}
	fseek(f, 0L, SEEK_END);

	while (1)
	{
		menu();
		printf("�����ϼ��� >");
		scanf("%d", &selMenu);
		switch (selMenu)
		{
		case 1:
			cnt = appendscore(f, cnt);
			break;
		case 2:
			printscore(f);
			break;
		case 3:

			break;
		case 4:

			break;
		case 0:
			printf("���Ḧ �����ϼ̽��ϴ�.\n");
			return 0;
			break;
		}
	}
	fclose(f);
	return 0;
}

