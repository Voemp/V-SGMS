// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_STRUCT_H
#define V_SGMS_STRUCT_H

typedef struct user {
    char account[20];   //�˺�
    char password[20];  //����
    int role;   //���ֱ�ʾ��ɫ 1�� teacher  2��student
} USER;

typedef struct subject {
    int subjectName;   //��Ŀ��
    float subjectScore;   //��Ŀ����
} SUB;

typedef struct student {
    struct student *pre;   //ǰһ���ڵ�
    char studentID[20]; //ѧ��
    char studentName[20];   //����
    SUB score[6];   //�ɼ�
    float totalScore; //�ܷ�
    float averageScore; //ƽ����
    struct student *next;   //��һ���ڵ�
} STU;

#endif //V_SGMS_STRUCT_H
