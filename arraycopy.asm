data segment
        a1 db 02h,04h,08h
        count db 3
        a2 db 50 dup(?)
        data ends
code segment 
    assume cs:code ds:data
    start:
    mov ax,data
    mov ds,ax
    mov si,offset a1
    mov di,offset a2
    mov cl,count
    next:
    mov al,[si]
    mov [di],al
    inc di
    inc si
    dec cl
    jz xx
    jmp next
    xx:
    mov ah,4ch
    int 21h
code ends
end start
