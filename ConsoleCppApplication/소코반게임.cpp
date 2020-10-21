
#define _WIN32_WINNT 0x0500

#include <stdio.h>
#include <WINDOWS.H>
//#include <cursor.h>
//#include <conio.h>
//#include <SDKDDKVer.h>

#define TRUE 1
#define FALSE 0

enum { ESC = 27, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 }; //열거형 요소에 아스키코드 값으로 키보드 입력에 대한 동작 값을 문자에 정의해준다.



#define putchxy(x, y, c) {gotoxy(x, y);putch(c);} //putchxy(x,y,c)의 형태가 나오면 x,y위치로 
//이동하여 c를 입력한다.
#define putsxy(x, y, s) {gotoxy(x, y);puts(s);} //putxy(x,y,s)의 형태가 나오면 x,y위치로 이동해서 
//s를 입력한다.



char arStage[][18][21] = { //0은 빈 공간, 1은 벽, 2는 짐, 3은 짐을 넣을 공간, 4는 짐을 옮기는 
//사람의 시작 위치로 첫 번째부터 세 번째까지 스테이지를 배열로 만들어 준다.


    {
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111000111111111111",
        "11111200111111111111",
        "11111002111111111111",
        "11100202011111111111",
        "11101011011111111111",
        "10001011011111003311",
        "10200200040000003311",
        "11111011101011003311",
        "11111000001111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
    },

    {
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11113300100000111111",
        "11113300102002001111",
        "11113300121111001111",
        "11113300004011001111",
        "11113300101002011111",
        "11111111101120201111",
        "11111102002020201111",
        "11111100001000001111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
    },

    {
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111110000041111",
        "11111111110212011111",
        "11111111110200211111",
        "11111111111202011111",
"11111111110201011111",
        "11333300110200200111",
        "11133300002002000111",
        "11333300111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111111111111111111",
    },
};
char ns[18][21]; //스테이지 크기가 가로 21, 세로 18의 크기를 가지므로 4의 짐을 움직이는 사람이 
//움직일 수 있는 최대 범위로 배열을 설정해준다. 
int nx, ny; //4의 짐을 움직이는 사람의 위치 값
const char* arTile[] = { "  ", "■", "⊙", "◇", "★" }; //스테이지의 숫자들을 순서대로 0은 "  ", 1은 "■", 2는 //"⊙", 3은 "◇", 4는 "★"로 바꾸어준다.

enum { EMPTY = 48, WALL, PACK, DEPOT, MAN }; //열거형 요소에 상수를 정해준다
int stage = 0;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

int main()
{
    int ch;
    int x, y;
    int dx, dy;
    BOOLEAN bEnd;
    ShowCursor(FALSE); //커서 숨기기
    // 전체 무한 루프
    for (;;) {
        // 게임판 초기화
        memcpy(ns, arStage[stage], sizeof(ns));
        for (y = 0; y < 18; y++) {
            for (x = 0; x < 20; x++) {
                // 짐을 옮기는 사람(4)의 위치 찾아 놓는다.
                if (ns[y][x] == MAN) {
                    nx = x;
                    ny = y;
                    ns[y][x] = EMPTY;
                }
            }
        }
        clrscr();
        putsxy(45, 2, "SOKOBAN"); //(45,2)위치에 "SOKOBAN" 문자열 출력
        putsxy(45, 4, "ESC:종료"); //(45,4)위치에 "ESC:종료" 문자열 출력
        putsxy(45, 6, "1, 2, 3:스테이지 이동"); //(45,6)위치에 "1,2,3: 스테이지 이동" 문자열 출력
        // 게임 진행 루프
        for (;;) {
            // 화면을 그린다.
            for (y = 0; y < 18; y++) {
                for (x = 0; x < 20; x++) {
                    putsxy(x * 2, y, arTile[ns[y][x] - '0']); //스테이지를 다 출력할 때까지 (x*2,y)
                                                              //위치에 arTile에 정해준 배열에 관한 요소를 출력한다.
                }
            }
            putsxy(nx * 2, ny, arTile[MAN - '0']); //짐을 옮기는 사람의 위치를 표현
            // 짐을 옮기는 사람(4) 이동
            ch = _getch();
            if (ch == 0xE0 || ch == 0) {
                ch = _getch();
                dx = dy = 0;
                switch (ch) {
                case LEFT:
                    dx = -1;
                    break;
                case RIGHT:
                    dx = 1;
                    break;
                case UP:
                    dy = -1;
                    break;
                case DOWN:
                    dy = 1;
                    break;
                }
                // 벽이 아니어야 한다.
                if (ns[ny + dy][nx + dx] != WALL) { //다음 위치가 벽이 아닐때
                 // 짐을 미는 경우
                    if (ns[ny + dy][nx + dx] == PACK) { //다음 위치가 짐일 때
                        // 그 다음 칸이 비어 있거나 창고여야 한다. 
                        if (ns[ny + dy * 2][nx + dx * 2] == EMPTY || // 다음 위치가 짐이고 다음다음위치가 빈공간이나 짐을 //넣는 곳일 때
                            ns[ny + dy * 2][nx + dx * 2] == DEPOT) {
                            if (arStage[stage][ny + dy][nx + dx] == DEPOT) {
                                ns[ny + dy][nx + dx] = DEPOT;
                            }
                            else {
                                ns[ny + dy][nx + dx] = EMPTY;
                            }
                            ns[ny + dy * 2][nx + dx * 2] = PACK; //다음다음 위치는 짐이다(짐을 옮긴다)
                        }
                        else {
                            dx = dy = 0;
                        }
                    }
                    // 새 위치로 이동
                    nx += dx;
                    ny += dy;
                }
            }
            else {
                if (ch == ESC) { //ESC를 누르면 커서를 드러내고 프로그램 종료
                    showcursor(TRUE);
                    return 0;
                }
                if (ch == '1') { //1을 입력받으면 arstage[0]의 스테이지로 이동
                    stage = 0;
                    break;
                }
                if (ch == '2') { //3을 입력받으면 arstage[2]의 스테이지로 이동
                    stage = 1;
                    break;
                }
                if (ch == '3') { //3을 입력받으면 arstage[2]의 스테이지로 이동
                    stage = 2;
                    break;
                }
            }
            // 게임 끝 처리
            bEnd = TRUE;
            for (y = 0; y < 18; y++) { //짐을 넣을 공간이 남아있으면 유지
                for (x = 0; x < 20; x++) {
                    if (ns[y][x] == DEPOT) {
                        bEnd = FALSE;
                    }
                }
            }
            if (bEnd) { //짐을 넣을 공간이 없으면 문구 출력 후 다음 스테이지로 이동 만약 3번째 스테이지(arStage[2]) 클리어 시 다시 1번째 스테이지(arStage[0])로 이동 
                clrscr();
                putsxy(10, 10, "참 잘했어요. 다음 스테이지로 이동합니다.");
                delay(2000);
                stage++;
                if (stage == 3) stage = 0;
                break;
            }
        }
    }
}