.MODEL SMALL
.STACK 100H
.DATA
    no1 DB 0ABH
    no2 DB 0F1H
    diff DB ?
    borrow DB 0

.CODE
MAIN PROC   
    MOV AX, @DATA
    MOV DS, AX

    MOV AX, 0

    MOV AL, no1
    SUB AL, no2
    MOV diff , AL

    JC SETB
    JMP EXIT

SETB:
    MOV borrow, 1
    MOV AH, borrow

EXIT:
    INT 3
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
