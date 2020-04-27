; Lorenzo Cauli 3C
.model small
.stack 100h
.data
TEN	DB	10
N	DB	0
MSG	DB	"Inserire un numero$"
TMP	DB	0
.code
START:
	MOV AX,@DATA
	MOV DS,AX
	CALL STRING
	CALL CAPO
	CALL LEGGI
	CALL CAPO
	CALL SCRIVI
	MOV AH,4Ch
	INT 21h
LEGGI PROC NEAR
	MOV AH,01h
	INT 21h
	SUB AL,48
	MUL TEN
	MOV N,AL
	MOV AH,01h
	INT 21h
	SUB AL,48
	ADD N,AL
	RET
	ENDP
CAPO PROC NEAR
	MOV DL,13
	MOV AH,02h
	INT 21h
	MOV DL,10
	MOV AH,02h
	INT 21h
	RET
	ENDP
SCRIVI PROC NEAR
	MOV AX,0
	MOV AL,N
	DIV TEN
	MOV TMP,AH
	MOV DL,AL
	ADD DL,48
	MOV AH,02h
	INT 21h
	MOV DL,TMP
	ADD DL,48
	MOV AH,02h
	INT 21h
	RET
	ENDP
STRING PROC NEAR
	LEA DX,MSG
	MOV AH,09h
	INT 21h
	RET
	ENDP
END START
