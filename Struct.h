// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_STRUCT_H
#define V_SGMS_STRUCT_H

typedef struct user {
    char account[20];   //�˺�
    char password[20];  //����
    int role;   //���ֱ�ʾ��ɫ 1�� teacher  2��student
} USER;

typedef struct student {
    long studentID; //ѧ��
    char studentName[20];   //����
    int score[5];   //�ɼ�
} STU;

#endif //V_SGMS_STRUCT_H
