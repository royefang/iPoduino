/////////////////////////////////////////////////
//
//iPoduino by Roye Fang
//Inspired by and Dedicated to Bryan Wong and Jackie Lam
//Last Updated 11/23/2020
//
//iPoduino is a music player that plays three songs/pieces:
//    Frédéric Chopin's "Nocturne in E-flat Major, Opus 9 Number 2" (1830-1832)
//    Keyboard Cat's Iconic Keyboard Solo (2007)
//    Vanessa Carlton's "A Thousand Miles" (2002)
//iPoduino uses an Arduino Nano to power a passive buzzer. Each song/piece can be 
//selected using a potentiometer, identified using a RGB LED that changes color 
//according to the song/piece. If the potentiometer is not adjusted, then the 
//three songs/pieces will be played. To play another song, adjust the potentiometer 
//and press reset. 
//
//This project is dedicated to Bryan Wong and Jackie Lam,
//UCLA IEEE OPS project leads who introduced and taught many fundamental electrical
//and computer engineering concepts and applications for 2019-2020.
//
/////////////////////////////////////////////////

#include "music.h"
#include "lights.h"

//Pin defintions
#define potentiometer A6
#define led 5
#define red_pin 16
#define green_pin 15
#define blue_pin 14

void setup(){
  //Serial.begin(9600);
  pinMode(potentiometer,INPUT);
  pinMode(led,OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  flashRandomColors();
  delay(1000);
}

void loop(){
int x = analogRead(A6);

    if(x < 100){
        RGB(255,0,0);
        nocturne();
        RGB(0,255,0);
        keyboardCat();
        RGB(0,0,255);
        aThousandMiles();
        while(1);
    }
    else if(x < 900 && x >=100){
        RGB(0,255,0);
        keyboardCat();
        RGB(0,0,255);
        aThousandMiles();
        RGB(255,0,0);
        nocturne();
        while(1);
    }
    else if(x >= 900){
        RGB(0,0,255);
        aThousandMiles();
        RGB(255,0,0);
        nocturne();
        RGB(0,255,0);
        keyboardCat();
        while(1);
    }
}
