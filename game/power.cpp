#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"power.h"

extern char a[][50];
extern int x, y;//我的位置;
extern int want_x, want_y;//目标位置;
extern int m_x1, m_y1;

void if_transmition()
{
		if (x == 0)
			x = 50 - 1-1;
		else if (x == 50-1)
			x = 0 + 1;
		if (y == 0)
			y = 30 - 1 - 1;
		else if (y <29)
		{

		}else y = 1;
		

		/*if (m_y1 == 0)
			m_x1 = 50 - 1;
		else if (m_x1 == 50)
			m_x1 = 0 + 1;
		if (m_y1 == 0)
			m_y1 = 30 - 1;
		else if (m_y1 == 30)
			m_y1 == 0 + 1;*/
}