#include<stdio.h>
typedef unsigned short WORD;
typedef char BYTE;
int main()
{
    union {
        struct{
            WORD ax,bx,cx,dx;
        } word;
        struct{
            BYTE al,ah,bl;
        } byte;
    }regs;
    regs.byte.ah=0x12;
    regs.byte.al=0x34;
    printf("%hx",regs.word.ax);

}