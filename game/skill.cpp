#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include"skill.h"
extern char a[][50];
extern int x, y;//我的位置;
extern int want_x, want_y;//目标位置;
extern int m_x1, m_y1;

void pop()
{
	int a = x - m_x1;
	int b = y - m_y1;
	if (a > 0 && a < 5)
		m_x1 -= 5;
	else if (a<0 && a>-5)
		m_x1 += 5;
	if (b > 0 && b < 5)
		m_y1 -= 5;
	else if (b<0 && b>-5)
		m_y1 += 5;

}