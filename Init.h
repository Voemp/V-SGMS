// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_INIT_H
#define V_SGMS_INIT_H



//�������ܣ���ӡ��ӭ����
void welcomeInit();

//��¼��������
extern char *loginMenu[7];

//���˵�����
extern char *mainMenu[10];

//ѧ���ɼ���ѯ�˵�����ʦ�棩����
extern char *studentGradeQueryMenu1[13];

//ѧ���ɼ���ѯ�˵���ѧ���棩����
extern char *studentGradeQueryMenu2[6];

//ѧ���ɼ�����˵�����ʦ�棩����
extern char *studentGradeManageMenu1[8];

//ѧ���ɼ�����˵���ѧ���棩����
extern char *studentGradeManageMenu2[8];

//�˳�����ȷ�Ͻ�������
extern char *exitConfirmMenu[6];

//�������ܣ����ڽ���
void About();


/*�������ܣ����Ʋ˵�
 * **menu��ѡ���ĸ����ǲ˵�
 * RowSize���˵�������
 * line�����������
 * confirm���Ƿ�ȷ��
 */
void drawMenu(char *menu[], int RowSize, int line, int confirm);

/*�������ܣ��÷����ѡ��˵�������������ѡ��˵�
 * **menu��ѡ���ĸ����ǲ˵�
 * choice_num���˵�ѡ��ĸ���
 * ����ֵ��ѡ���ѡ�1~9��������ʱ�ж��Ƿ�Ϊ����ѡ��������������ѡ��
 */
int menuController(char *menu[], int choice_num);

//�������ܣ��ʵ�
void bonusScene();

#endif //V_SGMS_INIT_H
