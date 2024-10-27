// Nilesh Jain - 653929943
// Lab 9 - Recovery Lab
// 1. This code is supposed to show the details on the LCD dependeing on the amount of light
// that is being given to the photoresistor (Dark, Partially Dark, Medium, Partially Lit, Fully Lit).
// Youtube link - https://youtu.be/DjYDHdw6fKM

// LCD library
#include <LiquidCrystal.h>

// This defines the LCD wiring to the DIGITALpins
// LCD points
int rs = 12;
int en = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

// library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Photoresistor
int photoresistor = A0;
int photoresistorValue = 0;

// Potentiometer
int potentiometer = A1;
int potentiometerValue = 0;

void setup() {
  // output devices
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);

  // input devices
  pinMode(photoresistor, INPUT);
  pinMode(potentiometer, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Photoresistor values in the range from 500-800
  
  photoresistorValue = analogRead(photoresistor);
  potentiometerValue = analogRead(potentiometer);
  Serial.println(potentiometerValue);

  // if brightness level is 100%
  
  lcd.clear();
  
  if (photoresistorValue > 800) {
    lcd.print("Fully Lit");    
  } 

  // if brightness level is 75%
  else if(photoresistorValue < 800 && photoresistorValue > 700){
    lcd.print("Partially Lit");
  } 

  // if brightness level is 50%
  else if (photoresistorValue < 700 && photoresistorValue > 600) {
    lcd.print("Medium");
  } 

  // if brightness level is 25%
  else if(photoresistorValue < 600 && photoresistorValue > 500) {
    lcd.print("Partially Dark");
  } 

  // if brightness level is 0%
  else if (photoresistorValue < 500) {
    lcd.print("Dark");
  }

  // dleay for 0.1 second
  delay(100);
}
