// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"

//函数功能：从文件读取程序基本信息
void readBasicInfo() {
    FILE *tfp = fopen("BasicInfo.txt", "a");
    fclose(tfp);
    FILE *fp = fopen("BasicInfo.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败！");
        exit(0);
    }
    fscanf(fp, "%d", &g_studentNum);
    fclose(fp);
}

//函数功能：录入成绩
void readScore(STU *stu) {
    stu->totalScore = 0;    //初始化总分
    printf("请输入学号：");
    scanf("%s", stu->studentID);
    printf("请输入姓名：");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        stu->score[i].subjectName = i + 1;
        printf("请输入第%d门的成绩：", stu->score[i].subjectName);
        scanf("%f", &stu->score[i].subjectScore);
        stu->totalScore += stu->score[i].subjectScore;  //计算总分
    }
    stu->averageScore = stu->totalScore / g_subjectNum;   //计算平均分
}

//函数功能：无限次录入成绩
void readScoreInfinite(STU *head) {
    int choice;
    do {
        system("cls");
        printf("************************\n");
        printf("*   学生成绩录入系统   *\n");
        printf("************************\n");
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("内存分配失败！");
            exit(0);
        }
        readScore(stu);
        doubleListAdd(head, stu);   //尾插法
        g_studentNum++;
        printf("录入成功！当前学生人数：%d\n", g_studentNum);
        printf("是否继续录入？\n");
        IN_CYAN;
        printf("1.是\t2.否\n");
        IN_WHITE;
        do {
            choice = getch();
            if (choice != '1' && choice != '2') {
                printf("输入错误，请重新输入！\r");
                Sleep(500);
                printf("                    \r");   //清除输入错误提示
            }
        } while (choice != '1' && choice != '2');   //输入错误则重新输入
    } while (choice == '1');    //输入1则继续录入
    printf("录入完成！即将返回菜单。。。\n");
    FILE *fp = fopen("BasicInfo.txt", "w");
    if (fp == NULL) {
        printf("文件打开失败！");
        exit(0);
    }
    fprintf(fp, "%d", g_studentNum);
    fclose(fp);

    Sleep(500);
}


//函数功能：查询每门课程的总分和平均分
void queryTotalAndAverageScore(STU *stu) {
    system("cls");
    printf("*******************************\n");
    printf("*   每门课程的总分和平均分    *\n");
    printf(" -----------------------------\n");
    printf("|  课程名称 |  总分  | 平均分 |\n");
    printf(" -----------------------------\n");
    float *total_score = calloc(sizeof(float), g_subjectNum);
    if (total_score == NULL) {
        printf("内存分配失败！");
        exit(0);
    }
    STU *temp = stu->next;  //头结点不参与计算
    //计算总分
    while (temp != NULL) {
        for (int i = 0; i < g_subjectNum; ++i) {
            total_score[i] += temp->score[i].subjectScore;
        }
        temp = temp->next;
    }
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("| 第%d门课程 | %6.1f | %6.1f |\n", i + 1, total_score[i], total_score[i] / g_studentNum);
        printf(" -----------------------------\n");
    }
    free(total_score);
}

//函数功能：按照每个学生的总分由高到低排出名次表
void queryRankAscending(STU *stu) {
    system("cls");
    printf("***********************************\n");
    printf("* 按学生的总分由高到低排出名次表  *\n");
    printf(" ---------------------------------\n");
    printf("|  学号  |  姓名  |  总分  | 排名 |\n");
    printf(" ---------------------------------\n");
    doubleListInsertSort(stu, 1);  //按照总分由高到低排序
    STU *temp = stu->next;  //头结点不参与计算
    int rank = 1;
    while (temp != NULL) {
        printf("| %6s | %6s | %6.1f | %4d |\n", temp->studentID, temp->studentName, temp->totalScore, rank);
        printf(" ---------------------------------\n");
        temp = temp->next;
        rank++;
    }
}
