#include<stdio.h>
#include<stdbool.h>
#include<string.h>



#define MAX_STACK 100
int contents[MAX_STACK];
//int top=0;
int *p=contents;
bool is_empty(void);
bool is_full(void);
int pull(void);
void push(int n);

int main()
{
    printf("Enter an PRN expresion: ");
    char s;
    int n,a,b;
    while(((s=getchar())<='9'&&s>='0')||s=='+'||s=='*'||s=='-'||s=='/'||s=='='||s==' '||s=='\n')
    {
        if(s<='9'&&s>'0')
        {
            switch (s)
            {
                case '0':n=0;break;case '1':n=1;break;case '2':n=2;break;case '3':n=3;break;case '4':n=4;break;
                case '5':n=5;break;case '6':n=6;break;case '7':n=7;break;case '8':n=8;break;case '9':n=9;break;
            }
            push(n);
        }
        else if(s=='+'||s=='-'||s=='*'||s=='/')
        {
            if(p>=contents+2)
            {
                if(s=='+')
                {
                    a=pull();
                    b=pull();
                    push(b+a);
                }
                if(s=='-')
                {
                    a=pull();
                    b=pull();
                    push(b-a);
                }
                if(s=='*')
                {
                    a=pull();
                    b=pull();
                    push(b*a);
                }
                if(s=='/')
                {
                    a=pull();
                    b=pull();
                    push(b/a);
                }
            }
            else 
                printf("No enough operands in expression.\n");
        }
        else if(s=='=')
            printf("Value of expression: %d\n",pull());
        if(s=='\n')
            printf("Enter an PRN expresion: ");
    }
    return 0;
}
bool is_full()
{
    return p==&contents+MAX_STACK;
}
bool is_empty()
{
    return p==contents;
}
void push(int n)
{
    if(is_full())
        printf("Expression is too complex\n");
    else 
        *p++=n;
}
int pull(void)
{
    if(is_empty())
        printf("The stack is empty\n");
    else 
        return *--p;
}
