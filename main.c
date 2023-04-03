#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Init.h"
#include "LoginSystem.h"
#include "struct.h"


int main() {
    SetTitle("V-SGMS 1.0");
    system("color f9");
    //welcomeInit();
    int choice;
    do {
        mainMenu();
        choice = menuController(3, 3, 3, 8, coverMainMenu);
        switch (choice) {
            case 0:
                printf("这是个小彩蛋，嘻嘻！");
                Sleep(500);
                break;
            case 1:
                printf("1");
                break;
            case 2:
                printf("2");
                break;
            case 3:
                printf("3");
                break;
            case 4:
                printf("4");
                break;
            case 5:
                printf("5");
                break;
            case 6:
                About();
                choice = 0;
                break;
            default:
                printf("没有这个选项！");
                Sleep(300);
                break;
        }
    } while (choice < 1 || choice > 6);
    //USER *temp_user = (USER *) malloc(sizeof(USER));
    //loginMod(temp_user, 6, 3);
    system("pause");
    return 0;
}
