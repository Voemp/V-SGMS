// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"

//�������ܣ����ļ���ȡ���������Ϣ
void readBasicInfo() {
    FILE *fp = fopen("BasicInfo.txt", "r");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    fscanf(fp, "%d", &g_studentNum);
}

//�������ܣ�¼��ɼ�
void readScore(STU *stu) {
    printf("������ѧ�ţ�");
    scanf("%s", stu->studentID);
    printf("������������");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        stu->score[i].subjectName = i + 1;
        printf("�������%d�ŵĳɼ���", stu->score[i].subjectName);
        scanf("%f", &stu->score[i].subjectScore);
    }
}

//�������ܣ����޴�¼��ɼ�
void readScoreInfinite(STU *head) {
    int choice;
    do {
        system("cls");
        printf("************************\n");
        printf("*   ѧ���ɼ�¼��ϵͳ   *\n");
        printf("************************\n");
        STU *stu = (STU *) calloc(sizeof(STU), 1);
        if (stu == NULL) {
            printf("�ڴ����ʧ�ܣ�");
            exit(0);
        }
        readScore(stu);
        doubleListAdd(head, stu);
        g_studentNum++;
        do {
            printf("�Ƿ����¼�룿\n");
            IN_CYAN;
            printf("1.��\t2.��\n");
            IN_WHITE;
            choice = getch();
            if (choice != '1' && choice != '2') {
                printf("����������������룡\n");
                Sleep(300);
            }
        } while (choice != '1' && choice != '2');
    } while (choice == '1');
    printf("¼����ɣ��������ز˵�������\n");
    FILE *fp = fopen("BasicInfo.txt", "w");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    fprintf(fp, "%d", g_studentNum);
    Sleep(500);
}


//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *stu) {
    system("cls");
    printf("*******************************\n");
    printf("*   ÿ�ſγ̵��ֺܷ�ƽ����    *\n");
    printf(" ����������������������������������������������������������\n");
    printf("|  �γ����� |  �ܷ�  | ƽ���� |\n");
    printf(" ����������������������������������������������������������\n");
    float *total_score = calloc(sizeof(float), g_subjectNum);
    if (total_score == NULL) {
        printf("�ڴ����ʧ�ܣ�");
        exit(0);
    }
    STU *temp = stu->next;  //ͷ��㲻�������
    //�����ܷ�
    while (temp != NULL) {
        for (int i = 0; i < g_subjectNum; ++i) {
            total_score[i] += temp->score[i].subjectScore;
        }
        temp = temp->next;
    }
    for (int i = 0; i < g_subjectNum; ++i) {
        printf("| ��%d�ſγ� | %6.1f | %6.1f |\n", i + 1, total_score[i], total_score[i] / g_studentNum);
        printf(" ����������������������������������������������������������\n");
    }
    free(total_score);
}

//�������ܣ���ָ���ı�׼��ѧ����Ϣ�����������
