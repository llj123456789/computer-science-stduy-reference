#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "map.h"

extern char a[][50];
extern int x, y;//我的位置;
extern int want_x, want_y;//目标位置;
extern int m_x1, m_y1;

void color(const unsigned short textColor)      //自定义函根据参数改变颜色 
{
    if (textColor >= 0 && textColor <= 15)     //参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //用一个参数，改变字体颜色
    else   //默认的字体颜色是白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void map(int n)//原地图
{
    switch(n)
    {
    case 0:for (int i = 0; i < 29; i++)
            for (int j = 0; j < 49; j++)
                a[i][j] = ' ';
        for (int i = 0; i < 49; i++)
        {
            a[29][i] = a[0][i] = '+';
        }
        for (int i = 0; i < 30; i++)
        {
            a[i][0] = a[i][49] = '+';
        }break;
    case 1:break;
    }
}
void p_map(int n)//打印用带有目标的地图;
{
    switch (n)
    {
    case 0: for (int i = 0; i < 30; i++)
            {
        for (int j = 0; j < 50; j++)
        {
                    if (a[i][j] == 'M')
                    {color(14);
                    printf("人");
                    color(16);
                    }
                    else if (a[i][j] == '&')
                    {
                        color(4);
                        printf("鬼");
                        color(16);
                    }
                    else if (a[i][j] == '$')
                    {
                        color(5);
                        printf("$");
                        color(16);
                    }
                    else
                    {
                        color(1);
                        printf("%c", a[i][j]);
                        color(16);
                    }
                      
                    
                    if (j == 49)
                        printf("\n");
                }
            }break;
    case 1:break;
    }
}