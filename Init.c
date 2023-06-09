// Created by VoidEmpty on 2023/3/29.
#include "Init.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "FunctionLib.h"

#define IN_BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x90)
#define IN_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb0)
#define IN_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf9)
#define IN_REDWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfc)
#define IN_CYANWORD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xfb)

#define TEMPKEY -32
#define UPKEY 72
#define DOWNKEY 80

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
    Sleep(250);
    printf("程序正在加载中[■■■■□□□□□□]40%\r");
    Sleep(400);
    printf("程序正在加载中[■■■■■■□□□□]60%\r");
    Sleep(700);
    printf("程序正在加载中[■■■■■■■■□□]80%\r");
    Sleep(350);
    printf("程序正在加载中[■■■■■■■■■■]100%\n");
    Sleep(400);
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
                      "*        3.退出登录            *\0",
                      "*        4.科目设置            *\0",
                      "*        5.关于                *\0",
                      "*        6.退出程序(ESC)       *\0",
                      "********************************\0"};

//学生成绩查询菜单（教师版）
char *studentGradeQueryMenu1[13] = {"******************************************************\0",
                                    "*                学生成绩查询（教师版）              *\0",
                                    "******************************************************\0",
                                    "*        1.查询每门课程的总分和平均分                *\0",
                                    "*        2.按照每个学生的总分由高到低排出名次表      *\0",
                                    "*        3.按照每个学生的总分由低到高排出名次表      *\0",
                                    "*        4.按照学号由小到大排出成绩表                *\0",
                                    "*        5.按照学号查询学生排名及其各科考试成绩      *\0",
                                    "*        6.按照姓名查询学生排名及其各科考试成绩      *\0",
                                    "*        7.统计不同分数段的人数百分比                *\0",
                                    "*        8.输出全部信息                              *\0",
                                    "*        9.返回主菜单                                *\0",
                                    "******************************************************\0"};

//学生成绩查询菜单（学生版）
char *studentGradeQueryMenu2[6] = {"*********************************\0",
                                   "*     学生成绩查询（学生版）    *\0",
                                   "*********************************\0",
                                   "*       1.查询自己的成绩        *\0",
                                   "*       2.返回主菜单            *\0",
                                   "*********************************\0"};

//学生成绩管理菜单（教师版）
char *studentGradeManageMenu1[8] = {"*********************************\0",
                                    "*     学生成绩管理（教师版）    *\0",
                                    "*********************************\0",
                                    "*       1.添加学生成绩          *\0",
                                    "*       2.修改学生成绩          *\0",
                                    "*       3.删除学生信息          *\0",
                                    "*       4.返回主菜单            *\0",
                                    "*********************************\0"};

