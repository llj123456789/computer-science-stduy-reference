#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include"monster.h"

extern int x, y;//�ҵ�λ��;
extern int want_x, want_y;//Ŀ��λ��;
extern int m_x1, m_y1;//���ƶ�����1��λ��;

void mon_motion()
{
	if (abs(x - m_x1) >= abs(y - m_y1))
	{
		if (x > m_x1)
			m_x1++;
		else if (x < m_x1)
			m_x1--;
		
	}
	else
	{
		if (y > m_y1)
			m_y1++;
		else
			m_y1--;
	}
	if (x - m_x1 == 1)
		m_x1++;
	else if (m_x1 - x == -1)
		m_x1--;
	if (y - m_y1 == 1)
		m_y1++;
	else if (m_y1 - y == 1)
		m_y1--;
			

}
