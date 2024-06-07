#include <Wire.h>
#include <RTClib.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define Sensor_temp A0
#define Pin_Pot A1
#define Led_Verde 8
#define Led_Vermelho 9

OneWire oneWire(Sensor_temp);
DallasTemperature sensors(&oneWire);

RTC_DS1307 rtc;

void setup() {

  Serial.begin(9600);
  sensors.begin();
  
  rtc.begin();

  pinMode(Led_Verde, OUTPUT);
  pinMode(Led_Vermelho, OUTPUT);
  
}

void loop() {

  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);

  DateTime now = rtc.now();
   
  int sensorPh = analogRead(Pin_Pot);
  float pH = sensorPh * (14.0 / 1023.0);


   if (temperatura < 30.0 && pH >= 8.0) {
    digitalWrite(Led_Verde, HIGH);
    digitalWrite(Led_Vermelho, LOW);

    Serial.println("Temperatura e pH em boas condições");

} else if (temperatura > 30.0 && pH < 8.0) {
    digitalWrite(Led_Verde, LOW);
    for (int i = 0; i < 3; i++) { 
        digitalWrite(Led_Vermelho, HIGH);
        delay(500);
        digitalWrite(Led_Vermelho, LOW);
        delay(500);
    }
    Serial.println("ALERTA! Temperatura elevada e Acidificação da Água");
    Serial.println("Risco para os Corais e Organismos marinhos");

} else if (temperatura > 30.0 && pH >= 8.0) {
    digitalWrite(Led_Verde, LOW);
    digitalWrite(Led_Vermelho, HIGH);

    Serial.println("ALERTA! Temperatura elevada");
    Serial.println("Risco para os Corais e Organismos marinhos");

} else {
    digitalWrite(Led_Verde, LOW);
    digitalWrite(Led_Vermelho, HIGH);

    Serial.println("ALERTA! Acidificação da Água");
    Serial.println("Risco para os Corais e Organismos marinhos");
}



  
  Serial.print("Data: ");
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(" - Hora: ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(" - Temperatura da água: ");
  Serial.print(temperatura);
  Serial.print(" °C - pH: ");
  Serial.println(pH);

  
 
  delay(1000);
}

  
