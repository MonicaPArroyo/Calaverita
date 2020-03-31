/*
   Calaverita.cpp - Librería para crear con facilidad una
   "calaverita" que detecte distancia, mueva la quijada,
   genere sonidos y emita luz de colores.
   Creada por Mónica P. Arroyo, 27 de marzo del 2020.
*/

#include "Arduino.h"
#include<Servo.h>
#include "Calaverita.h"

/* STRANGER THINGS */
int st_nn = 8;
int st_n[] = {c4, e4, g4, b4, c5, b4, g4, e4};
int st_t[] = {q, q, q, q, q, q, q, q};

/* EXORCISTA */
int e_nn = 14;
int e_n[] = {e4, a4, e4, b4, e5, g4, a4, e4, c5, e4, d5, e4, b4, c5};
int e_t[] = {q, q, q, q, q, q, q, q, q, q, q, q, q, q};

/* HELLO ZEPP */
int h_nn = 13;
int h_n[] = {d4, e4, f4, p_e, d4, e4, f4, p_e, e4, d4, e4, f4, g4};
int h_t[] = {q, q, q, q*3, q, q, q, q*2, q, q, q, q, q};

//float C4 = 261.6,
//      C4S = 277.1,
//      D4 = 293.7,
//      D4S = 311.1,
//      E4 = 329.6,
//      F4 = 349.2,
//      F4S = 370,
//      G4 = 392,
//      G4S = 415.3,
//      a4 = 440,
//      A4S = 466.2,
//      B4 = 493.9,
//      C5 = 523.3,
//      C5S = 554.4,
//      D5 = 587.3,
//      D5S = 622.3,
//      E5 = 659.3,
//      F5 = 698.5,
//      F5S = 734,
//      G5 = 784,
//      G5S = 830.6,
//      a5 = 880,
//      A5S = 932.3,
//      B5 = 987.8,
//      C6 = 1046.5,
//      C6S =1108.7,
//      D6 = 1174.7,
//      D6S = 1244.5,
//      E6 = 1318.5,
//      F6 = 1396.91,
//      F6S = 1478,
//      G6 = 1568,
//      G6S = 1661.2,
//      a6 = 1760,
//      A6S = 1864.7,
//      B6 = 1975.5,
//      PAU = 0; 
//
//int   e=800,
//      m = e/2,
//      q = e/4,
//      d = e*2;

//HALLOWEEN
//int melodia[] = {C6S, F5S, PAU, F5S, C6S, F5S, PAU, F5S, C6S, F5S, D6,F5S};
//int duracionNota[] = {q,q,10,q,q,q,10, q, q, q, q, q};
//int tam =12;
//SAW
//int melodia[] = {D4,E4,F4,D4,E4,F4, E4, D4, E4, F4, G4};
//int duracionNota[] = {q,q,q*4,q,q,q*2,q,q,q,q,q*2};
//int tam =11;

//WALKING DEAD
//int melodia[] = {B4, F5, F5S, F5, B4, PAU, B4, F5, F5S, F5, B4, PAU, B4, F5, F5S, F5};
//int duracionNota[] = {q, q, q, q, q,10, q,q,q,q,q,10,q,q,q, q};
//int tam =16;


//THIS IS HALLOWEEN
//int t = 300;
//int qu = 310;
//int melodia[] = {G4, PAU, G4, PAU, G4, PAU, G4, G4S, F4, PAU, F4, PAU, F4, PAU, F4, G4S, G4, PAU, G4, PAU, G4, PAU, G4, G4S, F4, PAU, F4, G4S, G4, PAU, G4, PAU};
//int duracionNota[] = {qu, t, qu, t, qu, t, qu, qu, qu, t, qu, t, qu, t, qu, qu, qu, t, qu, t, qu, t, qu, qu, qu, t, qu, qu, qu, t, qu, t};
//int tam =32;

Calaverita:: Calaverita(int tipo)
{
  _p_buzzer = 11;
  _p_trig = 10;
  _p_echo = 9;
  _p_R = 8;
  _p_G = 6;
  _p_B = 7;
  _p_servo = 5;
  _tipo = tipo;
  digitalWrite(_p_R, !_tipo);
  digitalWrite(_p_G, !_tipo);
  digitalWrite(_p_B, !_tipo);
  pinMode(_p_buzzer, OUTPUT);
  pinMode(_p_trig, OUTPUT);
  pinMode(_p_echo, INPUT);
  pinMode(_p_R, OUTPUT);
  pinMode(_p_G, OUTPUT);
  pinMode(_p_B, OUTPUT);
  quijada.attach(_p_servo);
}

float Calaverita::medir()
{
  int tiempo;
  float distancia;
  digitalWrite(_p_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_p_trig, LOW);
  tiempo = pulseIn(_p_echo, HIGH);
  distancia = tiempo * 0.017;
  return distancia;
}

void Calaverita::activar(int dist, int cancion, int color)
{
  
  float distancia = Calaverita::medir();
  if(distancia <= dist)
  {
    color_e(color, _tipo);
    color_a(color, _tipo);
  }
}

void Calaverita::color_e(int color, int tipo)
{
  switch(color)
  {
    case 1:
      digitalWrite(_p_R, tipo);
      digitalWrite(_p_G, !tipo);
      digitalWrite(_p_B, !tipo);
      break;
    case 2:
      digitalWrite(_p_R, !tipo);
      digitalWrite(_p_G, tipo);
      digitalWrite(_p_B, !tipo);
      break;     
    case 3:
      digitalWrite(_p_R, !tipo);
      digitalWrite(_p_G, !tipo);
      digitalWrite(_p_B, tipo);
      break;   
    case 4:
      digitalWrite(_p_R, tipo);
      digitalWrite(_p_G, !tipo);
      digitalWrite(_p_B, tipo);
      break;   
    case 5:
      digitalWrite(_p_R, tipo);
      digitalWrite(_p_G, tipo);
      digitalWrite(_p_B, !tipo);
      break;   
    case 6:
      digitalWrite(_p_R, !tipo);
      digitalWrite(_p_G, tipo);
      digitalWrite(_p_B, tipo);
      break;   
    case 7:
      digitalWrite(_p_R, tipo);
      digitalWrite(_p_G, tipo);
      digitalWrite(_p_B, tipo);
      break;   
    case 8:
      digitalWrite(_p_R, random(2));
      digitalWrite(_p_G, random(2));
      digitalWrite(_p_B, random(2));
      break;
  } 
}

void Calaverita::color_a(int color, int tipo)
{
  digitalWrite(_p_R, !tipo);
  digitalWrite(_p_G, !tipo);
  digitalWrite(_p_B, !tipo);
}
