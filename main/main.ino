////////////LIBRARY////////////
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GPS.h>
#include <Adafruit_PMTK.h>
#include <NMEA_data.h>


///////////BUTTON///////////
int BUTTON_PIN = 4;
int buttonPressedCount = 0;
bool isPressed = true;

unsigned long previousMillis = 0;
unsigned long lastPressed = 0;


/////////////GPS/////////////
Adafruit_GPS GPS(&Wire);

#define GPSECHO  true
unsigned long timer = millis();

////////////UART/////////////

/////////BLUETOOTH/////////
SoftwareSerial hc06(2,3);


void setup() {
  ///////////SERIAL_COMMUNICATION////////////]
  Serial.begin(9600);
  while (!Serial) delay(10);

  ////////////GPS_SETUP/////////////
  Serial.println("Adafruit I2C GPS library basic test!");

  // 9600 NMEA is the default baud rate for Adafruit MTK GPS's- some use 4800
  GPS.begin(0x10);  // The I2C address to use is 0x10
  // uncomment this line to turn on RMC (recommended minimum) and GGA (fix data) including altitude
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  // uncomment this line to turn on only the "minimum recommended" data
  //GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY);
  // For parsing data, we don't suggest using anything but either RMC only or RMC+GGA since
  // the parser doesn't care about other sentences at this time
  // Set the update rate
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // 1 Hz update rate
  // For the parsing code to work nicely and have time to sort thru the data, and
  // print it out we don't suggest using anything higher than 1 Hz

  // Request updates on antenna status, comment out to keep quiet
  GPS.sendCommand(PGCMD_ANTENNA);

  delay(1000);

  // Ask for firmware version
  GPS.println(PMTK_Q_RELEASE);



  ///////////BUTTON_SETUP////////////
  pinMode(BUTTON_PIN, INPUT);

  ////////////////////////////////////

  hc06.begin(9600);
}

void loop() {
  /////////UPDATE_GPS//////////
  // read data from the GPS in the 'main loop'
  char c = GPS.read();
  
  // if a sentence is received, we can check the checksum, parse it...
  if (GPS.newNMEAreceived()) {
    // a tricky thing here is if we print the NMEA sentence, or data
    // we end up not listening and catching other sentences!
    // so be very wary if using OUTPUT_ALLDATA and trying to print out data
    //Serial.println(GPS.lastNMEA()); // this also sets the newNMEAreceived() flag to false
    if (!GPS.parse(GPS.lastNMEA())) // this also sets the newNMEAreceived() flag to false
      return; // we can fail to parse a sentence in which case we should just wait for another
  }

  
  /*/////////CHECK FOR BLUETOOTH COM/////////
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

          //////////////GET_COORDINATES////////////
          if (millis() - timer > 2000) {
          timer = millis(); // reset the timer
        
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
