#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Initialization(char(*x)[12]); // �迭�� ��� 0 ���� �ʱ�ȭ���ִ� �Լ�.
void Randoma(int *x); // �������� ���ڸ� �ϳ� �����ϰ� ������ ���ڸ�ŭ �ߺ����� ���ڸ� �����ϴ� �Լ�
void Ladder(char(*x)[12], int y, int *z); //��ٸ��� �׷��ִ� �Լ�.
void Answer(char(*x)[12], int y); // ���� �迭�� �־��ִ� �Լ�.
void PrintLadder(char(*x)[12], int y); // ��ٸ��� ������ִ� �Լ�

int main()
{
	char l[21][12];//��ٸ� �迭 
	int input; // �Էµ� ��
	int random[10] = { 0, };// ������ ������ ����Ǵ� �迭

	srand(time(NULL));

	while (1)
	{
		printf("\n���ڸ� �Է��ϼ��� : ");
		scanf("%d", &input);
		if (input > 1 && input > 10)
		{
			printf("\n1 - 10 ���̰��� �Է°���\n");
		}
		else
		{
			Initialization(l); // �迭 �ʱ�ȭ
			Ladder(l, input, random); // ��ٸ� �ֱ�
			Answer(l, input); // �䱸�ϱ� 
			PrintLadder(l, input);// ����ϱ�
		}
	}
	return 0;
}
void Initialization(char(*x)[12])
{
	int i, j;

	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 12; j++)
		{
			x[i][j] = '\0';
		}
	}
}
void Ladder(char(*x)[12], int y, int *z)
{
	int i, j, l;
	for (i = 1; i < 11; i++)
	{
		for (j = 1; j < y * 2; j = j + 2)
		{
			x[j][i] = 5; // ��ٸ��� �׸���.
		}
	}

	j = 49;
	for (i = 1; i < y * 2; i = i + 2) // �� ���� ���ڸ� �ִ´�.
	{
		x[i][0] = j;
		j++;
	}
	x[19][0] = '1';
	x[20][0] = '0';

	for (l = 2; l < y * 2; l = l + 2) // input �� ũ�⿡ ���� �ݺ�Ƚ�� ����
	{
		Randoma(z); // ���� ����
		for (i = 1; i < 12; i++) // ��ٸ����� 11
		{
			for (j = 0; j < 10; j++) // ���� ���� 10��
			{
				if (i == z[j])// ������ ������ ��ٸ��� ��ġ �����Ѵ�.
				{
					x[l - 2][i] = 32;// �������� ��ٸ��� ������ �ʰ����ش�.
					x[l][i] = 6; //��ٸ� �ֱ�
				}
			}
		}
		for (i = 0; i < 10; i++) // ���� �迭�� �ʱ�ȭ�ϰ� �ٽ� ���� ����
		{
			z[i] = 0;
		}
	}
}

void Randoma(int *x)
{
	int r;
	int temp;
	int i, j;

	r = (rand() % 7) + 1; // ���� �ϳ� ����
	for (i = 0; i < r;) // ������ ������ ������ŭ ������ ����
	{
		temp = rand() % 10 + 1; // 1-10 ������ ������ �����Ѵ�
		for (j = 0; j < i; j++)
		{
			if (x[j] == temp)// ������ ������ ������ ������ ������ ������ ������.
			{
				break;
			}
		}
		if (i == j) // ������ ������ ������ �ٸ� ���� ����.
		{
			x[i++] = temp;
		}
	}
}
void Answer(char(*x)[12], int y)
{
	int m, n;
	int aw;
	int i, j;

	aw = 1;

	for (j = 1; j <= y; j++)
	{
		n = 1;
		m = (j * 2) - 1; //  j �������� ��ġ�ٲ�
		for (i = 0; i < 11; i++)
		{
			if (x[m - 1][n] == 6) // ���ʿ� ��ٸ��� ������ �������� ��ĭ �̵�
			{
				m = m - 2;
				n++;
			}
			else if (x[m + 1][n] == 6) // �����ʿ� ��ٸ��� ������ ���������� ��ĭ�̵�
			{
				m = m + 2;
				n++;
			}
			else // ��ٸ��� ������ �Ʒ��� �̵�
			{
				n++;
			}
		}
		x[m][11] = aw + 48; // 1�� �ƽ�Ű�ڵ� 49
		aw++;
	}

	for (i = 0; i < 22; i++) // 10�� �ֱ����� �ݺ���
	{
		if (x[i][11] == 58)
		{
			x[i][11] = 49;
			x[i + 1][11] = 48;
		}
	}
}

void PrintLadder(char(*x)[12], int y)
{
	int i, j;

	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < y * 2 + 1; j++)
		{
			printf("%c", x[j][i]); // ��ٸ� ���
		}
		printf("\n");
	}
}