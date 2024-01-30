DATAS SEGMENT
   ARR DB 14,-25,66,-17,78,-33,46,-96,71,80  
   ODDNUM DB 0
   EVENNUM DB 0
DATAS ENDS

STACKS SEGMENT
   DW 40H DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    ;初始化各个变量地址
    MOV AX,0
    MOV CX,ODDNUM
    MOV DX,EVENNUM
    MOV BX,1
    
     ; 统计数组中奇数和偶数的个数  
    mov CX,ARR	;数组指针指向cx
    mov AX,CX	;指向数组首地址
    loop_start:  
        cmp byte [CX], 1  ; 判断当前字节是否为 1，如果是奇数则跳转到 loop_start  
        jne loop_start  ; 如果不是则跳转到 loop_start 继续统计  
        inc BX  ; 计数器 ebx 加 1  
        mov byte [CX], 0  ; 将 0 存入 ecx 指向的字节中，表示该字节为偶数  
        loop loop_start  ; 如果字节不为 1 且已经统计了奇数个数则跳转到 loop_start 继续统计  
      
    ; 将统计结果存入 ODDNUM 和 EVENNUM  
    mov CX, ODDNUM  ; 将 ODDNUM 的地址存入 ecx  
    mov DX, EVENNUM  ; 将 EVENNUM 的地址存入 edx  
    mov [CX], BX  ; 将计数器 ebx 的值存入 ODDNUM  
    mov [DX], BX  ; 将计数器 ebx 的值存入 EVENNUM  
    
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
