# Projeto de Monitoramento de Corais

## Problema

Os corais estão branqueando rapidamente devido ao aumento da temperatura da água e à acidificação causada pelo excesso de CO2. Para manter os corais saudáveis, a temperatura da água deve estar abaixo de 30 graus Celsius e o pH acima de 8.

## Nossa Proposta

Desenvolver um sensor que monitore a temperatura e o pH da água, permitindo ações rápidas para proteger os corais.

## Componentes do Projeto

 - Arduino Uno
 - Sensor de Temperatura DS18B20
 - Sensor de pH (simulado com um potenciômetro na plataforma Wokwi)
 - Sensor RTC para registrar a data e a hora de cada medição
 - LEDs: verde para indicar boas condições da água; vermelho para indicar alerta de risco

## Como Usar

1. Carregue o código para o Arduino através do simulador Wokwi.
 
2. Inicie o monitoramento:
- Dados na Serial: As informações de temperatura e pH, juntamente com a data e hora de cada medição, aparecerão na serial do computador, no caso do nosso projeto aparecerá na serial do Wokwi.
- LEDs e Mensagens:
- Se a temperatura estiver abaixo de 30 graus e o pH acima de 8, o LED verde permanecerá aceso e uma mensagem informará que as condições da água são boas.
- Se a temperatura e/ou o pH estiverem fora desses parâmetros, o LED vermelho acenderá e uma mensagem de alerta de risco será emitida.

## Requisitos

- Hardware:
  - Arduino Uno
  - Sensor de Temperatura DS18B20
  - Sensor de pH ou potenciômetro para simulação
  - Sensor RTC (Real Time Clock)
  - LEDs (verde e vermelho)
  - Jumpers e Protoboard

## Dependências

Para este projeto, utilizamos as seguintes bibliotecas da Arduino :
- OneWire.h e DallasTemperature.h para o sensor de temperatura DS18B20
- RTClib.h para o sensor RTC
- Wire.h para comunicação I2C

## Benefícios

- Intervenção Rápida: Com os dados coletados, é possível agir rapidamente para proteger os corais.
- Educação Ambiental: O projeto pode ser usado para educar sobre os impactos ambientais e a importância da conservação dos recifes de corais.
- Recuperação dos Recifes: Contribui para os esforços de recuperação e preservação dos recifes de corais.





## Alunos
### Thamiris Almeida - RM559155
### Werbeth Nunes - RM559067
