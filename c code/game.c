#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
double distance(double x1,double x2,double y1,double y2,double z1,double z2)
{
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
}
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int testsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            return 1;
        }
    }
    return 0;
}
void sort(int l,int r,int a[],int k)
{
    int c=a[l],pl=l,pr=r;
    int move=1;
    if(pl>=pr)
        return;
    while(pl<pr)
    {
        if(move==1)
        {
            if(a[pr]<c)
            {
                a[pl++]=a[pr];
                move=0;
            }else
            {
                pr--;
            }
        }else
        {
            if(a[pl]>c)
            {
                a[pr--]=a[pl];
                move=1;
            }else
            {
                pl++;
            }
        }
    }
    a[pl]=c;
        sort(l,pl-1,a,k);

        sort(pl+1,r,a,k);
    
 
}
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}


int len[4];
int sub[30];
int f[21][1201];

int main(){
    
    for(int i=0;i<4;i++) scanf("%d",&len[i]);
    int tot=0;
    for(int i=0;i<4;i++){
        int v=0;
        for(int j=1;j<=len[i];j++) scanf("%d",&sub[j]),v+=sub[j];
     //   sort(sub,sub+len[i]);
        int t1=0;
        for(int j=1;j<=len[i];j++)
            for(int k=0;k<=v/2;k++){
                f[j][k]=f[j-1][k];
                if(k>=sub[j])f[j][k]=max(f[j][k],f[j-1][k-sub[j]]+sub[j]);
                t1=max(f[j][k],t1);
            }
        tot+=max(t1,v-t1);
    }
    printf("%d",tot);
    return 0;
}