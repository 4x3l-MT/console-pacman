#ifndef FANTASMA_H
#define FANTASMA_H

#include "mapa.h"

#define MAX_FANTASMAS 4

typedef enum {
    BLINKY, // Rojo: Persigue directamente a Pacman
    PINKY,  // Rosa: Intenta emboscar (apunta casillas por delante de Pacman)
    INKY,   // Cian: Impredecible (combina posicion de Blinky y Pacman)
    CLYDE   // Naranja: Se acerca de lejos, huye de cerca
} TipoFantasma;

typedef struct {
    int fila;
    int col;
    char celdaPrevia;
    TipoFantasma tipo;
} Fantasma;

// Inicializa las posiciones y asigna roles a los 4 fantasmas clasicos
int inicializarFantasmas(char mapa[FILAS][COLUMNAS], Fantasma fantasmas[MAX_FANTASMAS]);

// Mueve todos los fantasmas ejecutando sus respectivas inteligencias
void moverFantasmas(char mapa[FILAS][COLUMNAS], Fantasma fantasmas[MAX_FANTASMAS], int numFantasmas, int pacmanFila, int pacmanCol, char pacmanDir);

#endif