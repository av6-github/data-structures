.MODEL SMALL
.STACK 100H
.DATA
    no1 DB 0ABH
    no2 DB 0F1H
    prod_low DB ?
    prod_high DB 0

.CODE
MAIN PROC   
    MOV AX, @DATA
    MOV DS, AX

    MOV AX, 0

    MOV AL, no1
    MUL no2 ; MUL -> AX = AL * operand

    MOV prod_low , AL
    MOV prod_high, AH

    INT 3
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
