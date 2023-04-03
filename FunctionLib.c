// Created by VoidEmpty on 2023/3/29.
#include "FunctionLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

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
VOID SetTitle(LPCSTR lpTitle) {
    SetConsoleTitle(lpTitle);
}

//函数功能：打开网页
void openWeb(char *website) {
    ShellExecuteA(0, "open", website, 0, 0, 1);
}