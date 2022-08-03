#include <SoftwareSerial.h>
#include<DHT.h>
SoftwareSerial bt(8,9);// Tx Rx
#define DATAPIN 3
#define DHTTYPE DHT11
DHT t(DATAPIN,DHTTYPE);
float temp;
float hum;
float f;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  t.begin(9600);
  bt.begin(9600);
  Serial.println("Date & Time, Humidity %, Temprature *C, *F");

}

void loop() {
  // put your main code here, to run repeatedly:
  hum = t.readHumidity();
  temp = t.readTemperature();
  f = t.readTemperature(true);

  bt.print(temp);
  bt.print(";");
  bt.print(hum);
  bt.println(";");

   Serial.print(",");
  Serial.print(hum);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.println(f);
 
  delay(2000);

}