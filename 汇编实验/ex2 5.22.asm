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
    
    ;��ʼ������������ַ
    MOV AX,0
    MOV CX,ODDNUM
    MOV DX,EVENNUM
    MOV BX,1
    
     ; ͳ��������������ż���ĸ���  
    mov CX,ARR	;����ָ��ָ��cx
    mov AX,CX	;ָ�������׵�ַ
    loop_start:  
        cmp byte [CX], 1  ; �жϵ�ǰ�ֽ��Ƿ�Ϊ 1���������������ת�� loop_start  
        jne loop_start  ; �����������ת�� loop_start ����ͳ��  
        inc BX  ; ������ ebx �� 1  
        mov byte [CX], 0  ; �� 0 ���� ecx ָ����ֽ��У���ʾ���ֽ�Ϊż��  
        loop loop_start  ; ����ֽڲ�Ϊ 1 ���Ѿ�ͳ����������������ת�� loop_start ����ͳ��  
      
    ; ��ͳ�ƽ������ ODDNUM �� EVENNUM  
    mov CX, ODDNUM  ; �� ODDNUM �ĵ�ַ���� ecx  
    mov DX, EVENNUM  ; �� EVENNUM �ĵ�ַ���� edx  
    mov [CX], BX  ; �������� ebx ��ֵ���� ODDNUM  
    mov [DX], BX  ; �������� ebx ��ֵ���� EVENNUM  
    
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
