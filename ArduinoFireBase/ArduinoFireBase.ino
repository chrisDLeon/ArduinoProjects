#include <NewPing.h>
#include "DHT.h" //cargamos la librería DHT
#define DHTPIN 2 //Seleccionamos el pin en el que se //conectará el sensor
#define DHTTYPE DHT11 //Se selecciona el DHT11 (hay //otros DHT)
#define TRIGGER_PIN 6
#define ECHO_PING 7
#define MAX_DISTANCE 400
DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que será usada por Arduino para comunicarse con el sensor

NewPing sonar(TRIGGER_PIN, ECHO_PING, MAX_DISTANCE);
const int IN_A0 = A0;

void setup() {
    pinMode (IN_A0, INPUT);
    Serial.begin(9600);
    dht.begin(); //Se inicia el sensor
}

void loop() {
    delay(1000);
    Serial.println(get_data());
}

float get_temperature() {

  return  dht.readTemperature();
}

float get_humidity() {

  return dht.readHumidity();
}

float get_distance() {
  return 20;
}

int get_luminosity() {
  return analogRead(0);
}

String get_data() {
 return "{\"temperature\": " + String(get_temperature()) + ", \"humidity\": " + String(get_humidity()) + ", \"distance\": " + String(get_distance()) + ", \"luminosity\": " + String(get_luminosity()) + "}"; 
}
