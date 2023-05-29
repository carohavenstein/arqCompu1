#include <stdio.h>
#include <stdlib.h>

int main() {
    int aux = 0;
    do {    
        printf("Seleccione\n");
            printf("|1| Auto fantastico\n");
            printf("|2| Choque\n");
            printf("|3| La carrera\n");
            printf("|4| \n");
            printf("|5|\n");
            printf("|6| Salir\n");
            scanf("%d",&aux);
        switch (aux) {
            case 1:
                printf("Auto fantastico\n");
                system("cls");
                break;
            case 2:
                printf("Choque\n");
                system("cls");
                break;
            case 3:
                printf("La carrera\n");
                system("cls");        
                break;
            case 4:
                system("cls");        
                break;
            case 5:
                system("cls");        
            case 6:
                printf("Hasta la proxima\n");
                system("cls");
            default:
                printf("Opcion no valida, ingrese otro numero\n");
                system("cls");
        }
    } while (aux != 6);


}