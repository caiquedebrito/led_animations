#include <stdio.h>
#include "pico/stdlib.h"
#include "matrix_keyboard.h"
#include "neopixel.h"
#include "buzzer.h"

#define BUZZER_PIN 27 //pino do buzzer

//Funções de animação
void anima_flor();
void anima_ampulheta();
void anima_face();
void anima_cont();
void anima_sorriso();

int main()
{
    char tecla_pressionada;

    stdio_init_all();
    pwm_init_buzzer(BUZZER_PIN);
    
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
            case '1':
                anima_face();
                break;
            case '2':  
                anima_ampulheta();
                break;
            case '3':
                //Animação da contagem de 0 até 9 e som do buzzer
                anima_cont(); 
                break;
            case '4':
                // Animação da face feliz
                anima_sorriso();
                break;
            case '5':
                //ativa o buzzer
                beep(BUZZER_PIN, 500);
                break;
            case 'A':
                // Apaga todos os LEDs
                npClear();
                npWrite();
                break;
            case 'B':
                //Acende todos os LEDs na cor azul com intensidade 100%
                for(int i = 0; i < LED_COUNT; i++){
                  npSetLED(i, 0 , 0 , 255);
                }
                npWrite();
                break;            
            case 'C':  
                for (int i = 0; i < LED_COUNT; i++) {
                    npSetLED(i, 255*0.8, 0, 0);  // Vermelho com 80% de intensidade
                }
                npWrite();
                break;
            case 'D':  
                // Acende todos os LEDs na cor verde com intensidade de 50%
                for (int i = 0; i < LED_COUNT; i++) {
                    npSetLED(i, 0, 255*0.5, 0);  // Verde com 50% de intensidade
                }
                npWrite();
                break;
            case '#':
                for(int i = 0; i < LED_COUNT; i++){
                  npSetLED(i, 255 * 0.2, 255 * 0.2, 255 * 0.2); // Acende todos os LEDs na cor branca com intensidade de 20%
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

void anima_ampulheta() {
    int tempo_espera = 1000;  // Tempo entre os frames

    // Frame 1
    npClear();
    for (int i = 20; i < 25; i++) { // Linha 1 (topo) completa
        npSetLED(i, 255, 255, 0);
    }
    for (int i = 15; i < 20; i++) { // Linha 2 completa
        npSetLED(i, 255, 255, 0);
    }
    npWrite();
    sleep_ms(tempo_espera);

    // Frame 2
    npClear();
    for (int i = 20; i < 25; i++) { // Linha 1 completa
        npSetLED(i, 255, 255, 0);
    }
    for (int i = 15; i < 20; i++) { // Linha 2 completa
        npSetLED(i, 255, 255, 0);
    }
    npSetLED(12, 255, 255, 0); // Centro da linha 3
    npWrite();
    sleep_ms(tempo_espera);

    // Frame 3
    npClear();
    for (int i = 15; i < 20; i++) { // Linha 2 completa
        npSetLED(i, 255, 255, 0);
    }
    npSetLED(12, 255, 255, 0); // Centro da linha 3
    npSetLED(7, 255, 255, 0);  // Centro da linha 4
    npWrite();
    sleep_ms(tempo_espera);

    // Frame 4
    npClear();
    npSetLED(12, 255, 255, 0); // Centro da linha 3
    for (int i = 5; i < 10; i++) { // Linha 4 completa
        npSetLED(i, 255, 255, 0);
    }
    for (int i = 0; i < 5; i++) { // Linha 5 completa
        npSetLED(i, 255, 255, 0);
    }
    npWrite();
    sleep_ms(tempo_espera);

    // Frame 5
    npClear();
    for (int i = 0; i < 5; i++) { // Linha 5 completa
        npSetLED(i, 255, 255, 0);
    }
    for (int i = 5; i < 10; i++) { // Linha 4 completa
        npSetLED(i, 255, 255, 0);
    }
    npWrite();
    sleep_ms(tempo_espera);

    // Limpa LEDs ao final
    npClear();
    npWrite();
}

void anima_face() {
  int frame_time = 1000;

  // Frame 1
  npSetLED(23, 255, 0, 0);
  npSetLED(22, 255, 0, 0);
  npSetLED(21, 255, 0, 0);
  npWrite();
  sleep_ms(frame_time);

  // Frame 2
  npSetLED(23, 0, 0, 0);
  npSetLED(22, 0, 0, 0);
  npSetLED(21, 0, 0, 0);
  npSetLED(24, 255, 0, 0);
  npSetLED(20, 255, 0, 0);
  npSetLED(16, 255, 0, 0);
  npSetLED(17, 255, 0, 0);
  npSetLED(18, 255, 0, 0);
  npWrite();
  sleep_ms(frame_time);

  // Frame 3
  npSetLED(24, 0, 0, 0);
  npSetLED(20, 0, 0, 0);
  npSetLED(16, 0, 0, 0);
  npSetLED(17, 0, 0, 0);
  npSetLED(18, 0, 0, 0);
  npSetLED(15, 255, 0, 0);
  npSetLED(19, 255, 0, 0);
  npSetLED(13, 255, 0, 0);
  npSetLED(12, 255, 0, 0);
  npSetLED(11, 255, 0, 0);
  npWrite();
  sleep_ms(frame_time);

  // Frame 4
  npSetLED(15, 0, 0, 0);
  npSetLED(19, 0, 0, 0);
  npSetLED(13, 0, 0, 0);
  npSetLED(12, 0, 0, 0);
  npSetLED(11, 0, 0, 0);
  npSetLED(23, 255, 0, 0);
  npSetLED(21, 255, 0, 0);
  npSetLED(14, 255, 0, 0);
  npSetLED(10, 255, 0, 0);
  npSetLED(6, 255, 0, 0);
  npSetLED(7, 255, 0, 0);
  npSetLED(8, 255, 0, 0);
  npWrite();
  sleep_ms(frame_time);

  // Frame 5
  npSetLED(23, 0, 0, 0);
  npSetLED(21, 0, 0, 0);
  npSetLED(14, 0, 0, 0);
  npSetLED(10, 0, 0, 0);
  npSetLED(6, 0, 0, 0);
  npSetLED(7, 0, 0, 0);
  npSetLED(8, 0, 0, 0);
  npSetLED(16, 255, 0, 0);
  npSetLED(18, 255, 0, 0);
  npSetLED(1, 255, 0, 0);
  npSetLED(2, 255, 0, 0);
  npSetLED(3, 255, 0, 0);
  npSetLED(5, 255, 0, 0);
  npSetLED(9, 255, 0, 0);
  npWrite();
  sleep_ms(frame_time);

  // Frame 6
  npSetLED(23, 0, 0, 0);
  npSetLED(21, 0, 0, 0);
  npSetLED(14, 0, 0, 0);
  npSetLED(10, 0, 0, 0);
  npSetLED(6, 0, 0, 0);
  npSetLED(7, 0, 0, 0);
  npSetLED(8, 0, 0, 0);
  npSetLED(16, 255, 0, 0);
  npSetLED(18, 0, 0, 0);
  npSetLED(1, 255, 0, 0);
  npSetLED(2, 255, 0, 0);
  npSetLED(3, 255, 0, 0);
  npSetLED(5, 255, 0, 0);
  npSetLED(9, 255, 0, 0);
  npWrite();
  sleep_ms(frame_time);

  // Frame 7
  npSetLED(23, 0, 0, 0);
  npSetLED(21, 0, 0, 0);
  npSetLED(14, 0, 0, 0);
  npSetLED(10, 0, 0, 0);
  npSetLED(6, 0, 0, 0);
  npSetLED(7, 0, 0, 0);
  npSetLED(8, 0, 0, 0);
  npSetLED(16, 255, 0, 0);
  npSetLED(18, 255, 0, 0);
  npSetLED(1, 255, 0, 0);
  npSetLED(2, 255, 0, 0);
  npSetLED(3, 255, 0, 0);
  npSetLED(5, 255, 0, 0);
  npSetLED(9, 255, 0, 0);
  npWrite();
  sleep_ms(frame_time);
}

void anima_cont(){
  int frame_time = 1000;

  // Frame 1 (Dígito 0)
  npSetLED(23, 20, 0, 0);
  npSetLED(16, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(6, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(8, 20, 0, 0);
  npSetLED(11,20,0,0);
  npSetLED(18, 20, 0, 0);
  npSetLED(21, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time);
  npClear();
    
  // Frame 2 (Dígito 1)
  npSetLED(22, 20, 0, 0);
  npSetLED(17, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(7, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time);
  npClear();

  // Frame 3 (Dígito 2)
  npSetLED(23, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npSetLED(21, 20, 0, 0);
  npSetLED(18, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(6, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time);
  npClear();

  // Frame 4 (Dígito 3)
  npSetLED(23, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npSetLED(21, 20, 0, 0);
  npSetLED(18, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(8, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time);
  npClear();

  // Frame 5 (Dígito 4)
  npSetLED(21, 20, 0, 0);
  npSetLED(18, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npSetLED(8, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(23, 20, 0, 0);
  npSetLED(16, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time); 
  npClear();

  // Frame 6 (Dígito 5)
  npSetLED(21, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npSetLED(23, 20, 0, 0);
  npSetLED(16, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npSetLED(8, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time); 
  npClear(); 

  // Frame 7 (Dígito 6)
  npSetLED(21, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npSetLED(23, 20, 0, 0);
  npSetLED(16, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npSetLED(8, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npSetLED(6, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time); 
  npClear(); 

  // Frame 8 (Dígito 7)
  npSetLED(23, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npSetLED(17, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(7, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time); 
  npClear();

  // Frame 9 (Dígito 8)
  npSetLED(23, 20, 0, 0);
  npSetLED(16, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(6, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npSetLED(21, 20, 0, 0);
  npSetLED(18, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npSetLED(8, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time); 
  npClear(); 

  // Frame 10 (Dígito 9)
  npSetLED(21, 20, 0, 0);
  npSetLED(22, 20, 0, 0);
  npSetLED(23, 20, 0, 0);
  npSetLED(16, 20, 0, 0);
  npSetLED(13, 20, 0, 0);
  npSetLED(12, 20, 0, 0);
  npSetLED(11, 20, 0, 0);
  npSetLED(8, 20, 0, 0);
  npSetLED(1, 20, 0, 0);
  npSetLED(2, 20, 0, 0);
  npSetLED(3, 20, 0, 0);
  npSetLED(18,20, 0, 0);
  npWrite();
  beep(BUZZER_PIN, 500);
  sleep_ms(frame_time); 
  npClear();
}

// Função para exibir uma animação de rosto sorrindo
void anima_sorriso() {
    int frame_time = 1000; // Tempo de cada frame em milissegundos

    // Frame 1: Olhos fechados, boca neutra
    npClear();
    npSetLED(10, 255, 255, 0); // Olho esquerdo
    npSetLED(13, 255, 255, 0); // Olho direito
    npWrite();
    sleep_ms(frame_time);

    // Frame 2: Olhos entreabertos
    npSetLED(10, 255, 255, 0); // Olho esquerdo superior
    npSetLED(11, 255, 255, 0); // Olho esquerdo inferior
    npSetLED(13, 255, 255, 0); // Olho direito superior
    npSetLED(14, 255, 255, 0); // Olho direito inferior
    npWrite();
    sleep_ms(frame_time);

    // Frame 3: Olhos abertos, boca neutra
    npSetLED(11, 255, 255, 0);  // Olho esquerdo
    npSetLED(14, 255, 255, 0); // Olho direito
    npWrite();
    sleep_ms(frame_time);

    // Frame 4: Olhos abertos, sorriso pequeno
    npSetLED(16, 255, 0, 0);  // Canto da boca (esquerdo)
    npSetLED(18, 255, 0, 0);  // Canto da boca (direito)
    npWrite();
    sleep_ms(frame_time);

    // Frame 5: Olhos abertos, sorriso largo
    npSetLED(21, 255, 0, 0);  // Sorriso (esquerdo)
    npSetLED(23, 255, 0, 0);  // Sorriso (direito)
    npWrite();
    sleep_ms(frame_time);

    // Limpa os LEDs ao final da animação
    npClear();
    npWrite();
}