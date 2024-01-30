//#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<Windows.h>
#include"map.h"
#include"power.h"
#include"monster.h"
#include"skill.h"


char a[30][50];//��Ϸ��Χ;
int x, y;//�ҵ�λ��;
int want_x, want_y;//Ŀ��λ��;
int m_x1, m_y1;//���ƶ�����1��λ��;
int score = 0;//��Ϸ����;
int number_map;//��ͼ���;

void color_s(const unsigned short textColor)      //�Զ��庯���ݲ����ı���ɫ 
{
    if (textColor >= 0 && textColor <= 15)     //������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //��һ���������ı�������ɫ
    else   //Ĭ�ϵ�������ɫ�ǰ�ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
/*void modeset(int w, int h) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size = { w, h };
    SetConsoleScreenBufferSize(hOut, size);
    SMALL_RECT rc = { 1,1, w, h };
    SetConsoleWindowInfo(hOut, true, &rc);
    system("cls");
    return;
}
*///Ҳ����һ�����ڴ�С����;



void print_map();//��ӡ��ͼ;
void game_initialize();//��Ϸ��ʼ��;
void position();//����λ��;
void motion(char s);//�����ƶ�;
void clear_position();//����ԭλ��;
void continue_game();//��ʼ�������
void judge_victory();//�ж�ʤ��;
void new_game();//������Ϸ;
void new_position();//�³�ʼ��λ��;
//���Դ��͵�ǽ;

int main(void)
{
    initgraph(1290, 1080);
    system("color 74");//ǰ����������,��Ϊ1����Ϊ���壻
    system("pause");
    printf("Start?\nW is up,s is down,a is left,d is right,o is game over\n");
    game_initialize();
    continue_game();

}

void game_initialize()
{
    printf("��������Ҫ�ĵ�ͼ���");
    scanf_s("%d", &number_map);
    map(number_map);
    srand(time(0));
    new_position();
    position();
    print_map();

}

void print_map()
{
    position();
    p_map(number_map);
    color_s(2);
    printf("\nYour score is %d\n��ӵ�м���pop ���k\n���λ�ã�%d,%d�����λ�ã�%d,%d�����ص�λ�ã�%d��%d��", score,x,y,m_x1,m_y1,want_x,want_y);
    color_s(16);
}

void position()
{
    a[y][x] = 'M';
    a[want_y][want_x] = '$';
    a[m_y1][m_x1] = '&';
}

void motion(char s)
{
    if (want_x == x && want_y == y && score == 0)
    {
        score++;
        color_s(6);
        printf("��������");
        color_s(16);
        // system("pause");
    }
    else if (x==m_x1&&y==m_y1&&score==0)
    {
        score--;
        color_s(4);
        printf("��������̥��");
        color_s(16);
    }
    else
    {
        if (s == 'w' || s == 'W')
        {
            clear_position();
            y--;
            if_transmition();
            mon_motion();
            system("cls");
            print_map();
        }
        else if (s == 's' || s == 'S')
        {
           clear_position();
            y++;
            if_transmition();
            mon_motion();
            system("cls");
            print_map();
        }
        else if (s == 'A' || s == 'a')
        {
           clear_position();
            x--;
            if_transmition();
            mon_motion();
            system("cls");
            print_map();
        }
        else if (s == 'd' || s == 'D')
        {
           clear_position();
            x++;
            if_transmition();
            mon_motion();
            system("cls");
            print_map();
        }
        else if (s == 'k')
        {
            pop();
        }
    }
}

void clear_position()
{
    a[y][x] = ' ',
    a[want_y][want_x] = ' ';
    a[m_y1][m_x1] = ' ';

}

void continue_game()
{

    do
    {
        char s = _getch();
        if (s == 'W' || s == 'w' || s == 'a' || s == 'A' || s == 'd' || s == 'D' || s == 'S' || s == 's' || s == 'k');
        {
            motion(s);
           
            judge_victory();
        }
        if (s == 'o')
            break;
    } while (1);

}

void judge_victory()
{
    if (x == want_x && y == want_y)
    {
        score++;
        new_game();
    }
    else if (x == m_x1 && y == m_y1)
    {
        score--;
        new_game();
    }
}

void new_game()
{
    game_initialize();
    system("cls");
    print_map();
}

void new_position()
{
    want_x = rand() % 48 + 1, want_y = rand() % 28 + 1;
    x = rand() % 48 + 1, y = rand() % 28 + 1;
    m_x1 = rand() % 48 + 1, m_y1 = rand() % 28 + 1;
}
//���๦�ܼ�����power�ļ�;
//���༼�ܼ�skill�ļ�;
