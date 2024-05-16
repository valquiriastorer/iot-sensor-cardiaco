# Sensor de frequência cardíaca
Documentação do projeto da disciplina de Objetos Inteligentes Conectados.

Aluna: **Valquiria Scarelli Storer**
RA: **10370284**

## Descrição
Neste sensor de frequência cardíaca, a leitura das batidas do coração é feita através de um sensor óptico. O usuário coloca o dedo nesse sensor, e os dados são enviados ao microcontrolador Arduino Nano V3.0, que envia sinais a um LED que pisca conforme os batimentos. Os dados também são enviados ao módulo Wifi NodeMCU ESP8266, que se conecta à rede Wifi, carrega e publica as informações no servidor MQTT, o Ubidots. Assim, os batimentos podem ser visualizados em gráficos.

## Hardware
- Sensor de frequência cardíaca: efetua a leitura das batidas do coração usando um sensor óptico amplificado, e envia esses dados para o microcontrolador Arduino através de um único pino de sinal. Tensão de operação: 3 ou 5VDC.

![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/618d930a-fa3c-4edb-9793-4ece63f20c6c)

- Placa Arduino Nano V3.0 e cabo USB 2.0 A/B para alimentação.

![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/d7430a7e-7d15-46dc-ae1d-a80796d61e93)

- Módulo Wifi NodeMCU ESP8266 e cabo compatível: para realizar a comunicação com a internet via protocolo MQTT.

![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/8a66349a-fd59-400d-829f-9fb73a0532ac)

- LED 5mm vermelho: atuador, pisca conforme os batimentos cardíacos detectados
- Protoboard 400 pontos para conectar o Arduino, o LED  e o sensor de batimentos sem precisar soldar os componentes
- Protoboard 830 pontos para o módulo NodeMCU.
- Resistor 220R para conectar o LED ao Arduino.
- Jumpers macho-macho para ligar os componentes entre si.


### Modelo de montagem da proposta

![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/1a54951e-27ef-4d90-98c9-f668ccd7cc42)

1. Encaixar o Arduino na parte central do protoboard.
2. Conectar o sensor de batimentos cardíacos ao Arduino. O sinal de saída se conecta ao pino A0, (+) no pino 5V e (-) no pino GND.
3. Conectar um dos terminais do LED ao pino D13 do Arduino e o outro terminal ao GND através do resistor de 220R.
4. Conectar os pinos TX e RX do NodeMCU aos pinos D7 e D8 do Arduino, respectivamente.
5. Conectar tanto o Arduino quanto o NodeMCU a uma fonte de energia com seus respectivos cabos.

## Software
- software desenvolvido e a documentação de código.

## Comunicação com a internet com protocolo MQTT
- documentação das interfaces, protocolos e módulos de comunicação.
- projeto deve possuir comunicação/controle via internet (TCP/IP) e uso do Protocolo MQTT.
