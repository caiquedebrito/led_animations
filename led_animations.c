#include <stdio.h>
#include "pico/stdlib.h"
#include "matrix_keyboard.h"

int main()
{
    char tecla_pressionada;

    stdio_init_all();

    configurar_teclado();

    while (true) {
        tecla_pressionada = leitura_teclado();
        printf("Tecla pressionada: %c\n", tecla_pressionada);
        sleep_ms(1000);
    }
}