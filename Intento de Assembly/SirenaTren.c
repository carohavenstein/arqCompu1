
#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include <stdbool.h>
#include <string.h>


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

        /*if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}*/
        }
    }

}

void tren(unsigned long int speed){
    while(1){

    unsigned int pos = 0xE0;
        for (int i = 0; i < 8; ++i) {
            printf("\t|OLA HUMANA|\n\n");
            printf("Presione ESC para volver al menu principal\n\n");
            printf("\tDelay: %d\t",speed);
            disp_binary(pos);
            pos >>= 1;
            retardo(speed);
            system("cls");

        /*if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}*/

        }
    
    pos = 0xE0;
        for (int i = 6; i < 0; ++i) {
            printf("\t|OLA HUMANA|\n\n");
            printf("Presione ESC para volver al menu principal\n\n");
            printf("\tDelay: %d\t",speed);
            disp_binary(pos);
            pos <<= 1;
            retardo(speed);
            system("cls");

            /*if ((speed - 5000000) > 1000000){
            if(GetAsyncKeyState(VK_UP) & 0x0001){speed += 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){speed -= 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}*/
        }
    }
    
}
