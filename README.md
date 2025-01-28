# Projeto de Animações LED

Este projeto faz parte do programa de capacitação em sistemas embarcados (Embarcatech). O objetivo deste projeto é desenvolver animações de LED utilizando a placa Raspberry Pi Pico W e a biblioteca Pico SDK no Simulador Wokwi.

## Estrutura do Projeto

- `led_animations.c`: Código fonte principal que contém a lógica para as animações de LED.
- `CMakeLists.txt`: Arquivo de configuração do CMake para compilar o projeto.
- `.vscode/`: Configurações do Visual Studio Code para facilitar o desenvolvimento e a depuração.
- `wokwi.toml` e `diagram.json`: Arquivos de configuração para simulação no Wokwi.
- `ws2818b.pio`: Código para controle de uma PIO do microcontrolador RP2040

## Animações Desenvolvidas

Todas as animações desenvolvidas têm pelo menos 5 frames, como especificada na atividade. Cada componente da equipe ficou responsável por uma animação.

- Flor - Ao pressionar a tecla 0
- Rosto com olho piscando - Ao pressionar a tecla 1
- Ampulheta - Ao pressionar a tecla 2
- Contador de 0 a 9 - Ao pressionar a tecla 3
- Rosto com sorriso - Ao pressionar a tecla 4

## Funcionalidades

- Caso a tecla A seja acionada, todos os LEDs são desligados. 
- Caso a tecla B seja acionada, todos os LEDs são ligados na cor azul, no nível de intensidade de 100% da luminosidade máxima. 
- Caso a tecla C seja acionada, todos os LEDs são ligados na cor vermelha, no nível de intensidade de 80% da luminosidade máxima. 
- Caso a tecla D seja acionada, todos os LEDs são ligados na cor verde, no nível de intensidade de 50% da luminosidade máxima. 
- Caso a tecla # seja acionada, todos os LEDs são ligados na cor branca, no nível de intensidade de 20% da luminosidade máxima. 

## Execução do projeto

1. Faça um clone do repositório em sua máquina:
```
git clone https://github.com/caiquedebrito/led_animations.git
```

2. Compile o projeto
3. Execute o projeto no simulador wokwi

## Formação da equipe

(Líder) - Responsável pela gestão do repositório
- Caique 

(Desenvolvedores) - Responsáveis pela execução das tarefas

- Diêgo
- Devid
- Juan
- Renan

## Apresentação do resultados

https://github.com/user-attachments/assets/fa5e65ee-2f80-46d3-83c2-ccc9a569dc3b

## Vídeo Demonstrativo

[![Assista ao vídeo do projeto no YouTube](https://img.youtube.com/vi/JgjQNOM3ox0/hqdefault.jpg)](https://www.youtube.com/watch?v=JgjQNOM3ox0)

## Agradecimentos

Gostaríamos de agradecer à equipe do Embarcatech por proporcionar esta atividade desafiadora e enriquecedora. Foi uma experiência nova que agregou bastante a cada integrante do grupo, tanto individualmente quanto coletivamente, permitindo-nos desenvolver habilidades práticas em sistemas embarcados e colaboração em equipe.
