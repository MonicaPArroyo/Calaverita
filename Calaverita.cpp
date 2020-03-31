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
