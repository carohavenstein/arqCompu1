#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
//#include "EasyPIO.h"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>

void disp_binary (unsigned char dato);
void retardo(unsigned long int a);

void choque (unsigned long int speed);
void auto_fantastico(unsigned long int);
void sirena (unsigned long int speed);
void tren(unsigned long int speed);

int controlSpeed(unsigned long int* speed, char c);
void restoreTerminalMode();
void setNonblockingTerminalMode();
void tc_echo_off();
void tc_echo_on();

int main() {

    unsigned long int speedini = 150000000;
    unsigned long int speed = 150000000;
    speed = speedini;

    int aux = 0;
    
    //char arr[r][s] = ...
    //r = size del arreglo
    //s = cantidad maxima de caracteres que puede almacenar cada string

    char users[][8] = {"mish\0", "igna\0", "caro\0"}; 
    char passwords[][6] = {"miche\0", "igna1\0", "patos\0"};

        /*
        
            for (int i = 0; i < 3; i++) {
                printf("%s\n", users[i]);
            }

            for (int j = 0; j < 3; j++) {
                printf("%s\n", passwords[j]);
            }
        
        */

    char user[8];
    char password[6];
    int intentos = 0;
    bool verif = false;
    
    printf("Iniciar sesion:\n");
    printf("Usuario:\n");
    scanf("%s", user);

    getchar(); //sino toma el enter de cuando terminas el usuario
    do {
        //printf("passs antes: %s\n", password);
        tc_echo_off();
        
        initscr();
        printw("Ingrese su password de 5 digitos:\n");
        refresh();
        for (int j = 0; j < 6; j++) {
            char c = getchar();
            password[j] = c;
            addch('*');
            refresh();
            //putchar('*');
            //fflush(stdout);
        }
        password[5] = 0;
        //printf("pass post: %s\n", password);
        
        system("clear");

        for (int i = 0; i < 3; i++) {
            //printf("comparando:%s con %s\n", users[i], user);
            //printf("comparando:%s con %s\n", passwords[i], password);
            //printf("verif: %d\n", verif);
            if ((strcmp(users[i], user) + strcmp(passwords[i], password)) == 0) {
                verif = true;
                printw("Bienvenido al sistema\n");
                refresh();
                //printf("verif: %d\n", verif);
                break;
            }
        }
        if (!verif) {
            printw("Password no valida\n");
            refresh();
            intentos++;
        }

    } while (intentos < 3 && verif == false);
    
    endwin();
    tc_echo_on();
    system("clear");

    if (verif == false) {
        printf("Abortando programa\n");
    } else {
        printf("Llego al switch\n");
        
        do {
            restoreTerminalMode();
            system("clear");
            printf("\t -----|MENU|----- \n");
            printf("|1|. AUTO FANTASTICO\n");
            printf("|2|. CHOQUE\n");
            printf("|3|. TREN\n");
            printf("|4|. SIRENA\n");
            printf("|5|. SALIR\n");
            printf("Ingrese la opcion:");
            scanf("%d", &aux);
            switch (aux) {
                case 1:
                    printf("\tAUTO FANTASTICO\n\n");
                    auto_fantastico(speed);
                    system("clear");
                    break;
                case 2:
                    printf("\tCHOQUE\n\n");
                    choque(speed);
                    system("clear");
                    break;
                case 3:
                    printf("\tTREN\n\n");
                    tren(speed);
                    system("clear");
                    break;
                case 4:
                    printf("\tSIRENA\n\n");
                    sirena(speed);
                    system("clear");
                case 5:
                    printf("Hasta la proxima\n");
                    system("clear");
                default:
                    printf("Opcion no valida, ingrese otro numero\n");
                    system("clear");
                }
        } while (aux != 5);
        system("clear");
        
    }
    restoreTerminalMode();
}

    
void setNonblockingTerminalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    term.c_cc[VTIME] = 0;
    term.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    setbuf(stdin, NULL);
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void restoreTerminalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
}

void disp_binary(unsigned char dato){

    for (unsigned char mask = 128; mask > 0; mask >>= 1){
        if (dato & mask){
            printf("*");
        }
        else{
            printf("_");
        }
    }
}

void retardo(unsigned long int a){
    while (a)
    a--;
}

