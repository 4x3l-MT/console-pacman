#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

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

void mostrarMapa(char mapa[FILAS][COLUMNAS], int puntuacion, int vidas) {
    printf("Puntuacion: %d | Vidas: %d\n\n", puntuacion, vidas);
    for (int i = 0; i < FILAS; i++) {
        printf("%s\n", mapa[i]);
    }
}

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