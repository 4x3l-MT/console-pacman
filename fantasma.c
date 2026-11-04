#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fantasma.h"

int inicializarFantasmas(char mapa[FILAS][COLUMNAS], Fantasma fantasmas[MAX_FANTASMAS]) {
    int contador = 0;
    TipoFantasma tipos[4] = {BLINKY, PINKY, INKY, CLYDE};

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (mapa[i][j] == 'F' && contador < MAX_FANTASMAS) {
                fantasmas[contador].fila = i;
                fantasmas[contador].col = j;
                fantasmas[contador].celdaPrevia = ' ';
                fantasmas[contador].tipo = tipos[contador % 4];
                contador++;
            }
        }
    }
    return contador;
}

// Auxiliar para mover un fantasma a la mejor casilla segun una coordenada objetivo
static void moverHaciaObjetivo(char mapa[FILAS][COLUMNAS], Fantasma *f, int objFila, int objCol) {
    int df[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int mejorFila = f->fila;
    int mejorCol = f->col;
    int menorDistancia = 99999;
    int hayMovimiento = 0;

    for (int i = 0; i < 4; i++) {
        int nf = f->fila + df[i];
        int nc = f->col + dc[i];

        if (esMovimientoValido(mapa, nf, nc)) {
            int dist = abs(nf - objFila) + abs(nc - objCol);
            if (dist < menorDistancia) {
                menorDistancia = dist;
                mejorFila = nf;
                mejorCol = nc;
                hayMovimiento = 1;
            }
        }
    }

    if (hayMovimiento) {
        mapa[f->fila][f->col] = f->celdaPrevia;
        f->celdaPrevia = mapa[mejorFila][mejorCol];
        f->fila = mejorFila;
        f->col = mejorCol;
        mapa[mejorFila][mejorCol] = 'F';
    }
}

// Auxiliar para movimiento aleatorio (deambular)
static void moverAleatorio(char mapa[FILAS][COLUMNAS], Fantasma *f) {
    int df[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int validos[4];
    int totalValidos = 0;

    for (int i = 0; i < 4; i++) {
        int nf = f->fila + df[i];
        int nc = f->col + dc[i];
        if (esMovimientoValido(mapa, nf, nc)) {
            validos[totalValidos++] = i;
        }
    }

    if (totalValidos > 0) {
        int idx = validos[rand() % totalValidos];
        int nf = f->fila + df[idx];
        int nc = f->col + dc[idx];

        mapa[f->fila][f->col] = f->celdaPrevia;
        f->celdaPrevia = mapa[nf][nc];
        f->fila = nf;
        f->col = nc;
        mapa[nf][nc] = 'F';
    }
}

void moverFantasmas(char mapa[FILAS][COLUMNAS], Fantasma fantasmas[MAX_FANTASMAS], int numFantasmas, int pacmanFila, int pacmanCol, char pacmanDir) {
    // Buscar la posición de Blinky para la logica de Inky
    int blinkyFila = pacmanFila, blinkyCol = pacmanCol;
    for (int i = 0; i < numFantasmas; i++) {
        if (fantasmas[i].tipo == BLINKY) {
            blinkyFila = fantasmas[i].fila;
            blinkyCol = fantasmas[i].col;
            break;
        }
    }

    for (int i = 0; i < numFantasmas; i++) {
        Fantasma *f = &fantasmas[i];

        switch (f->tipo) {
            case BLINKY:
                // Cazador: Persigue a Pacman directamente
                moverHaciaObjetivo(mapa, f, pacmanFila, pacmanCol);
                break;

            case PINKY: {
                // Emboscadora: Apunta 3 casillas por delante de Pacman
                int targetFila = pacmanFila;
                int targetCol = pacmanCol;
                if (pacmanDir == 'w' || pacmanDir == 'W') targetFila -= 3;
                else if (pacmanDir == 's' || pacmanDir == 'S') targetFila += 3;
                else if (pacmanDir == 'a' || pacmanDir == 'A') targetCol -= 3;
                else if (pacmanDir == 'd' || pacmanDir == 'D') targetCol += 3;

                moverHaciaObjetivo(mapa, f, targetFila, targetCol);
                break;
            }

            case INKY: {
                // Impredecible: Calcula vector reflejo entre Blinky y Pacman
                int targetFila = pacmanFila + (pacmanFila - blinkyFila);
                int targetCol = pacmanCol + (pacmanCol - blinkyCol);
                moverHaciaObjetivo(mapa, f, targetFila, targetCol);
                break;
            }

            case CLYDE: {
                // Despistado: Persigue si está lejos (> 5 casillas), deambula si se acerca
                int dist = abs(f->fila - pacmanFila) + abs(f->col - pacmanCol);
                if (dist > 5) {
                    moverHaciaObjetivo(mapa, f, pacmanFila, pacmanCol);
                } else {
                    moverAleatorio(mapa, f);
                }
                break;
            }
        }
    }
}