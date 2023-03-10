//////////// LIBRARY ////////////
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GPS.h>
#include <Adafruit_PMTK.h>
#include <NMEA_data.h>


/////////// BUTTON ///////////
int BUTTON_PIN = 4;
int buttonPressedCount = 0;
bool isPressed = true;

unsigned long previousMillis = 0;
unsigned long lastPressed = 0;


///////////// GPS /////////////
// I2C communication
Adafruit_GPS GPS(&Wire);

#define GPSECHO  true
unsigned long timer = millis();


///////// BLUETOOTH /////////
SoftwareSerial hc06(2,3);


void setup() {
  ///////////SERIAL_COMMUNICATION////////////]
  Serial.begin(9600);
  while (!Serial) delay(10);

  //////////// GPS_SETUP /////////////
  Serial.println("Adafruit I2C GPS library basic test!");

  // The I2C address to use is 0x10
  GPS.begin(0x10);  
  // Turn on RMC (recommended minimum) and GGA (fix data) including altitude
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  
  // Set the update rate to 1 Hz
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  
  // Request updates on antenna status, comment out to keep quiet
  GPS.sendCommand(PGCMD_ANTENNA);
  delay(1000);

  // Ask for firmware version
  GPS.println(PMTK_Q_RELEASE);


  /////////// BUTTON_SETUP ////////////
  pinMode(BUTTON_PIN, INPUT);

  
  //////////// BLUETOOTH ////////////
  hc06.begin(9600);
}

void loop() {
  ///////// UPDATE_GPS //////////
  char c = GPS.read();
  
  // if a sentence is received, we can check the checksum, parse it...
  if (GPS.newNMEAreceived()) {
   
    // this also sets the newNMEAreceived() flag to false
    if (!GPS.parse(GPS.lastNMEA())){ 
      // we can fail to parse a sentence in which case we should just wait for another
      return;
    }
  }


  ////////// BUTTON //////////
  unsigned long currentMillis = millis();

  if(digitalRead(BUTTON_PIN) == HIGH){
    if(isPressed == false){
      isPressed = true;

      unsigned long timeSincePressed = (unsigned long)(currentMillis - previousMillis);
      // Uncomment to check how long since last time button was pressed
      // Serial.println(timeSincePressed);

      if(timeSincePressed <= 5000){
        // Uncomment to check buttonPressedCount
        // Serial.println(buttonPressedCount);
        buttonPressedCount++;

        previousMillis = currentMillis;

        if(buttonPressedCount >= 3){

          ////////////// GET_COORDINATES //////////// 
          if (millis() - timer > 2000) {
            timer = millis(); 
        
           if (GPS.fix) {
             Serial.print("Location: ");
             Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
             Serial.print(", ");
             Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
            }
          }
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
