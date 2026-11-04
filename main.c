#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 15
#define COLUMNAS 21

// --- MAPAS PREDEFINIDOS (CONSTANTES) ---
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

// --- PROTOTIPOS DE FUNCIONES ---
void cargarMapaAleatorio(char mapaDestino[FILAS][COLUMNAS]);
void mostrarMapa(char mapa[FILAS][COLUMNAS], int puntuacion, int vidas);
int esMovimientoValido(char mapa[FILAS][COLUMNAS], int nuevaFila, int nuevaColumna);

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

// --- DEFINICIÓN DE FUNCIONES ---

void cargarMapaAleatorio(char mapaDestino[FILAS][COLUMNAS]) {
    int seleccion = rand() % 3;
    const char (*mapaElegido)[COLUMNAS];

    switch (seleccion) {
        case 0: mapaElegido = MAPA_1; break;
        case 1: mapaElegido = MAPA_2; break;
        case 2: mapaElegido = MAPA_3; break;
        default: mapaElegido = MAPA_1; break;
    }

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            mapaDestino[i][j] = mapaElegido[i][j];
        }
    }
}

// Muestra el estado actual de la partida y la matriz completa
void mostrarMapa(char mapa[FILAS][COLUMNAS], int puntuacion, int vidas) {
    printf("Puntuacion: %d | Vidas: %d\n\n", puntuacion, vidas);
    for (int i = 0; i < FILAS; i++) {
        printf("%s\n", mapa[i]);
    }
}

// Comprobación genérica de casilla (usada posteriormente por Pacman y Fantasmas)
int esMovimientoValido(char mapa[FILAS][COLUMNAS], int nuevaFila, int nuevaColumna) {
    // 1. Validar limites de la matriz
    if (nuevaFila < 0 || nuevaFila >= FILAS || nuevaColumna < 0 || nuevaColumna >= COLUMNAS - 1) {
        return 0;
    }
    // 2. Comprobar que no sea una pared '#'
    if (mapa[nuevaFila][nuevaColumna] == '#') {
        return 0;
    }
    return 1;
}