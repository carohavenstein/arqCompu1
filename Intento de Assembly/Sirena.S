.text
.global sirena
sirena:
    mov r0, speed           @ Mueve el valor de speed al registro r0
    ldr r1, =tabla          @ Carga la dirección de memoria de la tabla en r1
    mov r2, #2              @ Mueve el valor 2 al registro r2 (contador del bucle externo)

loop:
    mov r3, #0              @ Reinicia el contador del bucle interno
    ldrb r4, [r1, r3]       @ Carga el byte de la tabla en r4 (primer elemento)

inner_loop:
    bl disp_binary          @ Llama a la función disp_binary
    bl retardo              @ Llama a la función retardo
    bl system               @ Llama a la función system con el argumento "cls"

    add r3, #1              @ Incrementa el contador del bucle interno
    cmp r3, r2              @ Compara el contador con el valor del bucle externo
    blt inner_loop          @ Salta al bucle interno si el contador es menor que r2

    cmp r2, #0              @ Compara el contador del bucle externo con cero
    bne loop                @ Salta al bucle externo si el contador no es igual a cero

    bx lr                   @ Vuelve de la subrutina

.section .data
tabla:
    .byte 0xF0, 0x0F       @ Definición de la tabla de luces
