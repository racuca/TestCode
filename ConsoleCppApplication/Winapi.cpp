#include <windows.h>
#include <tchar.h>
#include <stdio.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
    WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine, int nCmdShow)


{
    //2,������ Ŭ���� ����ü ���� �ۼ�(������ �������� ������ ����)
    HWND   hwnd;
    MSG   msg;
    WNDCLASS WndClass;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;   //������ ��Ÿ��(�������� ũ�Ⱑ ���Ҷ� �ٽ� ��ο�)
    WndClass.lpfnWndProc = WndProc; //�ݹ� ���ν��� �Լ� ������
    WndClass.cbClsExtra = 0;    //�����찡 ���������� ��� �� ������ �޸�(������� �ʴ´� ���� 0)
    WndClass.cbWndExtra = 0;    //�����찡 ���������� ��� �� ������ �޸�(������� �ʴ´� ���� 0)
    WndClass.hInstance = hInstance; //������ �ν��Ͻ�
    WndClass.hIcon = LoadIcon(NULL, IDI_QUESTION);   //������
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);     //Ŀ��
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   //����
    WndClass.lpszMenuName = NULL;   //�޴� �̸�(������ NULL)
    WndClass.lpszClassName = L"Window Class Name";   //Ŭ���� �̸�
    //�� ���� ����ü


    //3.Ŭ������ ����Ѵ�(�տ��� ������ ������ Ŭ������ ����Ѵ�)
    RegisterClass(&WndClass);   //����ü�� �ּ�(&WndClass)
    //4.��ϵ� ������ Ŭ���� ������ �����츦 �����Ѵ�.
    //���ÿ� ������ ������ �ڵ��� ����Ѵ�.
    hwnd = CreateWindow(_T("Window Class Name"),   //������ Ŭ���� �̸�
        _T("�������� ù ��° ������"),   //������ Ÿ��Ʋ �̸�
        WS_OVERLAPPEDWINDOW,    //������ ��Ÿ��
        100,  //������ ��ġ,x��ǥ
        100,  //������ ��ġ,y��ǥ
        1280,  //������ ��
        840,  //������ ����
        NULL,   //�θ� ������ �ڵ�
        NULL,   //�޴� �ڵ�
        hInstance,  //���� ���α׷� ID
        NULL    //������ ������ ����
    );
    //5.������ �����츦 ȭ�鿡 ����.
    ShowWindow(hwnd, nCmdShow); //�������� ȭ�� ���


    UpdateWindow(hwnd); //OS�� WM_PAINT �޽��� ����
    //7.�޽��� ����
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
        DrawText(hdc, _T("����"), 2, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if (bottomvkdown)
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(hdc, 120, 170, 200, 300);
        rect.left = 120; rect.top = 170; rect.right = 200; rect.bottom = 300;
        DrawText(hdc, _T("�Ʒ���"), 3, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        if (leftvkdown)
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(hdc, 0, 100, 120, 170);
        rect.left = 0; rect.top = 100; rect.right = 120; rect.bottom = 170;
        DrawText(hdc, _T("����"), 2, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        if (rightvkdown)
            SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 0)));
        Rectangle(hdc, 200, 100, 320, 170);
        rect.left = 200; rect.top = 100; rect.right = 320; rect.bottom = 170;
        DrawText(hdc, _T("������"), 3, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

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