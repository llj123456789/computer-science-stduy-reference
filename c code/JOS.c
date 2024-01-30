#include<stdio.h>
#include<string.h>

void aandj(int a[],int n,int lena)
{
    int b[101]={0}; //储存n的阶乘;
    b[0]=1;
    int now;
    int l=1;
    for(int i=1;i<=n;i++)
    {
        int c=0;
        for(now=0;now<=100;now++)
        {
            b[now]=b[now]*i+c;
            c=b[now]/10;
            if(b[l]!=0)
                l++;
            b[now]%=10;
        }
    } 
int p=0,c=0;
int left=(l>lena?l:lena);
    do
    {
        a[p]=a[p]+b[p]+c;
        c=a[p]/10;
        a[p]%=10;;
        p++;
    }while(p<=left);

}

int main()
{
    int a[101]={0};
    int n;
    scanf("%d",&n);
    int len=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=100;j>=0;j--)
        {
            if(a[j]!=0)
            {
                len=j+1;
                break;
            }
        }
        aandj(a,i,len);
    }
    for(int j=100;j>=0;j--)
        {
            if(a[j]!=0)
            {
                len=j+1;
                break;
            }
        }
    for(int i=len-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}