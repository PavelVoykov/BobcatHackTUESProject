////////////LIBRARY////////////
#include <SoftwareSerial.h>
#include <TinyGPS.h>


///////////BUTTON///////////
int BUTTON_PIN = 4;
int ButtonPressedCount = 0;

unsigned long previousMillis=0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}


void loop() {
  /////////CHECK FOR GPS COM//////////


  /////////CHECK FOR BLUETOOTH COM/////////
 

  //////////BUTTON//////////
  unsigned long currentMillis = millis();

  if(digitalRead(BUTTON_PIN) == 1){
    previousMillis = currentMillis;
    currentMillis = millis();
      if((unsigned long)(currentMillis - previousMillis) <= 5000){
      Serial.println(ButtonPressedCount);
      ButtonPressedCount++;

      if(ButtonPressedCount == 3){
        Serial.println("SOS");
        ButtonPressedCount = 0;
      }
    }
  }
  delay(1000);  
}