//学生成绩管理菜单（学生版）
char *studentGradeManageMenu2[8] = {"*********************************\0",
                                    "*     学生成绩管理（学生版）    *\0",
                                    "*********************************\0",
                                    "*       1.录入自己的成绩        *\0",
                                    "*       2.修改自己的成绩        *\0",
                                    "*       3.删除自己的成绩        *\0",
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
    printf("*作者Github：");
    IN_CYANWORD;
    printf("https://github.com/Voemp");
    IN_WHITE;
    printf("      *\n");
    printf("*项目地址：https://github.com/Voemp/V-SGMS *\n");
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
 * **menu：选择哪个覆盖菜单
 * choice_num：菜单选项的个数
 * 返回值：选择的选项（1~9）（引用时判断是否为已有选项，如果不是则重新选择）
 */
int menuController(char *menu[], int choice_num) {
    system("cls");
    //lower为第一个选项的行数，upper为最后一个选项的行数, line为光标所在行
    int confirm = 0, lower = 3, upper = lower + choice_num - 1, line = lower;
    drawMenu(menu, upper + 2, line, confirm);   //绘制菜单
    char c1, c2;
    while ((c1 = getch()) != '\r') {
        if (c1 == 27) { //如果输入的是ESC键
            return choice_num;
        } else if (c1 >= '0' && c1 <= '9') {   //如果输入的是数字，则直接返回
            return c1 - '0';
        } else if (c1 == -32) {  //如果输入的是方向键
            c2 = getch();
            if (c2 == DOWNKEY) {    //如果输入的是下方向键
                if (line == upper) line = lower - 1;
                drawMenu(menu, upper + 2, ++line, confirm);
            }
            if (c2 == UPKEY) {  //如果输入的是上方向键
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

//函数功能：彩蛋
void bonusScene() {
    //   获取控制台窗口的句柄
    HWND window = GetConsoleWindow();
    // 置顶窗口
    SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    // 移动窗口
    SetWindowPos(window, NULL, 0, 0, 0, 0, SWP_NOSIZE);
    // 设置窗口大小
    setWindowSize(327, 1094);
    system("color f6");
    openWeb("https://www.bilibili.com/video/BV1K64y1z71C/?share_source=copy_web&vd_source=5f5cb3412d1c4cb294585c18e26b6ae8&t=0");
    system("cls");
    printf("******************\n");
    printf("*   光——星尘   *\n");
    printf("******************\n");
    Sleep(500);
    printf("如在黑夜中\n");
    Sleep(300);
    printf("被熄灭了星空\n");
    Sleep(300);
    printf("荒原上看不到尽头\n");
    Sleep(300);
    printf("只有这一路相随的孤独\n");
    Sleep(300);
    printf("是我黑暗中唯一的盟友\n");
    Sleep(300);
    printf("如在寒风中\n");
    Sleep(300);
    printf("被浇灭了篝火\n");
    Sleep(300);
    printf("残余的温度也被夺走\n");
    Sleep(300);
    printf("已不能分清\n");
    Sleep(300);
    printf("颤抖着的身体\n");
    Sleep(300);
    printf("和心哪个更冰冷\n");
    Sleep(300);
    printf("视线渐渐模糊\n");
    Sleep(300);
    printf("一路上 我都在 追逐什么\n");
    Sleep(300);
    printf("这些渴望 哪个 真属于我\n");
    Sleep(300);
    printf("他人的期待不过是我的枷锁\n");
    Sleep(300);
    printf("一路上 我都在 为何拼搏\n");
    Sleep(300);
    printf("这些目标 哪个 真适合我\n");
    Sleep(300);
    printf("从今以后只做属于我的选择\n");
    Sleep(300);
    printf("走吧\n");
    Sleep(300);
    printf("放下\n");
    Sleep(300);
    printf("走吧\n");
    Sleep(300);
    printf("放下\n");
    Sleep(800);
    printf("背靠着大地\n");
    Sleep(300);
    printf("用全力深呼吸\n");
    Sleep(300);
    printf("手臂不由自主的上举\n");
    Sleep(300);
    printf("一定是对跌落的不甘心\n");
    Sleep(300);
    printf("不甘心刚到这里就放弃\n");
    Sleep(300);
    printf("面朝向天际\n");
    Sleep(300);
    printf("重新起身站立\n");
    Sleep(300);
    printf("心也用脉搏给予回应\n");
    Sleep(300);
    printf("踏出的步伐\n");
    Sleep(300);
    printf("向远方的黎明\n");
    Sleep(300);
    printf("有力并始终相信\n");
    Sleep(300);
    printf("日出的光明\n");
    Sleep(300);
    printf("一边走 一边看 四处风景\n");
    Sleep(300);
    printf("才发现 被忽略 过的美丽\n");
    Sleep(300);
    printf("所有的感受都将被铭记在心\n");
    Sleep(300);
    printf("不必 劳烦群星 指引\n");
    Sleep(300);
    printf("第一道 曙光已 划破天际\n");
    Sleep(300);
    printf("也知晓 黑夜会 再次光临\n");
    Sleep(300);
    printf("如今我已学会在黑暗中前行\n");
    Sleep(300);
    printf("已经无所畏惧\n");
    Sleep(300);
    printf("走吧\n");
    Sleep(300);
    printf("走吧\n");
    Sleep(300);
    printf("走吧\n");
    Sleep(300);
    printf("再 出发\n");
    Sleep(500);
    printf("跟随风 放飞脑 海中的梦想\n");
    Sleep(300);
    printf("回应地以坚定的步伐\n");
    Sleep(300);
    printf("拥抱海 拍打在 身上的浪花\n");
    Sleep(300);
    printf("让心再次重燃出发\n");
    Sleep(300);
    printf("待到再迷茫时回头望 所有脚印会发出光芒\n");
    Sleep(300);
    printf("能为你照亮 黑夜中 属于你的前行方向\n");
    Sleep(300);
    IN_REDWORD;
    printf("\n按任意键继续。。。");
    IN_WHITE;
    getch();
    system("color f9");
    setWindowSize(943, 598);
    // 移动窗口
    SetWindowPos(window, NULL, 510, 330, 0, 0, SWP_NOSIZE);
    // 不置顶窗口
    SetWindowPos(window, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}