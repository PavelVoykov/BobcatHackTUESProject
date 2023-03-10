////////////LIBRARY////////////
#include <SoftwareSerial.h>
#include <TinyGPS.h>

///////////BUTTON///////////
int BUTTON_PIN = 4;
int buttonPressedCount = 0;
bool isPressed = true;

unsigned long previousMillis = 0;
unsigned long lastPressed = 0;

////////////GPS//////////////

/////////BLUETOOTH/////////
SoftwareSerial hc06(2,3);


void setup() {
  ///////////SERIAL_COMMUNICATION////////////
  Serial.begin(9600);

  ///////////BUTTON_SETUP////////////
  pinMode(BUTTON_PIN, INPUT);

  ////////////////////////////////////

  hc06.begin(9600);
}

void loop() {
  /*/////////CHECK FOR GPS COM//////////
  

  /////////CHECK FOR BLUETOOTH COM/////////
  if (hc06.available()){
    Serial.write(hc06.read());
  }
  
  if (Serial.available()){
    hc06.write(Serial.read());
  }*/

  //////////BUTTON//////////
  unsigned long currentMillis = millis();

  if(digitalRead(BUTTON_PIN) == HIGH){
    if(isPressed == false){
      isPressed = true;

      unsigned long timeSincePressed = (unsigned long)(currentMillis - previousMillis);
      //Uncomment to check how long since last time button was pressed
      //Serial.println(age);

      if(timeSincePressed <= 5000){
        //Uncomment to check buttonPressedCount
        //Serial.println(buttonPressedCount);
        buttonPressedCount++;

        previousMillis = currentMillis;

        if(buttonPressedCount >= 3){
          Serial.println("SOS");
          buttonPressedCount = 0;
        }
      }else{
        buttonPressedCount = 0;
      }
    }
  }else{
    isPressed = false;
  }

  if(buttonPressedCount == 0){
    previousMillis = currentMillis;
  }

  delay(10);
}
