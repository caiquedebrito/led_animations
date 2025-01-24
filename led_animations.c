#include <stdio.h>
#include "pico/stdlib.h"
#include "matrix_keyboard.h"
#include "neopixel.h"

void anima_flor();

int main()
{
    char tecla_pressionada;

    stdio_init_all();

    npInit(LED_PIN);
    npClear();

    configurar_teclado();

    while (true) {
        tecla_pressionada = leitura_teclado();
        printf("Tecla pressionada: %c\n", tecla_pressionada);
        sleep_ms(1000);

        switch(tecla_pressionada){
            case '0':
                anima_flor();
                break;
            case '#':
                for(int i = 0; i < LED_COUNT; i++){
                  npSetLED(i, 255 * 0.2, 255 * 0.2, 255 * 0.2);
                }
                npWrite();
                break;
        }
    }
}

void anima_flor(){
 
  npSetLED(2, 0, 255, 0);
  npWrite();
  sleep_ms(250);

  npSetLED(7, 0, 255, 0);
  npWrite();
  sleep_ms(250);

  npSetLED(12, 0, 255, 0);
  npWrite();
  sleep_ms(250);

  npSetLED(17, 255, 255, 0);
  npWrite();
  sleep_ms(250);

  for(int i = 0; i < 5; i++){

    if(i%2 == 0){
      npSetLED(16, 255, 0, 0);
      npSetLED(18, 255, 0, 0);
      npSetLED(12, 255, 0, 0);
      npSetLED(22, 255, 0, 0);

      npSetLED(11, 0, 0, 0);
      npSetLED(13, 0, 0, 0);
      npSetLED(21, 0, 0, 0);
      npSetLED(23, 0, 0, 0);

      npWrite();
      sleep_ms(250);

    }
    else{
      npSetLED(16, 0, 0, 0);
      npSetLED(18, 0, 0, 0);
      npSetLED(12, 0, 0, 0);
      npSetLED(22, 0, 0, 0);

      npSetLED(11, 255, 0, 0);
      npSetLED(13, 255, 0, 0);
      npSetLED(21, 255, 0, 0);
      npSetLED(23, 255, 0, 0);

      npSetLED(12, 0, 255, 0);

      npWrite();
      sleep_ms(250);

    }
  }

  npSetLED(16, 200, 0, 0);
  npSetLED(18, 200, 0, 0);
  npSetLED(12, 200, 0, 0);
  npSetLED(22, 200, 0, 0);

  npWrite();
  sleep_ms(250);

  npSetLED(16, 255, 0, 0);
  npSetLED(18, 255, 0, 0);
  npSetLED(12, 255, 0, 0);
  npSetLED(22, 255, 0, 0);

  npWrite();
  sleep_ms(250);

  npSetLED(16, 200, 0, 0);
  npSetLED(18, 200, 0, 0);
  npSetLED(12, 200, 0, 0);
  npSetLED(22, 200, 0, 0);

  npWrite();
  sleep_ms(250);

  npSetLED(16, 255, 0, 0);
  npSetLED(18, 255, 0, 0);
  npSetLED(12, 255, 0, 0);
  npSetLED(22, 255, 0, 0);

  npWrite();
  sleep_ms(250);

  npClear();
  npWrite();

}