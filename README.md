# Console Pacman in C

A lightweight, terminal-based implementation of the classic Pacman game built in C using modular programming principles.

## Project Overview

This project simulates a console version of Pacman where the player navigates a 15x20 grid maze to eat dots (.) while avoiding ghosts (F). It demonstrates core programming concepts such as 2D arrays, game loops, modular file structures, and cross-platform terminal management.

---

## Features

- Modular Architecture: Separate header and implementation files (mapa.h, mapa.c, main.c) for clean code organization.
- Randomized Level Loading: Automatically selects one of three predefined 15x20 mazes at the start of each game session.
- Valid Movement System: Prevents Pacman and ghosts from passing through walls (#) using boundary and collision checking functions.
- Cross-Platform Clear Screen: Supports dynamic screen clearing for both Windows (cls) and Linux/macOS (clear).

---

## Project Structure

```text
├── main.c        # Main entry point, game loop, and interactive menu
├── mapa.h        # Header file containing constants and map function prototypes
├── mapa.c        # Implementation of predefined mazes and map logic
├── .gitignore    # Excludes compiled executables and object files
└── README.md     # Project documentation
```

---

## Map Legend

| Symbol | Description |
| :---: | :--- |
| # | Wall (impassable) |
| . | Dot (edible, adds 10 points) |
| C | Pacman (initial position) |
| F | Ghost (initial position) |
|   | Empty space |

---

## Building and Running

### Prerequisites
- GCC compiler (or any standard C/C++ compiler)
- Git (optional)

### Compilation

Open your terminal or command prompt in the project root directory and run:

```bash
gcc main.c mapa.c -o pacman.exe
```

### Execution

#### On Windows:
```cmd
pacman.exe
```

#### On Linux / macOS:
```bash
./pacman.exe
```

---

## Game Controls

- W: Move Up
- A: Move Left
- S: Move Down
- D: Move Right

---

## Requirements Checklist

- [x] 15x20 Matrix maze representation.
- [x] Predefined map layouts loaded at runtime.
- [x] Console clearing between frames.
- [x] Input system with navigation menus.
- [ ] Non-blocking real-time keyboard input.
- [ ] Ghost movement logic (Random / Simple AI).
- [ ] Win/Loss game end conditions.

---

## License

This project is open-source and available for educational purposes.
