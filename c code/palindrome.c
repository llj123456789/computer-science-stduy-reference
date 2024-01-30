#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
    char arr[50];
    char *p,*q;
    p=arr,q=arr;
    printf("Enter a message: ");
    while((*p++=getchar())!='\n'&&p<arr+50);
    int len=strlen(arr)-1;
    int n_word=0;
    for(p=arr;p<arr+len;p++)
    {
        if((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z'))
        {
            n_word++;
        }
    }
    char words[n_word];
    int i=0;
    for(p=arr;p<arr+len;p++)
    {
        if((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z'))
        {
            words[i++]=*p;
        }
    }
    for(p=words,q=words+n_word-1;p<q;p++,q--)
    {
        if(*p!=*q&&*p-32!=*q&&*p+32!=*q)
        {
            printf("Not a palindrome\n");
            exit(0);
        }
        printf("Palindromen\n");
return 0;
    }
    return 0;
}