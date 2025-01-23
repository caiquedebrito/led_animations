#include "pico/stdlib.h"
#include "matrix_keyboard.h"
#include <stdio.h>

const uint8_t colunas_pin[COLS] = {19, 18, 17, 16};
const uint8_t linhas_pin[ROWS] = {26, 22, 21, 20};
const char teclado[ROWS][COLS] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

void configurar_teclado()
{
  for (int i = 0; i < COLS; i++)
  {
    gpio_init(colunas_pin[i]);
    gpio_set_dir(colunas_pin[i], GPIO_OUT);
    gpio_put(colunas_pin[i], true);
  }

  for (int i = 0; i < ROWS; i++)
  {
    gpio_init(linhas_pin[i]);
    gpio_set_dir(linhas_pin[i], GPIO_IN);
    gpio_pull_up(linhas_pin[i]);
  }
}

char leitura_teclado()
{
  char tecla;

  for (int coluna = 0; coluna < COLS; coluna++)
  {
    gpio_put(colunas_pin[coluna], false);

    for (int linha = 0; linha < ROWS; linha++)
    {
      if (!gpio_get(linhas_pin[linha]))
      {
        sleep_ms(10);

        if (!gpio_get(linhas_pin[linha]))
        {
          tecla = teclado[linha][coluna];

          while (!gpio_get(linhas_pin[linha]))
            sleep_ms(10);

          gpio_put(colunas_pin[coluna], true);
          return tecla;
        }
      }
    }

    gpio_put(colunas_pin[coluna], true);
  }

  return tecla;
}