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
1. Fazer o download da [Arduino IDE](https://www.arduino.cc/en/software).
2.  Adicionar as seguintes bibliotecas à pasta de bibliotecas do Arduino em `Sketch > Include Library > Manage Library...`:

  ![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/ff7c20a5-5b09-4876-997f-85c263c8dd8d)

  - **Pulse Sensor:** Em Library Manager, pesquisar por "PulseSensor" e instale ou atualize:

     ![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/127af8b0-809c-44f1-8c30-294bba749a83)

  - **PubSubClient:** Em Library Manager, pesquisar por "PubSubClient" e instale ou atualize:

    ![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/a405ef80-7b9c-4a04-a112-7d7033ebd718)

  - **ESP8266 MQTT Ubidots:** Em `Files > Preferences`, adicionar http://arduino.esp8266.com/stable/package_esp8266com_index.json a Additional Board Manager URLs

    ![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/f8811dab-5d84-462e-bf04-76696c47eeee)
    
    Em `Tools > Boards Manager` instale a plataforma esp8266.

    ![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/5d3a3a1c-0012-4e3b-bf7b-ffe3bb33ffb6)

    Baixar a biblioteca [ubidots-mqtt-esp](https://github.com/ubidots/ubidots-mqtt-esp) como .zip, em `Sketch > Include Library > Add .ZIP Library` adicione o arquivo .zip e clique em Accept 

3. Abrir na IDE o arquivo heartbeat.ino.
4. Conectar-se ao Arduino Nano em `Tools > Board`, apertar Verify para compilar o código e depois em Upload. 

![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/83fd9b16-6008-4fc2-8886-7b313ac3bb89)

5. Abrir em outra janela da IDE o arquivo WIFI.ino. Se conectar a esp8266 em Boards e repetir o mesmo processo feito com o Arduino.

### Comunicação com a internet com protocolo MQTT
Para conexão DO PROJETO com a internet usando o protocolo MQTT, foi utilizado a plataforma Ubidots. O NodeMCU recebe os dados do Arduino, em seguida faz o upload e publica o tópico BPM para o Ubidots.

Primeiro, é necessário criar uma nova conta em https://ubidots.com/ ou logar se já tem uma conta existente.

Depois, é necessário obter a chave da API em API Credentials, e copiar o Default token para receber os dados.

![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/44091f7d-8bb4-4bf9-ae35-e65f8ceaf8f3)

No arquivo WIFI.ino, que é o código para a placa NodeMCU, é necessário adicionar a rede Wifi, senha do Wifi e o token do Ubidots obtido.

![confi-wifi-ino](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/2e0d5ce8-0a84-42d8-b51f-5bba7656582f)

Assim, depois de seguir todos os passos, ao colocar o dedo no sensor de batimento cardíaco, é possível observar o LED piscando conforme os batimentos, e observar os dados no dashboard do Ubidots no formato de sua preferência. Eu escolhi por exemplo o gráfico de linhas para visualização.

![image](https://github.com/valquiriastorer/iot-sensor-cardiaco/assets/101532054/871ab923-a2d1-401c-b3c8-eb9c1fb88ffa)
