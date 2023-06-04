#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <Windows.h>

#include <stdbool.h>
#include <string.h>
#include <termios.h>


void disp_binary (unsigned char dato);
void retardo(unsigned long int a);
void choque (unsigned long int speed);
void auto_fantastico(unsigned long int);
void carrera (unsigned long int speed);
void semaforo_de_carrera(unsigned long int speed);
void sirena (unsigned long int speed);
void ola_humana(unsigned long int speed);



void tc_echo_off(){

	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);

}
void tc_echo_on(){

	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);

}




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
    
    do {
        getchar(); //sino toma el enter de cuando terminas el usuario
        tc_echo_off();
        printf("Ingrese su password de 5 digitos:\n");
        for (int j = 0; j < 6; j++) {
            char c = getchar();
            password[j] = c;
            //putchar('*');
            //fflush(stdout);
        }
        password[5] = 0;
        //printf("%s", password);

        for (int i = 0; i < 3; i++) {
            //printf("comparando:%s con %s\n", users[i], user);
            //printf("comparando:%s con %s\n", passwords[i], password);
            if ((strcmp(users[i], user) + strcmp(passwords[i], password)) == 0) {
                verif = true;
                printf("Bienvenido al sistema\n");
                break;
            }
        }
        if (!verif) {
            printf("Password no valida\n");
            intentos++;
        }

    } while (intentos < 3 && verif == false);

    tc_echo_on();

    if (verif == false) {
        printf("Abortando programa\n");
    } else {

        //el switch y eso

            do {    
        printf("\t -----|MENU|----- \n");
            printf("|1|. AUTO FANTASTICO\n");
            printf("|2|. CHOQUE\n");
            printf("|3|. LA CARRERA\n");
            //printf("|4|. SEMAFORO DE CARRERA\n");
            printf("|4|. OLA HUMANA\n");
            printf("|5|. SIRENA\n");
            printf("|6|. SALIR\n");
            printf("Ingrese la opcion:");
            scanf("%d",&aux);
        switch (aux) {
            case 1:
                printf("\tAUTO FANTASTICO\n\n");
                auto_fantastico(speed);
                system("pause");
                break;
            case 2:
                printf("\tCHOQUE\n\n");
                choque(speed);
                system("pause");
                break;
            case 3:
                printf("\tLA CARRERA\n\n");
                carrera(speed);
                system("pause");        
                break;
            case 4:
                printf("\tOLA HUMANA\n\n");
                //printf("\tSEMAFORO DE CARRERA\n\n");
                //semaforo_de_carrera(speed);
                ola_humana(speed);
                system("pause");        
                break;
            case 5:
                printf("\tSIRENA\n\n");
                sirena(speed);
                system("pause");        
            case 6:
                printf("Hasta la proxima\n");
                system("pause");
            default:
                printf("Opcion no valida, ingrese otro numero\n");
                system("pause");
        }
        system("cls");
    } while (aux != 6);
    }




}


void disp_binary (unsigned char dato){

  for (unsigned char mask = 128; mask > 0; mask>>=1)
    {
        if (dato&mask)
        {
            printf("*");
        }
        else {
            printf("_");
        }
    }
}

void retardo(unsigned long int a){
    while (a) a--;
}

void choque (unsigned long int speed){
  unsigned char tabla[] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42};
    while(1){

    for (int i = 0; i < 6; ++i) {
            printf("\t |EL CHOQUE|\n\n");
            printf("Presione ESC para volver al menu principal\n\n\n");
            printf("\tDelay: %d\t",speed);
            disp_binary(tabla[i]);
            retardo(speed);
            system("cls");

            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }
}

void auto_fantastico(unsigned long int speed){
  unsigned int pos = 0x80;
  while(1){
    for (int i = 0; i < 8; ++i) {
        printf("\t |AUTO FANTASICO|\n\n");
        printf("Presione ESC para volver al menu principal\n\n");
        printf("\tDelay: %d\t",speed);
        disp_binary(pos);
        pos >>= 1;
        retardo(speed);
        system("cls");

        if ((speed - 5000000) > 1000000){
                if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}

    }
    pos = 0x02;
    for (int i = 0; i < 6; ++i) {
            printf("\t |AUTO FANTASTICO|\n\n");
            printf("Presione ESC para volver al menu principal\n\n");
            printf("\tDelay: %d\t",speed);
            disp_binary(pos);
            pos <<= 1;
            retardo(speed);
            system("cls");


        if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }
}

void carrera (unsigned long int speed){
    unsigned char tabla[] = {0xA0,0x30,0x08,0x06,0x03,0x01};
    while(1){

        for (int i = 0; i < 6; ++i) {
            printf("\t |LA CARRERA| \n\n");
            printf("Presione ESC para volver al menu principal\n\n");
            printf("\tDelay: %d\t",speed); 
            disp_binary(tabla[i]);
            retardo(speed);
            system("cls");

        if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }
}

void semaforo_de_carrera(unsigned long int speed){
  unsigned int pos = 0x80;
  while(1){
    for (int i = 0; i < 3; ++i) {
        printf("\t |SEMAFORO DE CARRERA|\n\n");
        printf("Presione ESC para volver al menu principal\n\n");
        printf("\tDelay: %d\t",speed);
        disp_binary(pos);
        pos >>= 2;
        pos+=0x80;
        retardo(speed);
        system("cls");

    if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
        }
        if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
        if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}

  }
  pos = 0x80;
    for (int i = 0; i < 8; ++i) {
            printf("\t |SEMAFORO DE CARRERA|\n\n");
            printf("Presione ESC para volver al menu principal\n\n");
            printf("\tDelay: %d\t",speed/4);
            disp_binary(pos);
            pos >>= 1;
            pos+=0x80;
            retardo(speed/4);
            system("cls");

        if ((speed - 5000000) > 250000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
        }
        if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
        if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
    }
    pos = 0x80;
  }
}

void sirena (unsigned long int speed){
    unsigned char tabla[] = {0xF0, 0xF};
    
    while(1){

        for (int i = 0; i < 2; ++i) {
            printf("\t |LA SIRENA| \n\n");
            printf("Presione ESC para volver al menu principal\n\n");
            printf("\tDelay: %d\t",speed); 
            disp_binary(tabla[i]);
            retardo(speed);
            system("cls");

        if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }

}

void ola_humana(unsigned long int speed){
    unsigned int pos = 0xE0;
    while(1){
    for (int i = 0; i < 8; ++i) {
        printf("\t|OLA HUMANA|\n\n");
        printf("Presione ESC para volver al menu principal\n\n");
        printf("\tDelay: %d\t",speed);
        disp_binary(pos);
        pos >>= 1;
        retardo(speed);
        system("cls");

    if ((speed - 5000000) > 1000000){
        if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
        }
        if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
        if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}

    }
    pos = 0x07;
        for (int i = 0; i < 6; ++i) {
            printf("\t|OLA HUMANA|\n\n");
            printf("Presione ESC para volver al menu principal\n\n");
            printf("\tDelay: %d\t",speed);
            disp_binary(pos);
            pos <<= 1;
            retardo(speed);
            system("cls");

            if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }
}