#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "map.h"

extern char a[][50];
extern int x, y;//�ҵ�λ��;
extern int want_x, want_y;//Ŀ��λ��;
extern int m_x1, m_y1;

void color(const unsigned short textColor)      //�Զ��庯���ݲ����ı���ɫ 
{
    if (textColor >= 0 && textColor <= 15)     //������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //��һ���������ı�������ɫ
    else   //Ĭ�ϵ�������ɫ�ǰ�ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void map(int n)//ԭ��ͼ
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
void p_map(int n)//��ӡ�ô���Ŀ��ĵ�ͼ;
{
    switch (n)
    {
    case 0: for (int i = 0; i < 30; i++)
            {
        for (int j = 0; j < 50; j++)
        {
                    if (a[i][j] == 'M')
                    {color(14);
                    printf("��");
                    color(16);
                    }
                    else if (a[i][j] == '&')
                    {
                        color(4);
                        printf("��");
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