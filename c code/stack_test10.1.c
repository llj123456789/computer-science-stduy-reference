#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define STACK_SIZE 100

char  contents[STACK_SIZE];
//int top=0;
int *p=contents;
// 储存字符的栈的实现
void make_empty();
bool if_empty();
bool if_full();
void push(char i);
char pull();
//

int main()
{
    printf("Enter parenteses and/or braces: ");
    char str[100]={'\0'};
    gets(str);
    int len;
    len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='{'||str[i]=='(')
        {
            push(str[i]);
        }
        else if(str[i]=='}')
        {
            char s;
            if((s=pull(str[i]))=='{')
                {}
            else 
            {
                printf("Parenteses/braces are nested wrong\n");
                exit(0);
            }
        }
        else 
        {
            char s;
            if(((s=pull(str[i])))=='(')
                {}
            else 
            {
                printf("Parenteses/braces are nested wrong\n");
                exit(0);
            }
        }
        
    }
    if(if_empty())
    {
        printf("Parenteses/brace are nested properly\n");
    }else printf("Parenteses/braces are nested wrong\n");

    make_empty();
    return 0;
}

void make_empty()
{
    p=contents;
}

bool if_empty()
{
    return p==contents;
}

bool if_full()
{
    return p==contents+STACK_SIZE;
}

void push(char i)
{
    if(if_full())
        printf("Stack is full.\n");
    else 
        *p++=i;
}

char pull()
{
    if(if_empty())
        printf("Stack is empty.\n");
    else
        return *--p;
}