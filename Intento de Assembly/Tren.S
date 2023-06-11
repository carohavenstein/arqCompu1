.global tren
tren:
    mov r0, speed      @ Mueve el valor de speed al registro r0

outer_loop:
    mov r1, #0xE0      @ Mueve el valor 0xE0 a r1 (posición inicial)

    mov r2, #8         @ Mueve el valor 8 a r2 (contador del bucle externo)
    inner_loop_1:
        bl disp_binary @ Llama a la función disp_binary para mostrar el valor en r1
        lsr r1, r1, #1 @ Desplaza lógicamente hacia la derecha r1 en 1 bit
        bl retardo     @ Llama a la función retardo para introducir un retardo
        bl system      @ Llama a la función system con el argumento "cls"

        subs r2, r2, #1 @ Resta 1 al contador del bucle externo
        bne inner_loop_1 @ Salta a inner_loop_1 si el contador no es igual a cero

    mov r1, #0xE0      @ Reinicia el valor de r1 a 0xE0

    mov r2, #6         @ Mueve el valor 6 a r2 (contador del bucle externo)
    inner_loop_2:
        bl disp_binary @ Llama a la función disp_binary para mostrar el valor en r1
        lsl r1, r1, #1 @ Desplaza lógicamente hacia la izquierda r1 en 1 bit
        bl retardo     @ Llama a la función retardo para introducir un retardo
        bl system      @ Llama a la función system con el argumento "cls"

        subs r2, r2, #1 @ Resta 1 al contador del bucle externo
        bne inner_loop_2 @ Salta a inner_loop_2 si el contador no es igual a cero

    b outer_loop       @ Salta de nuevo al bucle outer_loop
