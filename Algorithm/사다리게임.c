#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Initialization(char(*x)[12]); // 배열을 모두 0 으로 초기화해주는 함수.
void Randoma(int *x); // 랜덤으로 숫자를 하나 생성하고 생성된 숫자만큼 중복없이 숫자를 생성하는 함수
void Ladder(char(*x)[12], int y, int *z); //사다리를 그려주는 함수.
void Answer(char(*x)[12], int y); // 답을 배열에 넣어주는 함수.
void PrintLadder(char(*x)[12], int y); // 사다리를 출력해주는 함수

int main()
{
	char l[21][12];//사다리 배열 
	int input; // 입력된 값
	int random[10] = { 0, };// 생성한 난수가 저장되는 배열

	srand(time(NULL));

	while (1)
	{
		printf("\n숫자를 입력하세요 : ");
		scanf("%d", &input);
		if (input > 1 && input > 10)
		{
			printf("\n1 - 10 사이값만 입력가능\n");
		}
		else
		{
			Initialization(l); // 배열 초기화
			Ladder(l, input, random); // 사다리 넣기
			Answer(l, input); // 답구하기 
			PrintLadder(l, input);// 출력하기
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
			x[j][i] = 5; // 사다리를 그린다.
		}
	}

	j = 49;
	for (i = 1; i < y * 2; i = i + 2) // 맨 위에 숫자를 넣는다.
	{
		x[i][0] = j;
		j++;
	}
	x[19][0] = '1';
	x[20][0] = '0';

	for (l = 2; l < y * 2; l = l + 2) // input 의 크기에 따라 반복횟수 결정
	{
		Randoma(z); // 난수 생성
		for (i = 1; i < 12; i++) // 사다리높이 11
		{
			for (j = 0; j < 10; j++) // 난수 갯수 10개
			{
				if (i == z[j])// 생성된 난수로 사다리의 위치 결정한다.
				{
					x[l - 2][i] = 32;// 같은높이 사다리가 생기지 않게해준다.
					x[l][i] = 6; //사다리 넣기
				}
			}
		}
		for (i = 0; i < 10; i++) // 난수 배열을 초기화하고 다시 난수 생성
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

	r = (rand() % 7) + 1; // 난수 하나 생성
	for (i = 0; i < r;) // 생성된 난수의 갯수만큼 난수를 생성
	{
		temp = rand() % 10 + 1; // 1-10 사이의 난수를 생성한다
		for (j = 0; j < i; j++)
		{
			if (x[j] == temp)// 생성된 난수가 이전에 생성된 난수와 같으면 버린다.
			{
				break;
			}
		}
		if (i == j) // 이전에 생성된 난수와 다른 수만 저장.
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
		m = (j * 2) - 1; //  j 값에따라 위치바뀜
		for (i = 0; i < 11; i++)
		{
			if (x[m - 1][n] == 6) // 왼쪽에 사다리가 있으면 왼쪽으로 두칸 이동
			{
				m = m - 2;
				n++;
			}
			else if (x[m + 1][n] == 6) // 오른쪽에 사다리가 있으면 오른쪽으로 두칸이동
			{
				m = m + 2;
				n++;
			}
			else // 사다리가 없으면 아래로 이동
			{
				n++;
			}
		}
		x[m][11] = aw + 48; // 1은 아스키코드 49
		aw++;
	}

	for (i = 0; i < 22; i++) // 10을 넣기위한 반복문
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
			printf("%c", x[j][i]); // 사다리 출력
		}
		printf("\n");
	}
}