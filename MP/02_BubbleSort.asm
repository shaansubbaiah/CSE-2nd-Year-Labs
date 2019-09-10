;       PROGRAM TO PERFORM BINARY SORT
.MODEL SMALL
.DATA
        ARR DW 01H, 07H, 03H, 09H, 13H
.CODE
        MOV AX, @DATA
        MOV DS, AX

        MOV DX, 04              ; DX = OUTER COUNTER
OUTER:
        MOV CX, DX              ; CX = INNER COUNTER
        MOV SI, OFFSET ARR
INNER:
        MOV AL, [SI]
        CMP AL, [SI+2]          ; CHANGE TO [SI+1] FOR BYTE
        JBE LP                  ; SKIPS EXCHANGE IF CONDN NOT MET
        XCHG AH, [SI]
        XCHG AH, [SI+2]
LP:
        ADD SI, 02H             ; CHANGE TO 01H FOR BYTE
        DEC CX
        JNZ INNER               ; REPEAT INNER LOOP TILL CX=0
        DEC DX
        JNZ OUTER               ; REPEAT OUTER LOOP TILL DX=0

        MOV AH, 4CH             ; END OF PROGRAM
        INT 21H
        END
