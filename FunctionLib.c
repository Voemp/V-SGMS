// Created by VoidEmpty on 2023/3/29.
#include "FunctionLib.h"

//�������ܣ���ȡ���λ��
COORD getCursor() {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hCon, &csbi);
    return csbi.dwCursorPosition;
}

//�������ܣ����ù��λ��
void setCursor(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD setps;
    setps.X = x;
    setps.Y = y;
    SetConsoleCursorPosition(hCon, setps);
}

//�������ܣ����ô��ڱ���
VOID setTitle(LPCSTR lpTitle) {
    SetConsoleTitle(lpTitle);
}

//�������ܣ����ô��ڴ�С
void setWindowSize(int x, int y) {
    HWND hwnd = GetConsoleWindow();
    RECT rect;
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, rect.left, rect.top, x, y, TRUE);
}

//�������ܣ�����ҳ
void openWeb(char *website) {
    ShellExecuteA(0, "open", website, 0, 0, 1);
}