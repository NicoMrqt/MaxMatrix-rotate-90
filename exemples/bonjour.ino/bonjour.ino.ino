#include <MaxMatrix.h>

const int DIN = 12;   // DIN pin of MAX7219 module
const int CLK = 10;   // CLK pin of MAX7219 module
const int CS = 11;    // CS pin of MAX7219 module
const int maxInUse = 1;

byte Message[7][10] = {
  { 8, 8,B00000000,B01111100,B01100110,B01100110,B01111100,B01100110,B01100110,B01111100}, 
  { 8, 8,B00000000,B00111100,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100}, 
  { 8, 8,B00000000,B01100011,B01110011,B01111011,B01101111,B01100111,B01100011,B01100011}, 
  { 8, 8,B00000000,B00011110,B00001100,B00001100,B00001100,B01101100,B01101100,B00111000}, 
  { 8, 8,B00000000,B00111100,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100}, 
  { 8, 8,B00000000,B01100110,B01100110,B01100110,B01100110,B01100110,B01100110,B00111110}, 
  { 8, 8,B00000000,B01111100,B01100110,B01100110,B01111100,B01111000,B01101100,B01100110}
};

MaxMatrix matriceLed(DIN, CS, CLK, maxInUse);

void setup() {
  matriceLed.init(); 
  matriceLed.setIntensity(2); 
}

void loop() {
  matriceLed.clear();
  matriceLed.setDot(6, 2,HIGH);
  delay(2000);
  matriceLed.clear();
   delay(2000);
 for (int i=0; i<7; i++){
  matriceLed.clear(); // Clears the display
  matriceLed.writeSprite(0, 0,Message[i]);
  delay(1000);
 }
}
