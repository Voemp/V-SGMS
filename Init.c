// Created by VoidEmpty on 2023/3/29.
#include "Init.h"

//函数功能：打印欢迎界面
void welcomeInit() {
    system("cls");
    printf("****************************************************\n");
    printf(" VV        VV          SSSS    GGGG   M   M   SSSS  \n");
    printf(" VV       VV          S       G    G  MM MM  S      \n");
    printf(" VV      VV           S       G       MM MM  S      \n");
    printf(" VV     VV     =====   SSSS   G       M M M   SSSS  \n");
    printf(" VV    VV                  S  G   GG  M   M       S \n");
    printf(" VV   VV                   S  G    G  M   M       S \n");
    printf("  VVV                  SSSS    GGGG   M   M   SSSS  \n");
    printf("****************************************************\n");
    printf("          欢迎使用V-SIMS学生成绩管理系统！           \n");
    printf("****************************************************\n");
    printf("               作者：VoidEmpty\n");
    printf("****************************************************\n");
    IN_CYANWORD;
    printf("程序正在加载中[□□□□□□□□□□]0%\r");
    Sleep(300);
    printf("程序正在加载中[■■□□□□□□□□]20%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■□□□□□□]40%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■■■□□□□]60%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■■■■■□□]80%\r");
    Sleep(300);
    printf("程序正在加载中[■■■■■■■■■■]100%\n");
    Sleep(300);
    printf("程序加载完成！\n");
    IN_WHITE;
    Sleep(400);
}

//登录界面
char *loginMenu[7] = {"********************************\0",
                      "*           登录系统           *\0",
                      "********************************\0",
                      "*        1.登录已有帐号        *\0",
                      "*        2.注册新的帐号        *\0",
                      "*        3.退出程序            *\0",
                      "********************************\0"};

//主菜单
char *mainMenu[10] = {"********************************\0",
                      "*           主菜单             *\0",
                      "********************************\0",
                      "*        1.学生成绩查询        *\0",
                      "*        2.学生成绩管理        *\0",
                      "*        3.修改密码            *\0",
                      "*        4.退出登录            *\0",
                      "*        5.退出程序            *\0",
                      "*        6.关于                *\0",
                      "********************************\0"};

//学生成绩查询菜单（教师版）
char *studentGradeQueryMenu1[12] = {"******************************************************\0",
                                    "*                学生成绩查询（教师版）              *\0",
                                    "******************************************************\0",
                                    "*        1.查询每门课程的总分和平均分                *\0",
                                    "*        2.按照每个学生的总分由高到低排出名次表      *\0",
                                    "*        3.按照每个学生的总分由低到高排出名次表      *\0",
                                    "*        4.按照学号由小到大排出成绩表                *\0",
                                    "*        5.按照学号查询学生排名及其各科考试成绩      *\0",
                                    "*        6.统计不同分数段的人数百分比                *\0",
                                    "*        7.输出每个学生全部信息                      *\0",
                                    "*        8.返回主菜单                                *\0",
                                    "******************************************************\0"};


//学生成绩管理菜单（教师版）
char *studentGradeManageMenu1[8] = {"*********************************\0",
                                    "*     学生成绩管理（教师版）    *\0",
                                    "*********************************\0",
                                    "*       1.添加学生成绩          *\0",
                                    "*       2.修改学生成绩          *\0",
                                    "*       3.删除学生成绩          *\0",
                                    "*       4.返回主菜单            *\0",
                                    "*********************************\0"};

//退出程序确认界面
char *exitConfirmMenu[6] = {"********************************\0",
                            "*           退出程序           *\0",
                            "********************************\0",
                            "*        1.确认退出程序        *\0",
                            "*        2.返回上一级          *\0",
                            "********************************\0"};

//函数功能：关于界面
void About() {
    system("cls");
    printf("********************************************\n");
    printf("*                   关于                   *\n");
    printf("********************************************\n");
    printf("*    Void-StudentGradeManagementSystem     *\n");
    printf("********************************************\n");
    printf("*             作者：VoidEmpty              *\n");
    printf("*             版本：1.0                    *\n");
    printf("*             日期：2023.04.01             *\n");
    printf("*             作者Github：                 *\n");
    IN_CYANWORD;
    printf("*         https://github.com/Voemp         *\n");
    IN_WHITE;
    printf("********************************************\n");
    IN_REDWORD;
    printf("         &按回车访问作者Github主页&\n");
    printf("          &按其余任意键返回主菜单&\n");
    IN_WHITE;
    printf("********************************************\n");
    do {
        if (getch() == '\r')
            openWeb("https://github.com/Voemp");    //打开作者Github主页
        else
            break;
    } while (1);
}

/*函数功能：绘制菜单
 * **menu：选择哪个覆盖菜单
 * RowSize：菜单的行数
 * line：光标所在行
 * confirm：是否确认
 */
void drawMenu(char *menu[], int RowSize, int line, int confirm) {
    setCursor(0, 0);    //将光标移动到左上角
    //int LineSize = strlen((char *) menu) + 1;   //计算每一行的长度
    for (int i = 0; i < RowSize; ++i) {
        if (i == line) {
            if (confirm == 0) {
                IN_CYAN;
                printf("%s\n", menu[i]);
            } else {
                IN_BLUE;
                printf("%s\n", menu[i]);
            }
            IN_WHITE;
        } else {
            printf("%s\n", menu[i]);
        }
    }
    IN_REDWORD;
    printf("请使用↑、↓和enter来实现选择和执行命令\n");
    printf("或者输入每个命令前面的数字来执行命令\n");
    printf("按ESC键返回上一级\n");
    IN_WHITE;
    printf("%s\n\n", menu[0]);
}


/*函数功能：用方向键选择菜单或者输入数字选择菜单
 * upper, lower：选项的上下界所在行（上界为最后一个选项的行数，下界为第一个选项的行数）
 * **menu：选择哪个覆盖菜单
 * 返回值：选择的选项（1~9）（引用时判断是否为已有选项，如果不是则重新选择）
 */
int menuController(char *menu[], int lower, int upper) {
    system("cls");
    int confirm = 0, line = lower;  //line为光标所在行
    drawMenu(menu, upper + 2, line, confirm);   //绘制菜单
    char c1, c2;
    while ((c1 = getch()) != '\r') {
        if (c1 == 27) {
            if (strcmp(menu[1], "*           退出程序           *") == 0) {
                return 2;
            }
            int choice = menuController(exitConfirmMenu, 3, 4);
            if (choice == 1) {
                exit(0);
            } else {
                system("cls");
                drawMenu(menu, upper + 2, line, confirm);
            }

        } else if (c1 >= '0' && c1 <= '9') {   //如果输入的是数字，则直接返回
            return c1 - '0';
        } else if (c1 == -32) {
            c2 = getch();
            if (c2 == DOWNKEY) {
                if (line == upper) line = lower - 1;
                drawMenu(menu, upper + 2, ++line, confirm);
            }
            if (c2 == UPKEY) {
                if (line == lower) line = upper + 1;
                drawMenu(menu, upper + 2, --line, confirm);
            }
        }
    }
    confirm = 1;
    drawMenu(menu, upper + 2, line, confirm);
    Sleep(80);
    return line - lower + 1;
}