#include <ncurses.h>

int main() {
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    halfdelay(10);
    

    int ch = getch();
    printf("%d", ch);
    if (ch == 27) {
        printf("Apretaste esc!");
        refresh();   
    }

    if (ch == KEY_UP) {
        printf("Apretaste flecha arriba!");
        refresh();   
    }

    if (ch == KEY_DOWN) {
        printf("Apretaste flecha abajo!");
        refresh();   
    }

    //getch();
    endwin();
}