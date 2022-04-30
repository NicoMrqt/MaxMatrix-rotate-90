#include <MaxMatrix.h>

const int DIN = 12;     // DIN pin of MAX7219 module
const int CLK = 10;     // CLK pin of MAX7219 module
const int CS = 11;      // CS pin of MAX7219 module
const int maxInUse = 1; // Nbr de Modules

byte CharA[10] = {8, 8, B00000000, B00111100, B01100110, B01100110, 
B01111110,B01100110, B01100110, B01100110}; // A

byte SB[5][10] = {
    {8, 8, B00000000, B01100110, B01100110, B01100110, B01111110, 
    B01100110, B01100110, B01100110}, //H
    {8, 8, B00000000, B01111110, B01100000, B01100000, B01111100, 
    B01100000, B01100000, B01111110}, //E
    {8, 8, B00000000, B01100000, B01100000, B01100000, B01100000, 
    B01100000, B01100000, B01111110}, //L
    {8, 8, B00000000, B01100000, B01100000, B01100000, B01100000, 
    B01100000, B01100000, B01111110}, //L
    {8, 8, B00000000, B00111100, B01100110, B01100110, B01100110, 
    B01100110, B01100110, B00111100}  //O
  };

MaxMatrix matriceLed(DIN, CS, CLK, maxInUse);

void setup()
{
  matriceLed.init();          // MAX7219 initialization
  matriceLed.setIntensity(2); // initial led matrix intensity, 0-15
}

void loop()
{
  matriceLed.setDot(1, 4, HIGH); // allume la 5ème LED de la 2ème colonne
  delay(2000);

  matriceLed.clear(); // Eteint la matrice
  delay(500);

  for (int i = 0; i < 8; i++) // dessine progressivement une croix
  {
    matriceLed.setDot(i, i, HIGH);
    matriceLed.setDot(i, 7 - i, HIGH);
    delay(300);
  }

  matriceLed.clear(); // Eteint la matrice
  delay(500);

  matriceLed.writeSprite(0, 0, CharA); // Imprime A
  delay(2000);

  matriceLed.clear(); // Eteint la matrice
  delay(500);

  for (int i = 0; i < 5; i++) // Imrimme Hello
  {
    matriceLed.clear();
    matriceLed.writeSprite(0, 0, SB[i]);
    delay(1000);
  }

  matriceLed.clear(); // Eteint la matrice
  delay(500);
}
