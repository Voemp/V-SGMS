// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_STRUCT_H
#define V_SGMS_STRUCT_H

typedef struct user {
    char account[20];   //账号
    char password[20];  //密码
    int role;   //数字表示角色 1是 teacher  2是student
} USER;

typedef struct student {
    long studentID; //学号
    char studentName[20];   //姓名
    int score[5];   //成绩
} STU;

#endif //V_SGMS_STRUCT_H
