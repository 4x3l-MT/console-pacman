#ifndef MAPA_H
#define MAPA_H

#define FILAS 15
#define COLUMNAS 21

// Carga de forma aleatoria uno de los tres mapas predefinidos
void cargarMapaAleatorio(char mapaDestino[FILAS][COLUMNAS]);

// Imprime el tablero actual junto con las estadísticas
void mostrarMapa(char mapa[FILAS][COLUMNAS], int puntuacion, int vidas);

// Valida si una posición dentro de la matriz no es una pared (#) ni está fuera de límites
int esMovimientoValido(char mapa[FILAS][COLUMNAS], int nuevaFila, int nuevaColumna);

#endif