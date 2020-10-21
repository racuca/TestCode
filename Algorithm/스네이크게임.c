#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<conio.h>

#include<windows.h>

#include<time.h>

typedef struct

{

	int x, y;

}POS;

void gotoxy(int x, int y, char* s)

{

	COORD Pos = { x * 2,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	printf("%s", s);

}

void draw_screen()  ///처음 맵 테두리 그리기

{

	int i;

	system("cls");

	gotoxy(0, 0, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	for (i = 1; i < 20; i++)

	{

		gotoxy(0, i, "■");

		gotoxy(30, i, "■");

	}

	gotoxy(0, 20, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

}

void move_snake(POS* snake, int len)///뱀이 움직이는 부분

{

	static int dir = -1;

	if (_kbhit())///입력부분

	{

		int key;

		do { key = _getch(); } while (key == 224);

		switch (key)

		{

		case 72: dir = 0; break;//위

		case 80: dir = 1; break;//아레

		case 75: dir = 2; break;//왼쪽

		case 77: dir = 3; break;//오른쪽

		}

	}

	if (dir != -1)

	{

		int i;

		gotoxy(snake[len - 1].x, snake[len - 1].y, "  ");

		for (i = len - 1; i > 0; i--)snake[i] = snake[i - 1];

		gotoxy(snake[1].x, snake[1].y, "○");

	}

	switch (dir)

	{

	case 0: snake[0].y--;; break;//위

	case 1: snake[0].y++; break;//아레

	case 2: snake[0].x--; break;//왼쪽

	case 3: snake[0].x++; break;//오른쪽

	}

	gotoxy(snake[0].x, snake[0].y, "●");

}

int check_snake(POS* snake, int len)///뱀이 충돌했는지 확인하는 부분

{

	int i;

	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == 30 || snake[0].y == 20)return 0;

	for (i = 1; i < len; i++)

	{

		if (snake[0].x == snake[i].x&&snake[0].y == snake[i].y)return 0;

	}

	return 1;

}

int main()

{

	POS snake[100], item;

	int i, dir = -1, len = 5, score = 0;

	int speed = 150;

	srand(time(NULL));

	draw_screen();

	for (i = 0; i < len; i++)

	{

		snake[i].x = 15 + i;

		snake[i].y = 10;

		gotoxy(snake[i].x, snake[i].y, "○");

	}

	item.x = rand() % 28 + 1;

	item.y = rand() % 18 + 1;

	gotoxy(1, 21, "Score : 0");

	while (1)

	{

		if (check_snake(snake, len) == 0)

			break;

		if (snake[0].x == item.x&&snake[0].y == item.y)///아이템 먹었을 경우

		{

			score += 10;

			item.x = rand() % 28 + 1;

			item.y = rand() % 18 + 1;

			gotoxy(1, 21, "Score : ");

			printf("%d", score);

			if (speed > 10)speed -= 5;

			if (len < 100)

			{

				snake[len] = snake[len - 1];

				len++;

			}

		}

		gotoxy(item.x, item.y, "º");

		move_snake(snake, len);

		Sleep(speed);

	}

	gotoxy(0, 22, "Game Over\n");

	system("pause");

}