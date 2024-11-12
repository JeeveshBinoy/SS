DATA SEGMENT
    msg1 db 10,13, 'Number found$'
    msg2 db 10,13, 'Number not found$'
    array db 10h,10h,30h,40h,50h
    length equ 5
    search equ 10h
    DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:
        MOV AX,DATA
        MOV DS,AX
        LEA SI,array
        MOV CL,length
        MOV AX,00H
        MOV BL,search
    S_LOOP:
        MOV AL,[SI]
        CMP AL,BL
        JE F_LOOP
        INC SI
        DEC CL
        JNZ S_LOOP
        LEA DX,msg2 
        MOV AH,09H
        INT 21H
        JMP OVER
    F_LOOP:
        LEA DX,msg1
        MOV AH,09H
        INT 21H
    OVER:
        MOV AH,4CH
        INT 21H   
CODE ENDS
END START
