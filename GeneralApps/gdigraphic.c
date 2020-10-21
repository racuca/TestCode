#include <stdio.h>
#include <windows.h>

int main(void)
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
	int x = 30, y = 100, i = 0;
	char command;

	Rectangle(hdc, 10, 10, 810, 810);
	Rectangle(hdc, x, y, x + 50, y + 50);
	do {
		printf("명령어를 입력하시오(l or r or t or d, 종료 :q)");
		command = getchar();

		if (command == 'l') {
			while (i < 10) {
				system("cls");
				Rectangle(hdc, x, y, x + 50, y + 50);
				i++;
				x -= 50;
			}
		}
		else if (command == 'r') {
			while (i < 10) {
				system("cls");
				Rectangle(hdc, x, y, x + 50, y + 50);
				i++;
				x += 50;
			}


		}
		else if (command == 't') {
			while (i < 10) {
				system("cls");
				Rectangle(hdc, x, y, x + 50, y + 50);
				i++;
				y -= 50;
			}

		}
		else if (command == 'd') {
			while (i < 10) {
				system("cls");
				Rectangle(hdc, x, y, x + 50, y + 50);
				i++;
				y += 50;
			}

		}
		else if (command == 'q') {
			exit(0);
		}
		else {
			printf("잘못된 명렁어입니다.");
		}
	} while (command != 'q');
	return 0;
}