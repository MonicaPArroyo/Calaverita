/*
   Calaverita.cpp - Librería para crear con facilidad una
   "calaverita" que detecte distancia, mueva la quijada,
   genere sonidos y emita luz de colores.
   Creada por Mónica P. Arroyo, 27 de marzo del 2020.
*/

#include "Arduino.h"
#include<Servo.h>
#include "Calaverita.h"

/* MATRIZ DE CANCIONES */
int notas[6][32] =
{
  {c4,  e4,  g4,  b4,  c5,  b4,  g4,  e4},  // STRANGER THINGS
  {e4,  a4,  e4,  b4,  e5,  g4,  a4,  e4,  c5,  e4,  d5,  e4,  b4,  c5},  // EXORCISTA
  {d4,  e4,  f4,  d4,  e4,  f4,  e4,  d4,  e4,  f4,  g4}, // HELLO ZEPP
  {c6s, f5s, p_e, f5s, c6s, f5s, p_e, f5s, c6s, f5s, d6,  f5s}, // HALLOWEEN
  {b4,  f5,  f5s, f5,  b4,  p_e, b4,  f5,  f5s, f5,  b4,  p_e, b4,  f5,  f5s, f5},  // WALKING DEAD
  {g4,  p_e, g4,  p_e, g4,  p_e, g4,  g4s, f4,  p_e, f4,  p_e, f4,  p_e, f4,  g4s, g4, p_e, g4,  p_e, g4,  p_e, g4,  g4s, f4,  p_e, f4,  g4s, g4,  p_e, g4,  p_e} ///* THIS IS HALLOWEEN */
};

int tiempos[6][32] =
{
  {q,  q,  q,  q,  q,  q,  q,  q},  ///* STRANGER THINGS */
  {q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q},  ///* EXORCISTA */
  {q,  q,  q4, q,  q,  q2, q,  q,  q,  q,  q2}, ///* HELLO ZEPP */
  {q,  q,  10, q,  q,  q,  10, q,  q,  q,  q,  q},  ///* HALLOWEEN */
  {q,  q,  q,  q,  q,  10, q,  q,  q,  q,  q,  10, q,  q,  q,  q},  ///* WALKING DEAD */
  {td, t,  td, t,  td, t,  td, td, td, t,  td, t,  td, t,  td, td, td, t,  td, t,  td, t,  td, td, td, t,  td, td, td, t,  td, t} ///* THIS IS HALLOWEEN */
};

int n_notas[6] = {8, 14, 11, 12, 16, 32};

//int st_nn = 8;
//int st_n[] = {c4, e4, g4, b4, c5, b4, g4, e4};
//int st_t[] = {q, q, q, q, q, q, q, q};
//

//int e_nn = 14;
//int e_n[] = {e4, a4, e4, b4, e5, g4, a4, e4, c5, e4, d5, e4, b4, c5};
//int e_t[] = {q, q, q, q, q, q, q, q, q, q, q, q, q, q};
//

//int he_nn = 11;
//int he_n[] = {d4, e4, f4, d4, e4, f4, e4, d4, e4, f4, g4};
//int he_t[] = {q, q, q4, q, q, q2, q, q, q, q, q2};
//

//int ha_nn = 12;
//int ha_n[] = {c6s, f5s, p_e, f5s, c6s, f5s, p_e, f5s, c6s, f5s, d6, f5s};
//int ha_t[] = {q, q, 10, q, q, q, 10, q, q, q, q, q};
//

//int w_nn = 16;
//int w_n[] = {b4, f5, f5s, f5, b4, p_e, b4, f5, f5s, f5, b4, p_e, b4, f5, f5s, f5};
//int w_t[] = {q, q, q, q, q, 10, q, q, q, q, q, 10, q, q, q, q};
//

//int th_nn = 32;
//int th_n[] = {g4, p_e, g4, p_e, g4, p_e, g4, g4s, f4, p_e, f4, p_e, f4, p_e, f4, g4s, g4, p_e, g4, p_e, g4, p_e, g4, g4s, f4, p_e, f4, g4s, g4, p_e, g4, p_e};
//int th_t[] = {td, t, td, t, td, t, td, td, td, t, td, t, td, t, td, td, td, t, td, t, td, t, td, td, td, t, td, td, td, t, td, t};


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

void Calaverita::activar(int dist, int cancion, int color)
{

  float distancia = Calaverita::medir();
  if (distancia <= dist)
  {
    //for(int x = 0; x <
    color_e(color);
    color_a(color);
  }
  //  if(dist <= centim)
  //  {
  //    //AQUÍ VA EL FOR
  //    //quijada.write(5);
  //    //tone(pin_buzzer, DO);
  //    delay(200);
  //    //tone(pin_buzzer, DO);
  //    delay(200);
  //    //quijada.write(90);
  //  }
  //  else
  //  {
  //    //quijada.write(90);
  //    //noTone(pin_buzzer);
  //  }
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

void Calaverita::color_e(int color)
{
  switch (color)
  {
    case 1:
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, !_tipo);
      digitalWrite(_p_B, !_tipo);
      break;
    case 2:
      digitalWrite(_p_R, !_tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, !_tipo);
      break;
    case 3:
      digitalWrite(_p_R, !_tipo);
      digitalWrite(_p_G, !_tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 4:
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, !_tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 5:
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, !_tipo);
      break;
    case 6:
      digitalWrite(_p_R, !_tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 7:
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 8:
      digitalWrite(_p_R, random(2));
      digitalWrite(_p_G, random(2));
      digitalWrite(_p_B, random(2));
      break;
  }
}

void Calaverita::color_a(int color)
{
  digitalWrite(_p_R, !_tipo);
  digitalWrite(_p_G, !_tipo);
  digitalWrite(_p_B, !_tipo);
}
