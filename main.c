#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mapa.h"
#include "fantasma.h"

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
                Fantasma fantasmas[MAX_FANTASMAS];
                int puntuacion = 0;
                int vidas = 3;
                int pacmanFila = 1, pacmanCol = 1;
                char pacmanDir = 'D';

                // 1. Cargar el mapa aleatorio
                cargarMapaAleatorio(mapaActual);

                // 2. Inicializar posiciones y personalidades de los fantasmas
                int numFantasmas = inicializarFantasmas(mapaActual, fantasmas);

                // 3. Buscar la posicion inicial de Pacman ('C')
                for (int i = 0; i < FILAS; i++) {
                    for (int j = 0; j < COLUMNAS; j++) {
                        if (mapaActual[i][j] == 'C') {
                            pacmanFila = i;
                            pacmanCol = j;
                        }
                    }
                }

                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                // Renderizar estado inicial
                mostrarMapa(mapaActual, puntuacion, vidas);

                // Ejemplo de llamada a movimiento de fantasmas en el ciclo del juego:
                // moverFantasmas(mapaActual, fantasmas, numFantasmas, pacmanFila, pacmanCol, pacmanDir);

                printf("\nPresiona ENTER para volver al menu...");
                getchar();
                getchar();
                break;
            }

            case 2:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                printf("INSTRUCCIONES\n");
                printf("- Usa W/A/S/D para mover a Pacman (C).\n");
                printf("- Blinky (Rojo): Te persigue directamente.\n");
                printf("- Pinky (Rosa): Trata de emboscarte por delante.\n");
                printf("- Inky (Cian): Movimiento impredecible.\n");
                printf("- Clyde (Naranja): Se acerca si estas lejos y se aleja si te le aproximas.\n");
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