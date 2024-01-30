#include<stdio.h>
#include<stdlib.h>

#define printf __mingw_printf
#define max_digits 10

int segments[10][7]={{1,1,1,1,1,1,0},
                     {0,1,1,0,0,0,0},
                     {1,1,0,1,1,0,1},
                     {1,1,1,1,0,0,1},
                     {0,1,1,0,0,1,1},
                     {1,0,1,1,0,1,1},
                     {1,0,1,1,1,1,1},
                     {1,1,1,0,0,0,0},
                     {1,1,1,1,1,1,1},
                     {1,1,1,1,0,1,1},};
int N=0;
char digits[3][4*max_digits];
void print_digits(void);
void clear_digits(void);
void process_digit(int n);
int main()
{
    int n;
    char s;
    printf("Enter a number: (e.g. 123-456 or 123456 etc.)");
    clear_digits();
    while((s=getchar())!='\n'&&N<max_digits)
    {
        if(s>='0'&&s<='9')
        {
            N++;
            switch (s)
            {
                case '0':n=0;break;case '1':n=1;break;case '2':n=2;break;case '3':n=3;break;case '4':n=4;break;
                case '5':n=5;break;case '6':n=6;break;case '7':n=7;break;case '8':n=8;break;case '9':n=9;break;
            }
            process_digit(n);
        }
    }
    print_digits();
    return 0;
}

void process_digit(int n)
{
    if(segments[n][0])                       
            digits[0][4*N-3]='_';
    if(segments[n][5])
            digits[1][4*N-4]='|';
    if(segments[n][6])
            digits[1][4*N-3]='_';
    if(segments[n][1])
            digits[1][4*N-2]='|';
    if(segments[n][4])
            digits[2][4*N-4]='|';
    if(segments[n][3])
            digits[2][4*N-3]='_';
    if(segments[n][2])
            digits[2][4*N-2]='|';
}
void clear_digits(void)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4*max_digits;j++)
        {
            digits[i][j]=' ';
        }
    }
}
void print_digits(void)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4*max_digits;j++)
        {
            printf("%c",digits[i][j]);
            if(j==4*max_digits-1)
                printf("\n");
        }
    }
}