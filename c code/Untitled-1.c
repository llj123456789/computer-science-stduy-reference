#include <stdio.h>
#include <string.h>
#define MAXLEN 100
typedef struct _huiwenNmb
{
    char data[MAXLEN];
    int cnt; //出现次数
}Hwc;
//判断字符串是否是回文
int huiwen(char a[]) 
{
    int t = strlen(a) - 1;
    if (t == 0) return 0; //忽略单个字符的情况
    for (int i = 0; i < t; i++, t--) 
    {
        if (a[i] != a[t])
            return 0;  //是则返回1，不是返回0 
    }
    return 1;
}
//判断字符是否是数字
int isNumber(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}
//判断回文串是否已经出现过
int isExist(Hwc a[], int n, char* p)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(a[i].data, p) == 0)
            return i;
    }
    return -1;
}
//根据出现次数排序
void bubbleSort(Hwc a[], int n)
{
    int i, j;
    Hwc t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j].cnt < a[j + 1].cnt)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
int main()
{
    char buf[500];
    int nmb = 0;
    int i, j,t;
    int index = -1;
    Hwc a[100];
    int k = 0;
    while (1)
    {
        //读取字符串
        k=0;
        while(1)
        {
            t = getchar();
            if(t==EOF || t=='\n')
            {
                buf[k]=0;
                break;
            }else
            {
                buf[k] = t;
                k++;
            }
        }
        if(t == EOF)
            break;
        //提取字符串中的数字部分并判断是否是回文串
        i = 0;
        while (buf[i] != '\0')
        {
            while (buf[i] != '\0')
            {
                while (buf[i] != '\0' && (!isNumber(buf[i]))) //找到数字字符
                    i++;
                if (buf[i] == '\0')
                    break;
                if (buf[i] != '0')
                    break;
                else
                    i++; //如果开头是0，跳过，继续判断
            }
            if (buf[i] == '\0')
                break;
            //将数字字符保存出来
            j = 0;
            while (buf[i]!='\0' && isNumber(buf[i]))
            {
                a[nmb].data[j] = buf[i];
                i++;
                j++;
            }
            a[nmb].data[j] = 0; //结束符
            //判断是否是回文串
            if (huiwen(a[nmb].data))
            {
                //判断回文串是否已经出现过
                index = isExist(a, nmb, a[nmb].data);
                if (index == -1) //没有出现过
                {
                    a[nmb].cnt = 1;
                    nmb++;
                }
                else
                    a[index].cnt += 1; //出现过
            }
        }
    }
    if(nmb==0)
    {
        printf("Node");
        return 0;
    }
    //根据出现次数排序
    bubbleSort(a, nmb);
    i = 0;
    while (1)
    {
        printf("%s %d\n", a[i].data, a[i].cnt);
        if (i + 1 < nmb && a[i + 1].cnt == a[i].cnt) //如果有多个回文出现次数相等
            i++;
        else
            break;
    }
    return 0;
}
