# Documentación Técnica y Estado del Proyecto: Pacman en Consola (C)

Este documento describe la arquitectura modular del proyecto, el funcionamiento del código existente y la guía para implementar los componentes pendientes (movimiento del jugador, colisiones, sistema de vidas y condiciones de fin de juego).

---

## 1. Arquitectura del Proyecto

El proyecto está diseñado de forma modular en lenguaje C, repartiendo las responsabilidades en archivos de cabecera y de implementación.

### Estructura de Archivos

- **main.c**: Contiene la función principal, el menú de navegación inicial y el flujo principal de ejecución.
- **mapa.h / mapa.c**: Administra la matriz del laberinto, la carga aleatoria de niveles, el renderizado en pantalla y la validación de casillas libres.
- **fantasma.h / fantasma.c**: Define los tipos de fantasmas, sus posiciones y las inteligencias artificiales para el movimiento autónomo.
- **.gitignore**: Define los patrones para ignorar ejecutables y archivos de compilación intermedios.
- **README.md**: Documentación general de uso e instrucciones de compilación.

---

## 2. Componentes Implementados

### A. Módulo del Mapa (mapa.h / mapa.c)

Maneja una matriz bidimensional de 15 filas por 21 columnas (20 caracteres visibles más el carácter de terminación nulo).

#### Simbología de la Matriz:
- **#** : Pared (casilla impasable).
- **.** : Punto comestible (incrementa la puntuación).
- **C** : Posición inicial de Pacman.
- **F** : Posición inicial de un Fantasma.
- **Espacio en blanco** : Camino vacío.

#### Funciones Disponibles:
1. **cargarMapaAleatorio**: Elige al azar una de las tres matrices predefinidas en memoria y la copia en la matriz del tablero activo.
2. **mostrarMapa**: Limpia la pantalla de la consola e imprime el marcador (puntuación y vidas acumuladas) seguido de la matriz visual del juego.
3. **esMovimientoValido**: Función de comprobación de casillas. Recibe una coordenada destino dentro de la matriz y retorna un indicador de validez (permitido si está dentro de los límites y no es una pared `#`; denegado en caso contrario).

---

### B. Módulo de Fantasmas (fantasma.h / fantasma.c)

Administra a los 4 fantasmas del juego con sus respectivas personalidades de Inteligencia Artificial (IA) y garantiza que al desplazarse sobre casillas con puntos comestibles, dichos puntos se restauren cuando el fantasma abandone la casilla.

#### Estructura del Fantasma:
Contiene las coordenadas de fila y columna actual, la celda previa pisada (para no borrar puntos del mapa) y el tipo de personalidad asignado:
- **Blinky (Cazador):** Persigue a Pacman evaluando en cada turno la casilla que minimice la distancia directa hacia él.
- **Pinky (Emboscadora):** Calcula su casilla destino tres posiciones por delante de la dirección en la que Pacman se desplaza.
- **Inky (Impredecible):** Determina su dirección combinando la posición de Blinky y Pacman.
- **Clyde (Despistado):** Persigue a Pacman si se encuentra a más de 5 casillas de distancia; si Pacman se aproxima, pasa a deambular de forma aleatoria.

#### Funciones Disponibles:
1. **inicializarFantasmas**: Escanea el mapa cargado, localiza los símbolos de fantasmas `F`, guarda sus coordenadas iniciales y asigna los cuatro roles.
2. **moverFantasmas**: Actualiza la posición de todos los fantasmas ejecutando sus algoritmos de búsqueda de ruta, manteniendo la integridad de los puntos pisados.

---

### C. Menú Inicial (main.c)

- Proporciona las opciones: **1. Jugar**, **2. Instrucciones**, **3. Salir**.
- Incluye rutinas de limpieza de consola compatibles tanto para sistemas Windows como para Linux y macOS.

---

## 3. Guía de Implementación para las Partes Pendientes

El desarrollador a cargo de continuar el proyecto debe estructurar el módulo de Pacman y completar la lógica del bucle de juego.

### Tarea 1: Módulo de Pacman (pacman.h / pacman.c)

#### Definición de Datos:
Crear una estructura para Pacman que contenga:
- Coordenadas de fila y columna actuales.
- Coordenadas de origen (fila y columna iniciales) para el reaparecer tras perder una vida.
- Dirección actual de movimiento.

#### Especificación de Funciones:
1. **inicializarPacman**:
   - Recorre la matriz cargada para ubicar la letra `C`.
   - Asigna las coordenadas actuales y las coordenadas iniciales de origen.
2. **moverPacman**:
   - Recibe la tecla leída (`W`, `A`, `S`, `D`), calcula la posición destino solicitada y consulta a la función `esMovimientoValido`.
   - Si la casilla destino contiene un punto `.`, suma 10 puntos al acumulador del juego y descuenta una unidad del contador de puntos restantes del nivel.
   - Limpia la posición vieja con un espacio en blanco, actualiza las coordenadas de la estructura y coloca la letra `C` en la nueva casilla.
3. **reiniciarPosicionPacman**:
   - Quita a Pacman de su posición en la matriz y restablece sus coordenadas actuales a la posición inicial de origen.

---

### Tarea 2: Control del Estado del Juego y Colisiones

En el ciclo principal del juego (dentro de `main.c` o en un módulo de juego separado), se deben coordinar los siguientes aspectos:

1. **Conteo Inicial de Puntos**:
   - Al cargar la matriz al inicio de la partida, realizar un conteo total de caracteres `.` presentes para definir la condición de victoria.

2. **Detección de Colisiones**:
   - Al finalizar cada turno (tanto tras el movimiento del jugador como tras el movimiento de los fantasmas), comparar las coordenadas de Pacman con la coordenada de cada fantasma.

3. **Gestión de Vidas y Reaparición**:
   - Si se detecta colisión entre Pacman y un fantasma:
     - Restar 1 vida al contador global.
     - Si aún quedan vidas: devolver a Pacman a su posición inicial de origen y a los fantasmas a sus casillas iniciales.
     - Si las vidas llegan a 0: finalizar el bucle de juego e imprimir la pantalla de **GAME OVER** mostrando la puntuación acumulada.

4. **Condición de Victoria**:
   - Cuando el contador de puntos restantes sea igual a 0, detener la partida y mostrar la pantalla de **¡VICTORIA!** con la puntuación final alcanzada.

---

### Tarea 3: Secuencia del Bucle de Juego

En la opción de juego de `main.c`, la secuencia por turno debe ejecutarse en este orden:

1. Limpiar pantalla y llamar a la función para redibujar el tablero y las estadísticas.
2. Solicitar al usuario la dirección de movimiento (`W/A/S/D`).
3. Ejecutar la función de movimiento de Pacman.
4. Verificar colisiones (Pacman contra Fantasmas).
5. Si no hubo colisión, ejecutar la función de movimiento de los Fantasmas.
6. Verificar colisiones nuevamente (Fantasmas se mueven hacia Pacman).
7. Validar condiciones de victoria (puntos restantes en cero) o derrota (vidas en cero).

---

## 4. Compilación

Para compilar el proyecto una vez integrados todos los módulos, la sintaxis en la consola de comandos debe incluir los archivos fuentes de main, mapa, fantasma y pacman.