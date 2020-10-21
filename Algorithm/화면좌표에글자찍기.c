#include <stdio.h>
#include <Windows.h>
void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
int main(void)
{
	gotoxy(0, 0);
	printf("(0, 0) 좌표에 출력했습니다.");
	gotoxy(40, 12);
	printf("(40, 12) 좌표에 출력했습니다.");
	gotoxy(0, 24);
	printf("가장 밑줄에 출력했습니다.");
}


