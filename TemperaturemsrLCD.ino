/*
* Tamperature measurements and displaying with LCD
* Our connections:
*    LM35DZ has 3 pins
*    GND to GND
*    Vout to A0
*    Vs to 5V source on arduino

*      LCD display has 16 pins not all of the connections need to be used for this application
* LCD RS   =>   out8  or pin2
* LCD E    =>   out7  or pin3
* LCD D4   =>   out6  or pin7
* LCD D5   =>   out5  or pin8
* LCD D6   =>   out4  or pin13
* LCD D7   =>   out3  or pin12
* LCD R/W  =>   GND
*/

// You need to include this library if you want to use your LCD display
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 7, 8, 13, 12);  //initialization and pin indication  
int thermoPin = A0; 
int tempC, tempK,reading;  // temperature in Celcius, Kelvin and a store value from analogRead()
float tempC2;
  

void setup() { 
  lcd.begin(16, 2);              //declaration of # columns and lines
  analogReference(INTERNAL1V1);  //the reference is changed to 1.1 V for better resolution
  Serial.begin(9600);            //opens serial port communication, sets data rate to 9600 bps
}

void loop() {
  reading = analogRead(thermoPin);
  
  // conversion of Voltage to celcius
  tempC = round(reading / 9.31);

  // conversion to Kelvin
  tempK = tempC + 273;

  // displaying
  lcd.setCursor(0, 0);
  lcd.print(tempC);
  lcd.setCursor(4, 0); 
  lcd.print("Celsius"); 

  lcd.setCursor(0, 1);
  lcd.print(tempK);
  lcd.setCursor(5, 1); 
  lcd.print("Kelvin");
 
  delay(500); 
  lcd.clear();
}
