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
VOID SetTitle(LPCSTR lpTitle);

/*�������ܣ�����ҳ
 *����������website
 *��������ֵ����
 */
void openWeb(char *website);

#endif //V_SGMS_FUNCTIONLIB_H
