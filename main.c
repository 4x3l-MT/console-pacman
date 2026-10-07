#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 15
#define COLUMNAS 21

const char MAPA_1[FILAS][COLUMNAS] = {
    "####################",
    "#C...#..........#..#",
    "#.##.#.######.##.#.#",
    "#.#..............#.#",
    "#.#.##.###.###.##..#",
    "#......#F...#......#",
    "#####.##.###.##.####",
    "#........F.........#",
    "#####.##.###.##.####",
    "#......#...F#......#",
    "#.#.##.###.###.##..#",
    "#.#..............#.#",
    "#.##.#.######.##.#.#",
    "#....#..........#..#",
    "####################"
};

const char MAPA_2[FILAS][COLUMNAS] = {
    "####################",
    "#C........##.......#",
    "#.######.####.####.#",
    "#.#......#F......#.#",
    "#.#.####.#.####.##.#",
    "#...#....#....#....#",
    "###.#.#######.#.####",
    "#...#....F....#....#",
    "####.#.#######.#.###",
    "#....#....#....#...#",
    "#.##.####.#.####.#.#",
    "#.#......F#......#.#",
    "#.####.####.######.#",
    "#.......##.........#",
    "####################"
};

const char MAPA_3[FILAS][COLUMNAS] = {
    "####################",
    "#C....#......#....F#",
    "#.###.#.####.#.###.#",
    "#.#......##......#.#",
    "#.#.####.##.####.#.#",
    "#...#...F.......#..#",
    "##.##.########.##.##",
    "#........##........#",
    "##.##.########.##.##",
    "#..#.......F...#...#",
    "#.#.####.##.####.#.#",
    "#.#......##......#.#",
    "#.###.#.####.#.###.#",
    "#....F#......#.....#",
    "####################"
};

void cargarMapaAleatorio(char mapaDestino[FILAS][COLUMNAS]);

int main() {
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
            case 1:
                printf("\nIniciando el juego...\n");
                // Proximamente: Inicializacion y ciclo principal del juego
                printf("\nPresiona ENTER para volver al menu...");
                getchar();
                getchar();
                break;

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

void cargarMapaAleatorio(char mapaDestino[FILAS][COLUMNAS]) {
    int seleccion = rand() % 3;

    const char (*mapaElegido)[COLUMNAS];

    switch (seleccion) {
        case 0:
            mapaElegido = MAPA_1;
            break;
        case 1:
            mapaElegido = MAPA_2;
            break;
        case 2:
            mapaElegido = MAPA_3;
            break;
        default:
            mapaElegido = MAPA_1;
            break;
    }
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            mapaDestino[i][j] = mapaElegido[i][j];
        }
    }
}