disp_binary:                            // @disp_binary
        sub     sp, sp, #32
        stp     x29, x30, [sp, #16]             // 16-byte Folded Spill
        add     x29, sp, #16
        sturb   w0, [x29, #-1]
        mov     w8, #128                        // =0x80
        sturb   w8, [x29, #-2]
        b       .LBB0_1
.LBB0_1:                                // =>This Inner Loop Header: Depth=1
        ldurb   w8, [x29, #-2]
        subs    w8, w8, #0
        cset    w8, le
        tbnz    w8, #0, .LBB0_7
        b       .LBB0_2
.LBB0_2:                                //   in Loop: Header=BB0_1 Depth=1
        ldurb   w8, [x29, #-1]
        ldurb   w9, [x29, #-2]
        ands    w8, w8, w9
        cset    w8, eq
        tbnz    w8, #0, .LBB0_4
        b       .LBB0_3
.LBB0_3:                                //   in Loop: Header=BB0_1 Depth=1
        adrp    x0, .L.str
        add     x0, x0, :lo12:.L.str
        bl      printf
        b       .LBB0_5
.LBB0_4:                                //   in Loop: Header=BB0_1 Depth=1
        adrp    x0, .L.str.1
        add     x0, x0, :lo12:.L.str.1
        bl      printf
        b       .LBB0_5
.LBB0_5:                                //   in Loop: Header=BB0_1 Depth=1
        b       .LBB0_6
.LBB0_6:                                //   in Loop: Header=BB0_1 Depth=1
        ldurb   w8, [x29, #-2]
        asr     w8, w8, #1
        sturb   w8, [x29, #-2]
        b       .LBB0_1
.LBB0_7:
        ldp     x29, x30, [sp, #16]             // 16-byte Folded Reload
        add     sp, sp, #32
        ret
retardo:                                // @retardo
        sub     sp, sp, #16
        str     x0, [sp, #8]
        b       .LBB1_1
.LBB1_1:                                // =>This Inner Loop Header: Depth=1
        ldr     x8, [sp, #8]
        subs    x8, x8, #0
        cset    w8, eq
        tbnz    w8, #0, .LBB1_3
        b       .LBB1_2
.LBB1_2:                                //   in Loop: Header=BB1_1 Depth=1
        ldr     x8, [sp, #8]
        subs    x8, x8, #1
        str     x8, [sp, #8]
        b       .LBB1_1
.LBB1_3:
        add     sp, sp, #16
        ret
sirena:                                 // @sirena
        sub     sp, sp, #32
        stp     x29, x30, [sp, #16]             // 16-byte Folded Spill
        add     x29, sp, #16
        str     x0, [sp, #8]
        adrp    x8, .L__const.sirena.tabla
        add     x8, x8, :lo12:.L__const.sirena.tabla
        ldrh    w8, [x8]
        strh    w8, [sp, #6]
        b       .LBB2_1
.LBB2_1:                                // =>This Loop Header: Depth=1
        str     wzr, [sp]
        b       .LBB2_2
.LBB2_2:                                //   Parent Loop BB2_1 Depth=1
        ldr     w8, [sp]
        subs    w8, w8, #2
        cset    w8, ge
        tbnz    w8, #0, .LBB2_5
        b       .LBB2_3
.LBB2_3:                                //   in Loop: Header=BB2_2 Depth=2
        adrp    x0, .L.str.2
        add     x0, x0, :lo12:.L.str.2
        bl      printf
        adrp    x0, .L.str.3
        add     x0, x0, :lo12:.L.str.3
        bl      printf
        ldr     x1, [sp, #8]
        adrp    x0, .L.str.4
        add     x0, x0, :lo12:.L.str.4
        bl      printf
        ldrsw   x9, [sp]
        add     x8, sp, #6
        ldrb    w0, [x8, x9]
        bl      disp_binary
        ldr     x0, [sp, #8]
        bl      retardo
        adrp    x0, .L.str.5
        add     x0, x0, :lo12:.L.str.5
        bl      system
        b       .LBB2_4
.LBB2_4:                                //   in Loop: Header=BB2_2 Depth=2
        ldr     w8, [sp]
        add     w8, w8, #1
        str     w8, [sp]
        b       .LBB2_2
.LBB2_5:                                //   in Loop: Header=BB2_1 Depth=1
        b       .LBB2_1
tren:                                   // @tren
        sub     sp, sp, #48
        stp     x29, x30, [sp, #32]             // 16-byte Folded Spill
        add     x29, sp, #32
        stur    x0, [x29, #-8]
        b       .LBB3_1
.LBB3_1:                                // =>This Loop Header: Depth=1
        mov     w8, #224                        // =0xe0
        stur    w8, [x29, #-12]
        str     wzr, [sp, #16]
        b       .LBB3_2
.LBB3_2:                                //   Parent Loop BB3_1 Depth=1
        ldr     w8, [sp, #16]
        subs    w8, w8, #8
        cset    w8, ge
        tbnz    w8, #0, .LBB3_5
        b       .LBB3_3
.LBB3_3:                                //   in Loop: Header=BB3_2 Depth=2
        adrp    x0, .L.str.6
        add     x0, x0, :lo12:.L.str.6
        bl      printf
        adrp    x0, .L.str.3
        add     x0, x0, :lo12:.L.str.3
        bl      printf
        ldur    x1, [x29, #-8]
        adrp    x0, .L.str.4
        add     x0, x0, :lo12:.L.str.4
        bl      printf
        ldur    w0, [x29, #-12]
        bl      disp_binary
        ldur    w8, [x29, #-12]
        lsr     w8, w8, #1
        stur    w8, [x29, #-12]
        ldur    x0, [x29, #-8]
        bl      retardo
        adrp    x0, .L.str.5
        add     x0, x0, :lo12:.L.str.5
        bl      system
        b       .LBB3_4
.LBB3_4:                                //   in Loop: Header=BB3_2 Depth=2
        ldr     w8, [sp, #16]
        add     w8, w8, #1
        str     w8, [sp, #16]
        b       .LBB3_2
.LBB3_5:                                //   in Loop: Header=BB3_1 Depth=1
        mov     w8, #224                        // =0xe0
        stur    w8, [x29, #-12]
        mov     w8, #6                          // =0x6
        str     w8, [sp, #12]
        b       .LBB3_6
.LBB3_6:                                //   Parent Loop BB3_1 Depth=1
        ldr     w8, [sp, #12]
        subs    w8, w8, #0
        cset    w8, ge
        tbnz    w8, #0, .LBB3_9
        b       .LBB3_7
.LBB3_7:                                //   in Loop: Header=BB3_6 Depth=2
        adrp    x0, .L.str.6
        add     x0, x0, :lo12:.L.str.6
        bl      printf
        adrp    x0, .L.str.3
        add     x0, x0, :lo12:.L.str.3
        bl      printf
        ldur    x1, [x29, #-8]
        adrp    x0, .L.str.4
        add     x0, x0, :lo12:.L.str.4
        bl      printf
        ldur    w0, [x29, #-12]
        bl      disp_binary
        ldur    w8, [x29, #-12]
        lsl     w8, w8, #1
        stur    w8, [x29, #-12]
        ldur    x0, [x29, #-8]
        bl      retardo
        adrp    x0, .L.str.5
        add     x0, x0, :lo12:.L.str.5
        bl      system
        b       .LBB3_8
.LBB3_8:                                //   in Loop: Header=BB3_6 Depth=2
        ldr     w8, [sp, #12]
        add     w8, w8, #1
        str     w8, [sp, #12]
        b       .LBB3_6
.LBB3_9:                                //   in Loop: Header=BB3_1 Depth=1
        b       .LBB3_1
.L.str:
        .asciz  "*"

.L.str.1:
        .asciz  "_"

.L__const.sirena.tabla:
        .ascii  "\360\017"

.L.str.2:
        .asciz  "\t |LA SIRENA| \n\n"

.L.str.3:
        .asciz  "Presione ESC para volver al menu principal\n\n"

.L.str.4:
        .asciz  "\tDelay: %d\t"

.L.str.5:
        .asciz  "cls"

.L.str.6:
        .asciz  "\t|OLA HUMANA|\n\n"