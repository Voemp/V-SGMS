// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_INIT_H
#define V_SGMS_INIT_H



//函数功能：打印欢迎界面
void welcomeInit();

//登录界面声明
extern char *loginMenu[7];

//主菜单声明
extern char *mainMenu[10];

//学生成绩查询菜单（教师版）声明
extern char *studentGradeQueryMenu1[13];

//学生成绩查询菜单（学生版）声明
extern char *studentGradeQueryMenu2[6];

//学生成绩管理菜单（教师版）声明
extern char *studentGradeManageMenu1[8];

//学生成绩管理菜单（学生版）声明
extern char *studentGradeManageMenu2[8];

//退出程序确认界面声明
extern char *exitConfirmMenu[6];

//函数功能：关于界面
void About();


/*函数功能：绘制菜单
 * **menu：选择哪个覆盖菜单
 * RowSize：菜单的行数
 * line：光标所在行
 * confirm：是否确认
 */
void drawMenu(char *menu[], int RowSize, int line, int confirm);

/*函数功能：用方向键选择菜单或者输入数字选择菜单
 * **menu：选择哪个覆盖菜单
 * choice_num：菜单选项的个数
 * 返回值：选择的选项（1~9）（引用时判断是否为已有选项，如果不是则重新选择）
 */
int menuController(char *menu[], int choice_num);

//函数功能：彩蛋
void bonusScene();

#endif //V_SGMS_INIT_H
