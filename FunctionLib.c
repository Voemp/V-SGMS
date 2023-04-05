// Created by VoidEmpty on 2023/3/29.
#include "FunctionLib.h"

//函数功能：获取光标位置
COORD getCursor() {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hCon, &csbi);
    return csbi.dwCursorPosition;
}

//函数功能：设置光标位置
void setCursor(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD setps;
    setps.X = x;
    setps.Y = y;
    SetConsoleCursorPosition(hCon, setps);
}

//函数功能：设置窗口标题
VOID setTitle(LPCSTR lpTitle) {
    SetConsoleTitle(lpTitle);
}

//函数功能：设置窗口大小
void setWindowSize(int x, int y) {
    HWND hwnd = GetConsoleWindow();
    RECT rect;
    GetWindowRect(hwnd, &rect);
    MoveWindow(hwnd, rect.left, rect.top, x, y, TRUE);
}

//函数功能：打开网页
void openWeb(char *website) {
    ShellExecuteA(0, "open", website, 0, 0, 1);
}