DATA SEGMENT
    msg1 db 10,13,'Enter the string : $'
    msg2 db 10,13,'Enter the character : $'
    msg3 db 10,13,'Found$'
    msg4 db 10,13,'Not found$'
    str1 db 50 dup(?)
    DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:
        MOV AX,DATA
        MOV DS,AX
        LEA DX,msg1
        MOV AH,09H
        INT 21H
        
        LEA SI,str1
        LEA DI,str1
        
    NEXT:
        MOV AH,01H
        INT 21H
        CMP AL,13
        JE TERMINATE
        MOV [DI],AL
        INC DI
        JMP NEXT
    TERMINATE:
        MOV AL,'$'
        MOV [DI],AL
        LEA DX,msg2
        MOV AH,09H
        INT 21H
        MOV AH,01H
        INT 21H
        MOV DL,AL
    SEARCH:
        CMP [SI],DL
        JE FOUND
        CMP [SI],'$'
        JE NOTFOUND
        INC SI
        JMP SEARCH
    FOUND:
        LEA DX,msg3
        MOV AH,09H
        INT 21H
        JMP ENDPROGRAM
    NOTFOUND:
        LEA DX,msg4
        MOV AH,09H
        INT 21H
    ENDPROGRAM:
        MOV AH,4CH
        INT 21H
    CODE ENDS
END START
