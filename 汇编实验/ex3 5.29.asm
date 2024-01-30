DATAS SEGMENT
    ;此处输入数据段代码  
    MAXLENTH DB 11
    STRLEN DB ?
    STR1 DB 11 DUP(0)
    STR2 DB 11 DUP(0)
    DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
    DW 40H DUP(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
    MOV AH,0AH
    LEA DX,MAXLENTH
    INT 21H
    XOR CX,CX
    LEA SI,STR1
    LEA DI,STR2
    ;分别将str1，str2存入SI,DI
    CALL NONUM
    CMP STRLEN,0
    ;判断删除数字之后的字符串长度
    JE L1
    CALL UPWORD
    JMP L2
	;如果长度不为0则调用upword来转换大写
    
L1: MOV AL,'?'
	MOV [DI],AL
	MOV AL,'$'
	MOV [DI+1],AL
	;如果长度为0则在空串中压入‘？’
		
	;L2的作用是输出字符串
L2: MOV DL,0DH
	MOV AH,02H
	INT 21H
	MOV DL,0AH
	MOV AH,02H
	INT 21H
	;输出时注意需要输出换行与回车
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
	;入栈保护现场
	MOV CL,STRLEN
L3:	MOV BL,[SI]
	;取当前字符保存至BL
	CMP BL,30H
	JAE L4
	JMP L5
L4:	CMP BL,39H
	JA L5
	DEC STRLEN
	JMP L6
	;判断当前字符是否为数字（30H-39H）	
L5: MOV AL,[SI]
	MOV [DI],AL
	INC DI
	;如果不是数字就保存到str2,即（DI）
L6: INC SI
	LOOP L3
	POP CX
	POP SI
	POP DI
	POP AX
	POPF
	;出栈还原现场 
	RET
NONUM ENDP

UPWORD PROC
	PUSHF
	PUSH AX
	PUSH DI
	PUSH CX
	;入栈保护现场
	MOV CL,STRLEN
L7:	MOV BL,[DI]
	CMP BL,61H
	JAE L8
	JMP L9
L8: MOV AL,[DI]
	CMP AL,7AH
	;判断当前字符是否为小写字母字符
	JA L9
	;如果不是小写字母（大于7AH）则跳过
	SUB AL,20H
	MOV [DI],AL
	;如果是小写字母就改为大写（原ascll码减20）然后存入原来位置
L9:	INC DI
	LOOP L7
	MOV AL,'$'
	MOV [DI],AL
	;处理过后将$压入字符串中
	POP CX
	POP DI
	POP AX
	POPF
	;出栈还原现场
	RET
UPWORD ENDP
    
CODES ENDS
    END START
