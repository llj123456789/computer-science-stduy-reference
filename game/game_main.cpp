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


char a[30][50];//游戏范围;
int x, y;//我的位置;
int want_x, want_y;//目标位置;
int m_x1, m_y1;//可移动怪兽1的位置;
int score = 0;//游戏分数;
int number_map;//地图序号;

void color_s(const unsigned short textColor)      //自定义函根据参数改变颜色 
{
    if (textColor >= 0 && textColor <= 15)     //参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //用一个参数，改变字体颜色
    else   //默认的字体颜色是白色
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
*///也许是一个窗口大小设置;



void print_map();//打印地图;
void game_initialize();//游戏初始化;
void position();//物体位置;
void motion(char s);//物体移动;
void clear_position();//处理原位置;
void continue_game();//开始与结束；
void judge_victory();//判断胜利;
void new_game();//重置游戏;
void new_position();//新初始化位置;
//可以传送的墙;

int main(void)
{
    initgraph(1290, 1080);
    system("color 74");//前背景后字体,若为1个则为字体；
    system("pause");
    printf("Start?\nW is up,s is down,a is left,d is right,o is game over\n");
    game_initialize();
    continue_game();

}

void game_initialize()
{
    printf("请输入你要的地图序号");
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
    printf("\nYour score is %d\n你拥有技能pop 点击k\n你的位置（%d,%d）鬼的位置（%d,%d）宝藏的位置（%d，%d）", score,x,y,m_x1,m_y1,want_x,want_y);
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
        printf("出身即幸运");
        color_s(16);
        // system("pause");
    }
    else if (x==m_x1&&y==m_y1&&score==0)
    {
        score--;
        color_s(4);
        printf("不幸死于胎中");
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
//更多功能见功能power文件;
//更多技能见skill文件;
