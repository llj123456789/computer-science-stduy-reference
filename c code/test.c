#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


int min(int a,int b)
{
	return a>b?b:a;
}
int jie(int i)
{
    if(i>1)
        return i*jie(i-1);
    else
        return 1;
}
typedef struct
{
    int a;
} student;
struct name
{
    int a,b,c;
};
int main()
{
    struct name a;
    
    student c;
    c.a=10;

    
}