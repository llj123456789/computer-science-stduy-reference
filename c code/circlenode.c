#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//这个谜题中玩具小人的朝向非常关键
int main()
{
    int n,m; //0 向内  1 向外
    scanf("%d %d",&n,&m);
    struct man
    {
        int pst;
        char name[11];
        struct man* next;
        struct man* pre;
    };
    //有圈创建环形链表;
    struct man* start=NULL;
    struct man* end=NULL;
    for(int i=0;i<n;i++)
    {
        struct man* newnode=malloc(sizeof(struct man));
        if(i==0)
        {
            newnode->next=NULL;
            newnode->pre=NULL;
            scanf("%d %s",&(newnode->pst),newnode->name);
            start=newnode;
            end=newnode;
        }
        //
        else if(i<n-1)
        {
            newnode->pre=start;
            newnode->next=NULL;
            scanf("%d %s",&(newnode->pst),newnode->name);
            start->next=newnode;
            start=newnode;
        }
        else if(i==n-1)
        {
            newnode->next=end;
            newnode->pre=start;
            scanf("%d %s",&(newnode->pst),newnode->name);
            start->next=newnode;
            start=newnode;
            end->pre=start;
            start=end;
        }
    }
    struct man* now=start;
//环形链表创建结束;
    for(int i=0;i<m;i++)
    {   
        int a,s;
        scanf("%d %d",&a,&s);
        if(a==0) //left;
        {
            if(now->pst==0)// in pre
            {
                for(int j=0;j<s;j++)
                {
                    now=now->pre;
                }
            }else  //out next
            {
                for(int j=0;j<s;j++)
                {
                    now=now->next;
                }
            }
        }else //right
        {
            if(now->pst==0)// in next
            {
                for(int j=0;j<s;j++)
                {
                    now=now->next;
                }
            }else  //out  pre
            {
                for(int j=0;j<s;j++)
                {
                    now=now->pre;
                }
            }
        }
        
    }   
    printf("%s",now->name);
    return 0;
}