#include <windows.h>
#include <tchar.h>
#include <stdio.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
    WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine, int nCmdShow)


{
    //2,윈도우 클래스 구조체 정보 작성(생성될 윈도우의 정보를 설정)
    HWND   hwnd;
    MSG   msg;
    WNDCLASS WndClass;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;   //윈도우 스타일(윈도우의 크기가 변할때 다시 드로우)
    WndClass.lpfnWndProc = WndProc; //콜백 프로시져 함수 포인터
    WndClass.cbClsExtra = 0;    //윈도우가 내부적으로 사용 할 여분의 메모리(사용하지 않는다 보통 0)
    WndClass.cbWndExtra = 0;    //윈도우가 내부적으로 사용 할 여분의 메모리(사용하지 않는다 보통 0)
    WndClass.hInstance = hInstance; //윈도우 인스턴스
    WndClass.hIcon = LoadIcon(NULL, IDI_QUESTION);   //아이콘
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);     //커서
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   //배경색
    WndClass.lpszMenuName = NULL;   //메뉴 이름(없으면 NULL)
    WndClass.lpszClassName = L"Window Class Name";   //클래스 이름
    //위 까지 구조체


    //3.클래스를 등록한다(앞에서 정의한 윈도우 클래스를 등록한다)
    RegisterClass(&WndClass);   //구조체의 주소(&WndClass)
    //4.등록된 윈도우 클래스 정보로 윈도우를 생성한다.
    //동시에 생성된 윈도우 핸들을 기억한다.
    hwnd = CreateWindow(_T("Window Class Name"),   //윈도우 클래스 이름
        _T("최지흠의 첫 번째 윈도우"),   //윈도우 타이틀 이름
        WS_OVERLAPPEDWINDOW,    //윈도우 스타일
        100,  //윈도우 위치,x좌표
        100,  //윈도우 위치,y좌표
        1280,  //윈도우 폭
        840,  //윈도우 높이
        NULL,   //부모 윈도우 핸들
        NULL,   //메뉴 핸들
        hInstance,  //응용 프로그램 ID
        NULL    //생성된 윈도우 정보
    );
    //5.생성된 윈도우를 화면에 띄운다.
    ShowWindow(hwnd, nCmdShow); //윈도우의 화면 출력


    UpdateWindow(hwnd); //OS에 WM_PAINT 메시지 전송
    //7.메시지 루프
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
    WPARAM wParam, LPARAM lParam)

{
    HDC hdc;
    PAINTSTRUCT ps;
    static TCHAR str[100];
    static int count;
    static SIZE size;
    RECT rect;
    HPEN hPen, oldPen;
    static BOOL rightvkdown, leftvkdown, topvkdown, bottomvkdown;
    switch (iMsg)
    {
    case WM_CREATE:
        rightvkdown = FALSE;
        leftvkdown = FALSE;
        bottomvkdown = FALSE;
        topvkdown = FALSE;
        break;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);


        if (topvkdown)
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(hdc, 120, 0, 200, 100);
        rect.left = 120; rect.top = 0; rect.right = 200; rect.bottom = 100;
        DrawText(hdc, _T("위쪽"), 2, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if (bottomvkdown)
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(hdc, 120, 170, 200, 300);
        rect.left = 120; rect.top = 170; rect.right = 200; rect.bottom = 300;
        DrawText(hdc, _T("아래쪽"), 3, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if (leftvkdown)
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(hdc, 0, 100, 120, 170);
        rect.left = 0; rect.top = 100; rect.right = 120; rect.bottom = 170;
        DrawText(hdc, _T("왼쪽"), 2, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        if (rightvkdown)
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(hdc, 200, 100, 320, 170);
        rect.left = 200; rect.top = 100; rect.right = 320; rect.bottom = 170;
        DrawText(hdc, _T("오른쪽"), 3, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        EndPaint(hwnd, &ps);

        break;

    case WM_KEYUP:
        rightvkdown = FALSE;
        leftvkdown = FALSE;
        bottomvkdown = FALSE;
        topvkdown = FALSE;

        break;
    case WM_KEYDOWN:
        if (wParam == VK_RIGHT) {
            rightvkdown = true;
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
        if (wParam == VK_LEFT) {
            leftvkdown = true;
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
        if (wParam == VK_UP) {
            topvkdown = true;
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
        if (wParam == VK_DOWN) {
            bottomvkdown = true;
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
        break;
    case WM_DESTROY:

        PostQuitMessage(0);
        break;

    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}