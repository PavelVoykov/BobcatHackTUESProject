////////////Libraries////////////
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

////////////GPS//////////////
Adafruit_GPS GPS(&Wire);

/////////Bluetooth/////////
SoftwareSerial hc06(2,3);

///////////Button////////////
int buttonPin = 3;
int buttonState;

void setup() {
/////////Serial communication///////////
  while(!Serial){}
  Serial.begin(9600);

  Serial.println("Adafruit GPS library basic I2C test");
  GPS.begin(0x10);

  hc06.begin(9600);

  pinMode(buttonPin, INPUT);
}

void loop() {
  /*/////////CHECK FOR GPS COM//////////
  if(Serial.available()){
    char c = Serial.read();
    GPS.write(c);
  }
  if(GPS.available()){
    char c = GPS.read();
    Serial.write(c);
  }

  /////////CHECK FOR BLUETOOTH COM/////////
  if (hc06.available()){
    Serial.write(hc06.read());
  }
  
  if (Serial.available()){
    hc06.write(Serial.read());
  }*/

  buttonState = digitalRead(buttonPin);
  /*if (buttonState == HIGH) {
    Serial.write("Button is high");
  } else {
    Serial.write("Button is low");
  }*/
}
