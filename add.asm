.MODEL SMALL
.STACK 100H
.DATA
    no1 DB 0ABH
    no2 DB 0F1H
    sum DB ?
    carry DB 0

.CODE
MAIN PROC   
    MOV AX, @DATA
    MOV DS, AX

    MOV AX, 0

    MOV AL, no1
    ADD AL, no2
    MOV sum , AL

    JC SETC
    JMP EXIT

SETC:
    MOV carry, 1
    MOV AH, carry

EXIT:
    INT 3
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
