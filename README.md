# ESP32 AP + Web Server

Este projeto cria uma rede Wi‑Fi própria no ESP32 e hospeda uma página web simples para controlar uma saída digital (nesse exemplo é a luz azul do ESP32 Devkit v1)

![](https://github.com/sadraico/Esp32_Wifi_Webserver/blob/main/images/Screenshot_20260720-224620.png)

## Visão geral

Ao ligar o ESP32, ele entra em modo **Access Point (AP)** e cria uma rede chamada `ESP32_Rede`.  
Depois disso, qualquer celular ou computador conectado nessa rede pode acessar a interface web do dispositivo pelo IP `192.168.4.1`.

## Funcionalidades

- Cria uma rede Wi‑Fi própria no ESP32
- Hospeda um servidor web local
- Exibe uma página com botão de controle
- Liga e desliga um pino digital via navegador
- Mostra mensagens de status no Serial Monitor

## Partes principais do projeto

### 1. Wi‑Fi em modo AP
O ESP32 é configurado como ponto de acesso, em vez de se conectar a um roteador externo.  
Isso permite usar o projeto sem internet e sem rede doméstica.

### 2. Servidor web
Um servidor HTTP roda na porta 80 e responde às requisições feitas pelo navegador.

### 3. Página HTML
A interface é criada diretamente no código e enviada ao navegador.  
Ela mostra o estado atual da saída e oferece botões para alternar entre ligado e desligado.

### 4. Controle do GPIO
Quando o usuário clica em um botão, o ESP32 altera o estado do pino configurado como saída.

### 5. Monitor Serial
O Serial Monitor exibe informações úteis como:
- rede criada
- IP do ESP32
- estado do servidor

## Como usar

1. Faça o upload do código para o ESP32
2. Abra o Serial Monitor em `115200`
3. Conecte seu celular ou computador à rede `ESP32_Rede`
4. Acesse o IP `192.168.4.1` no navegador
5. Use os botões para controlar a saída

## Requisitos

- ESP32
- Arduino IDE ou ArduinoDroid
- Biblioteca `WiFi.h`
- Biblioteca `WebServer.h`

## Observações

- A senha da rede deve ter pelo menos 8 caracteres 
- O IP padrão do modo AP normalmente é `192.168.4.1`
- O pino usado no exemplo pode ser alterado conforme sua necessidade

## Licença

MIT