void choque (unsigned long int speed){
    setNonblockingTerminalMode();
    int running = 1;
    char c;

    unsigned char tabla[] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42};
    while(running){

        for (int i = 0; i < 6; ++i) {
            printf("\t |EL CHOQUE|\n\n");
            printf("Presione E para volver al menu principal\n\n\n");
            printf("\tDelay: %ld\t",speed);
            disp_binary(tabla[i]);
            retardo(speed);
            system("clear");

            running = controlSpeed(&speed, c);
            if (running == 0) {
                return;
            }
        }
    }
}

void auto_fantastico(unsigned long int speed){
    setNonblockingTerminalMode();
    int running = 1;
    char c;

    unsigned int pos = 0x80;
    while(running){
        for (int i = 0; i < 8; ++i) {
            printf("\t |AUTO FANTASTICO|\n\n");
            printf("Presione E para volver al menu principal\n\n");
            printf("\tDelay: %ld\t",speed);
            disp_binary(pos);
            pos >>= 1;
            retardo(speed);
            system("clear");

            running = controlSpeed(&speed, c);
            if (running == 0) {
                return;
            }

        }
        pos = 0x02;
        for (int i = 0; i < 6; ++i) {
            printf("\t |AUTO FANTASTICO|\n\n");
            printf("Presione E para volver al menu principal\n\n");
            printf("\tDelay: %ld\t",speed);
            disp_binary(pos);
            pos <<= 1;
            retardo(speed);
            system("clear");

            running = controlSpeed(&speed, c);
            if (running == 0) {
                return;
            }
            
        }
    }
}

int controlSpeed(unsigned long int* speed, char c) {
    ssize_t bytesRead = read(STDIN_FILENO, &c, 1);
    if (bytesRead > 0) {
        if (c == 'e') {
            return 0;
        } else if (c == '\033') {
            char arrow;
            ssize_t arrowBytesRead = read(STDIN_FILENO, &arrow, 1);

            if (arrowBytesRead > 0 && arrow == '[') {
                char direction;
                ssize_t directionBytesRead = read(STDIN_FILENO, &direction, 1);
                    
                if (directionBytesRead > 0) {
                    if (direction == 'A') {
                        //printf("Tecla presionada: Flecha hacia arriba\n");
                        if ((*speed - 5000000) > 1000000){*speed += 5000000;}
                    } else if (direction == 'B') {
                        //printf("Tecla presionada: Flecha hacia abajo\n");
                        *speed -= 5000000;
                    }
                }
            }
        }
    }    
}

void sirena (unsigned long int speed){
    setNonblockingTerminalMode();
    int running = 1;
    char c;

    unsigned char tabla[] = {0xF0, 0xF};
    
    while(running){

        for (int i = 0; i < 2; ++i) {
            printf("\t |SIRENA| \n\n");
            printf("Presione E para volver al menu principal\n\n");
            printf("\tDelay: %ld\t",speed); 
            disp_binary(tabla[i]);
            retardo(speed);
            system("clear");

            running = controlSpeed(&speed, c);
            if (running == 0) {
                return;
            }
        }
    }

}

void tren(unsigned long int speed){
    setNonblockingTerminalMode();
    int running = 1;
    char c;

    while(running){

        unsigned int pos = 0xE0;
        for (int i = 0; i < 8; ++i) {
            printf("\t|TREN|\n\n");
            printf("Presione E para volver al menu principal\n\n");
            printf("\tDelay: %ld\t",speed);
            disp_binary(pos);
            pos >>= 1;
            retardo(speed);
            system("clear");

            running = controlSpeed(&speed, c);
            if (running == 0) {
                return;
            }

        }
    
        pos = 0xE0;
        for (int i = 6; i < 0; ++i) {
            printf("\t|TREN|\n\n");
            printf("Presione E para volver al menu principal\n\n");
            printf("\tDelay: %ld\t",speed);
            disp_binary(pos);
            pos <<= 1;
            retardo(speed);
            system("clear");

            running = controlSpeed(&speed, c);
            if (running == 0) {
                return;
            }
        }
    }
    
}

void tc_echo_off() {
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(1, TCSANOW, &term);
}

void tc_echo_on() {
    struct termios term;
    tcgetattr(1, &term);
    term.c_lflag |= ECHO;
    tcsetattr(1, TCSANOW, &term);
}