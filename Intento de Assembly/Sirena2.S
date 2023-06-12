.text
.global sirena

.extern disp_binary

sirena
    STMFD SP!,{R4, R5, R6, LR}
    MOV R4, #0
    MOV R5, #2

loop
    LDR R6, =tabla
    LDRB R6, [R6, R4]
    MOV R0, R6
    BL disp_binary
    MOV R0, R5
    MOV R5, R0
    CMP R5, #0
    BEQ exit
    BNE loop

exit
   LDMFD SP!,{R4, R5, R6, PC}

.data 
tabla:
    .byte 0xF0
    .byte 0xF
    