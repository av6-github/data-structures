.MODEL SMALL
.STACK 100H
.DATA
    no1 DB 120
    no2 DB 7
    quotient DB ?
    remainder DB ?

.CODE
MAIN PROC   
    MOV AX, @DATA
    MOV DS, AX

    MOV AX, 0

    MOV AL, no1
    DIV no2

    MOV quotient , AL
    MOV remainder, AH

    INT 3
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
