/*
   Calaverita.cpp - Librería para crear con facilidad una
   "calaverita" que detecte distancia, mueva la quijada,
   genere sonidos y emita luz de colores.
   Creada por Mónica P. Arroyo, 27 de marzo del 2020.
*/

#include "Arduino.h"
#include<Servo.h>
#include "Calaverita.h"

Calaverita:: Calaverita(int p_buzzer, int p_trig, int p_echo, int p_R, int p_G, int p_B, int p_servo)
{
  pinMode(p_buzzer, OUTPUT);
  pinMode(p_trig, OUTPUT);
  pinMode(p_echo, INPUT);
  pinMode(p_R, OUTPUT);
  pinMode(p_G, OUTPUT);
  pinMode(p_B, OUTPUT);
  quijada.attach(p_servo);
  _p_buzzer = p_buzzer;
  _p_trig = p_trig;
  _p_echo = p_echo;
  _p_R = p_R;
  _p_G = p_G;
  _p_B = p_B;
  _p_servo = p_servo;
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

void Calaverita::activar(int color)
{
  
  if(color == 1)
  {
    digitalWrite(_p_R, HIGH);
    delay(500);
    digitalWrite(_p_R, LOW);
    delay(500);
  }
}
