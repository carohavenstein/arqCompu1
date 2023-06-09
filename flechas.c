#include <ncurses.h>

void auto_fantastico(unsigned long int speed) {
    initscr(); // Inicia modo curses
    raw(); // Para que no sea necesario presionar Enter para leer el carácter
    noecho();
    keypad(stdscr, TRUE);

    unsigned int pos = 0x80;
    int ch;
    bool exit_flag = false;

    while (!exit_flag) {
        ch = getch();
        switch (ch) {
            case KEY_UP:
                if ((speed - 5000000) > 1000000) {
                    speed += 5000000;
                }
                break;
            case KEY_DOWN:
                speed -= 5000000;
                break;
            case 27: // Tecla ESC
                exit_flag = true;
                break;
        }

        for (int i = 0; i < 8; ++i) {
            printf("\t |AUTO FANTASTICO|\n\n");
            printf("Presione ESC para volver al menú principal\n\n");
            printf("\tDelay: %lu\t", speed);
            // disp_binary(pos);
            pos >>= 1;
            // retardo(speed);
            // system("clear");
            refresh();
            napms(speed/1000); // Ajusta la velocidad en milisegundos (ms)

            if (exit_flag) {
                break;
            }
        }
        pos = 0x02;
        for (int i = 0; i < 6; ++i) {
            printf("\t |AUTO FANTASTICO|\n\n");
            printf("Presione ESC para volver al menú principal\n\n");
            printf("\tDelay: %lu\t", speed);
            // disp_binary(pos);
            pos <<= 1;
            // retardo(speed);
            // system("clear");
            refresh();
            napms(speed/1000); // Ajusta la velocidad en milisegundos (ms)

            if (exit_flag) {
                break;
            }
        }
    }

    endwin(); // Finaliza modo curses
}

int main() {
    unsigned long int speed = 5000000;
    auto_fantastico(speed);
    return 0;
}