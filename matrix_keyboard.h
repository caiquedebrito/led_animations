#ifndef MATRIX_KEYBOARD_H
#define MATRIX_KEYBOARD_H

#include <stdint.h>

#define ROWS 4
#define COLS 4

extern const uint8_t colunas[COLS];
extern const uint8_t linhas[ROWS];
extern const char teclado[ROWS][COLS];

void configurar_teclado();
char leitura_teclado();

#endif // MATRIX_KEYBOARD_H