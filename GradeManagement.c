// Created by VoidEmpty on 2023/4/3.
#include "GradeManagement.h"

//�������ܣ����ļ���ȡ���������Ϣ
void readBasicInfo() {
    FILE *tfp = fopen("BasicInfo.txt", "a");
    fclose(tfp);
    FILE *fp = fopen("BasicInfo.txt", "r");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    fscanf(fp, "%d", &g_studentNum);
    fclose(fp);
}

//�������ܣ�¼��ɼ�
void readScore(STU *stu) {
    stu->totalScore = 0;    //��ʼ���ܷ�
    printf("������ѧ�ţ�");
    scanf("%s", stu->studentID);
    printf("������������");
    scanf("%s", stu->studentName);
    for (int i = 0; i < g_subjectNum; ++i) {
        stu->score[i].subjectName = i + 1;
        printf("�������%d�ŵĳɼ���", stu->score[i].subjectName);
        scanf("%f", &stu->score[i].subjectScore);
        stu->totalScore += stu->score[i].subjectScore;  //�����ܷ�
    }
    stu->averageScore = stu->totalScore / g_subjectNum;   //����ƽ����
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
        doubleListAdd(head, stu);   //β�巨
        g_studentNum++;
        printf("¼��ɹ�����ǰѧ��������%d\n", g_studentNum);
        printf("�Ƿ����¼�룿\n");
        IN_CYAN;
        printf("1.��\t2.��\n");
        IN_WHITE;
        do {
            choice = getch();
            if (choice != '1' && choice != '2') {
                printf("����������������룡\r");
                Sleep(500);
                printf("                    \r");   //������������ʾ
            }
        } while (choice != '1' && choice != '2');   //�����������������
    } while (choice == '1');    //����1�����¼��
    printf("¼����ɣ��������ز˵�������\n");
    FILE *fp = fopen("BasicInfo.txt", "w");
    if (fp == NULL) {
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }
    fprintf(fp, "%d", g_studentNum);
    fclose(fp);

    Sleep(500);
}


//�������ܣ���ѯÿ�ſγ̵��ֺܷ�ƽ����
void queryTotalAndAverageScore(STU *stu) {
    system("cls");
    printf("*******************************\n");
    printf("*   ÿ�ſγ̵��ֺܷ�ƽ����    *\n");
    printf(" -----------------------------\n");
    printf("|  �γ����� |  �ܷ�  | ƽ���� |\n");
    printf(" -----------------------------\n");
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
        printf(" -----------------------------\n");
    }
    free(total_score);
}

//�������ܣ�����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
void queryRankAscending(STU *stu) {
    system("cls");
    printf("***********************************\n");
    printf("* ��ѧ�����ܷ��ɸߵ����ų����α�  *\n");
    printf(" ---------------------------------\n");
    printf("|  ѧ��  |  ����  |  �ܷ�  | ���� |\n");
    printf(" ---------------------------------\n");
    doubleListInsertSort(stu, 1);  //�����ܷ��ɸߵ�������
    STU *temp = stu->next;  //ͷ��㲻�������
    int rank = 1;
    while (temp != NULL) {
        printf("| %6s | %6s | %6.1f | %4d |\n", temp->studentID, temp->studentName, temp->totalScore, rank);
        printf(" ---------------------------------\n");
        temp = temp->next;
        rank++;
    }
}
