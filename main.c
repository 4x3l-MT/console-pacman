#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mapa.h"

int main() {
    srand((unsigned int)time(NULL));

    int opcion = 0;
    int salir = 0;

    while (!salir) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("PACMAN EN CONSOLA\n");
        printf("1. Jugar\n");
        printf("2. Instrucciones\n");
        printf("3. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char mapaActual[FILAS][COLUMNAS];
                int puntuacion = 0;
                int vidas = 3;

                // 1. Seleccionar e inicializar mapa
                cargarMapaAleatorio(mapaActual);

                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                // 2. Renderizar pantalla inicial del juego
                mostrarMapa(mapaActual, puntuacion, vidas);

                printf("\nPresiona ENTER para volver al menu...");
                getchar(); // Limpia buffer del scanf
                getchar(); // Espera ENTER
                break;
            }

            case 2:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                printf("INSTRUCCIONES\n");
                printf("- Usa W/A/S/D o las flechas para mover a Pacman (C).\n");
                printf("- Come todos los puntos (.) para ganar el nivel.\n");
                printf("- Esquiva a los fantasmas (F).\n");
                printf("- Empiezas con 3 vidas.\n");
                printf("\nPresiona ENTER para volver al menu...");
                getchar();
                getchar();
                break;

            case 3:
                printf("\nGracias por jugar\n");
                salir = 1;
                break;

            default:
                printf("\nOpcion invalida. Intenta de nuevo.\n");
                printf("Presiona ENTER para continuar...");
                getchar();
                getchar();
                break;
        }
    }

    return 0;
}