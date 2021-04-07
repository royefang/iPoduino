#include "lights.h"

void RGB(int red_value, int green_value, int blue_value){
  analogWrite(red_pin, red_value);
  analogWrite(green_pin, green_value);
  analogWrite(blue_pin, blue_value);
}

void flashRandomColors(){   
    randomSeed(analogRead(0));
    int randNumber1;
    int randNumber2;
    int randNumber3;
    for(int i = 0; i < 10; i++)
    {
        randNumber1 = random(0, 255);
        randNumber2 = random(0, 255);
        randNumber3 = random(0, 255);
        RGB(randNumber1,randNumber2,randNumber3);
        delay(150);
    }
    RGB(0,0,0);
}
