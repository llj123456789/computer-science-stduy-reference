DATAS SEGMENT
    ;�˴��������ݶδ��� 
     MAXLEN DB 11
     INPUTLEN DB ?
     STR DB 11 DUP(0)
     SUM DB 0 
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
    LEA DX,MAXLEN
    INT 21H
    XOR CX,CX
    MOV CL,INPUTLEN
    LEA SI,STR
    PUSH SI
    PUSH CX
    LEA SI,SUM
    PUSH SI
    CALL JU
    ADD SUM,30H
    MOV [SUM+1],'$'
    MOV AH,02H
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H
    MOV AH,09H
    LEA DX,SUM
    INT 21H
    MOV AH,09H
    LEA DX,SUM
    INT 21H
    MOV AH,4CH
    INT 21H
JU PROC
	PUSH BP
	MOV BP,SP
	PUSH AX
	PUSH CX
	PUSH BX
	PUSH DX
	MOV CX,[BP+6]
	MOV SI,[BP+8]
	MOV BX,[BP+4]
    
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
