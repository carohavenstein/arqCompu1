.text

.extern disp_binary
.extern retardo

.global sirena

sirena:
      PUSH {R4, R5, R6, LR}
    MOV R4, #0
    MOV R5, #2 ; Cant de bytes 
loop:
    LDR R6, =tabla
    LDRB R6, [R6,R4]
    ADD R4, R4, #1
    MOV R0, R6
    BL disp_binary ; Llamada a la función mostrar
    MOV R0, speed
    BL retardo ; Llamada a la función retardo y guarda el resultado en R0
    MOV speed, R0 ; Actualiza el valor de speed con el resultado del retardo
    CMP speed, #0
    BEQ salida
    BNE loop
salida:
    POP {R4,R5,R6, PC}


.data tabla:
      .byte 0xF0, 0x0F
.end




