// Created by VoidEmpty on 2023/3/29.
#ifndef V_SGMS_FUNCTIONLIB_H
#define V_SGMS_FUNCTIONLIB_H

#include <windows.h>

/*�������ܣ���ȡ���λ��
 *������������
 *��������ֵ�����λ��
 */
COORD getCursor();

/*�������ܣ�����̨����ƶ���ָ��λ��
 *����������x,y
 *��������ֵ����
 */
void setCursor(int x, int y);

/*�������ܣ����ô��ڱ���
 *����������lpTitle
 *��������ֵ����
 */
VOID setTitle(LPCSTR lpTitle);

/*�������ܣ����ô��ڴ�С
 *����������width,height
 *��������ֵ����
 */
void setWindowSize(int x, int y);

/*�������ܣ�����ҳ
 *����������website
 *��������ֵ����
 */
void openWeb(char *website);

#endif //V_SGMS_FUNCTIONLIB_H
