DATAS SEGMENT
    ;�˴��������ݶδ���  
    MAXLENTH DB 11
    STRLEN DB ?
    STR1 DB 11 DUP(0)
    STR2 DB 11 DUP(0)
    DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
    DW 40H DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
    MOV AH,0AH
    LEA DX,MAXLENTH
    INT 21H
    XOR CX,CX
    LEA SI,STR1
    LEA DI,STR2
    ;�ֱ�str1��str2����SI,DI
    CALL NONUM
    CMP STRLEN,0
    ;�ж�ɾ������֮����ַ�������
    JE L1
    CALL UPWORD
    JMP L2
	;������Ȳ�Ϊ0�����upword��ת����д
    
L1: MOV AL,'?'
	MOV [DI],AL
	MOV AL,'$'
	MOV [DI+1],AL
	;�������Ϊ0���ڿմ���ѹ�롮����
		
	;L2������������ַ���
L2: MOV DL,0DH
	MOV AH,02H
	INT 21H
	MOV DL,0AH
	MOV AH,02H
	INT 21H
	;���ʱע����Ҫ���������س�
	MOV AH,09H
	LEA DX,STR2
	INT 21H
	MOV AH,4CH
	INT 21H
    
    MOV AH,4CH
    INT 21H
    
NONUM PROC
	PUSHF
	PUSH AX
	PUSH DI
	PUSH SI
	PUSH CX
	;��ջ�����ֳ�
	MOV CL,STRLEN
L3:	MOV BL,[SI]
	;ȡ��ǰ�ַ�������BL
	CMP BL,30H
	JAE L4
	JMP L5
L4:	CMP BL,39H
	JA L5
	DEC STRLEN
	JMP L6
	;�жϵ�ǰ�ַ��Ƿ�Ϊ���֣�30H-39H��	
L5: MOV AL,[SI]
	MOV [DI],AL
	INC DI
	;����������־ͱ��浽str2,����DI��
L6: INC SI
	LOOP L3
	POP CX
	POP SI
	POP DI
	POP AX
	POPF
	;��ջ��ԭ�ֳ� 
	RET
NONUM ENDP

UPWORD PROC
	PUSHF
	PUSH AX
	PUSH DI
	PUSH CX
	;��ջ�����ֳ�
	MOV CL,STRLEN
L7:	MOV BL,[DI]
	CMP BL,61H
	JAE L8
	JMP L9
L8: MOV AL,[DI]
	CMP AL,7AH
	;�жϵ�ǰ�ַ��Ƿ�ΪСд��ĸ�ַ�
	JA L9
	;�������Сд��ĸ������7AH��������
	SUB AL,20H
	MOV [DI],AL
	;�����Сд��ĸ�͸�Ϊ��д��ԭascll���20��Ȼ�����ԭ��λ��
L9:	INC DI
	LOOP L7
	MOV AL,'$'
	MOV [DI],AL
	;�������$ѹ���ַ�����
	POP CX
	POP DI
	POP AX
	POPF
	;��ջ��ԭ�ֳ�
	RET
UPWORD ENDP
    
CODES ENDS
    END START
