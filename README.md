# Acelerometro MPU 9250 4k Sample Freq
 
Usando o acelerômetro, capacitivo, MPU-9250 para estudo em frequência.

Pelo Datasheet esse modelo de acelerômetro só funciona até 4 Khz de frequência de amostragem. Para chegar a 4 Khz de frequência de amostragem, é necessario desabilitar o filtro interno do dispositivo.

O protocolo de comunicação utilizado nesse projeto é o I2C.

## O que é um acelerômetro?

O acelerômetro é um sensor da família Micro Electro Mechanical Sensors (MEMS – Microssensores Eletromecânicos). O funcionamento do dispositivo baseia-se na Segunda Lei de Newton, na qual a força é igual a massa vezes aceleração. Quando há uma aceleração resultante de um deslocamento, é desenvolvida uma força em uma massa anexada a uma superfície de silício. O fluido (geralmente é utilizado o ar) atua como um amortecedor. O sistema do acelerômetro é calculado como um sistema de segunda ordem. Pelo fato do espaço de deslocamento da massa dentro do sensor ser limitado, a largura de banda de resposta do sensor também é limitada. Pelos sistemas amortecedores dos fluidos integrados no acelerômetro em conjunto com o um sistema de mola simulados por pequenos feixes, a resposta do sensor na frequência não é uniforme, ou seja, a frequência tende a ser afetada pela velocidade de aceleração do sensor.

Os acelerômetros são construídos baseados em princípios já existentes, comumente utilizados em outros sensores, como o acelerômetro piezoelétrico e o acelerômetro capacitivo, por exemplo. O acelerômetro piezoelétrico produz sinal de corrente alternada à medida que ocorre uma vibração ou choque mecânico. Acelerômetros capacitivos utilizam o efeito da capacitância para detectar a distância de uma massa e calcular a sua aceleração quando aplicado uma força direcional em um sistema massa mola. A Figura abaixo ilustra com uma analógia o funcionamento de um acelerômetro capacitivo. Esse tipo de acelerômetro possui alta precisão e estabilidade, além de ser menos propensos a ruídos pela variação de temperatura.

![Analogiadefuncionamento](https://github.com/Arthurmgwork/Acelerometro-MPU-9250-4k-Sample-Freq/blob/main/Analogia-do-Principio-de-funcionamento-de-um-aceler%C3%B4metro.JPG)


## Como Utilizar o Código

Para obter os dados do acelerômetro, é utilizado uma ESP32.

Ao realizar o upload do código para a ESP32, abra a janela de comunicação serial e digite um número entre 1 a 9 para começar a aquisição de dados. Quando não quiser receber mais os dados do acelerômetro digite 0.

## Especificações do Sensor

O acelerômetro utilizado neste projeto é o acelerômetro MPU-9250. O módulo MPU é um conjunto de sensores MEMS. O MPU utilizado possui: um giroscópio, um acelerômetro capacitivo, um magnetômetro baseado no efeito hall e um barômetro que serve como altímetro. O módulo MPU possui compatibilidade com a comunicação I2C e SPI que é um protocolo de comunicação mestre escravo. A presença deste protocolo facilita a comunicação com diversas plataformas microcontroladoras e microprocessadoras, como a Esp32 e a Raspberry, por exemplo.

![foto do sensor](https://github.com/Arthurmgwork/Acelerometro-MPU-9250-4k-Sample-Freq/blob/main/m%C3%B3dulo%20MPU-9250.JPG)

O acelerômetro presente no MPU, possui três eixos X, Y e Z. O MPU-9250 possui uma frequência de amostragem máxima 4000 Hz. O nível máximo de comunicação com a porta I2C é 400 kHz para ambos os módulos. A Figura 9 ilustra o posicionamento de cada eixo no chip do módulo. A coleta de dados da vibração das pregas vocais ocorre pelo eixo Z do acelerômetro por se posicionar linearmente a deformação do tecido da pele do pescoço.

![EixosSensor](https://github.com/Arthurmgwork/Acelerometro-MPU-9250-4k-Sample-Freq/blob/main/dire%C3%A7%C3%A3o%20dos%20eixos%20do%20sensor.JPG)

Especificações do acelerômetro no MPU-9250:
• Tensão de alimentação 2,5 volts para o chip e 5 volts para o módulo;
• Temperatura máxima: 85 ºC;
• Temperatura mínima: -40 ºC;
• Três eixos (X, Y e Z) com escalas programáveis de ±2g, ±4g, ±8g e ±16g;
• Saída de 16 bits;
• Corrente em operação normal: 450𝜇A;
• Baixo consumo de energia: 8,4𝜇A a 0.98Hz, 19,8 𝜇A a 31,25Hz;
• Modo de descanso: 8 𝜇A;
• Tolerância a impacto de 10,000g;
• Frequência máxima de comunicação com o protocolo I2C em todos os registradores: 400 kHz;



Datasheet do MPU-9250: https://invensense.tdk.com/wp-content/uploads/2015/02/PS-MPU-9250A-01-v1.1.pdf

Datasheet dos registradores do MPU-9250: https://cdn.sparkfun.com/assets/learn_tutorials/5/5/0/MPU-9250-Register-Map.pdf


