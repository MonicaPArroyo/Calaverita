/*
   Calaverita.cpp - Librería para crear con facilidad una
   "calaverita" que detecte distancia, mueva la quijada,
   genere sonidos y emita luz de colores.
   Creada por Mónica P. Arroyo, 8 de abril del 2020.
*/

#include "Arduino.h"
#include<Servo.h>
#include "Calaverita.h"

/* MATRIZ DE CANCIONES */
int notas[6][32] =
{
  {c4,  e4,  g4,  b4,  c5,  b4,  g4,  e4},  // STRANGER THINGS
  {d4,  e4,  f4,  d4,  e4,  f4,  e4,  d4,  e4,  f4,  g4}, // HELLO ZEPP
  {c6s, f5s, p_e, f5s, c6s, f5s, p_e, f5s, c6s, f5s, d6,  f5s}, // HALLOWEEN
  {e4,  a4,  e4,  b4,  e5,  g4,  a4,  e4,  c5,  e4,  d5,  e4,  b4,  c5},  // EXORCISTA
  {b4,  f5,  f5s, f5,  b4,  p_e, b4,  f5,  f5s, f5,  b4,  p_e, b4,  f5,  f5s, f5},  // WALKING DEAD
  {g4,  p_e, g4,  p_e, g4,  p_e, g4,  g4s, f4,  p_e, f4,  p_e, f4,  p_e, f4,  g4s, g4, p_e, g4,  p_e, g4,  p_e, g4,  g4s, f4,  p_e, f4,  g4s, g4,  p_e, g4,  p_e} // THIS IS HALLOWEEN
};

/* MATRIZ DE TIEMPOS */
int tiempos[6][32] =
{
  {q,  q,  q,  q,  q,  q,  q,  q},  // STRANGER THINGS
  {q,  q,  q4, q,  q,  q2, q,  q,  q,  q,  q2}, // HELLO ZEPP
  {q,  q,  10, q,  q,  q,  10, q,  q,  q,  q,  q},  // HALLOWEEN
  {q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q,  q},  // EXORCISTA
  {q,  q,  q,  q,  q,  10, q,  q,  q,  q,  q,  10, q,  q,  q,  q},  // WALKING DEAD
  {td, t,  td, t,  td, t,  td, td, td, t,  td, t,  td, t,  td, td, td, t,  td, t,  td, t,  td, td, td, t,  td, td, td, t,  td, t} // THIS IS HALLOWEEN
};

/* NÚMERO DE NOTAS */
int n_notas[6] =
{
  8,  // STRANGER THINGS
  11, // HELLO ZEPP
  12, // HALLOWEEN
  14, // EXORCISTA
  16, // WALKING DEAD
  32  // THIS IS HALLOWEEN
};

/* Función para inicializar el objeto */
void Calaverita:: inicializar(int tipo)
{
  // Pines asignados a los componentes conectados 
  _p_buzzer = 11; 
  _p_trig = 10;
  _p_echo = 9;
  _p_R = 7;
  _p_G = 5;
  _p_B = 6;
  _p_servo = 3;
  _tipo = tipo;

  pinMode(_p_buzzer, OUTPUT);
  pinMode(_p_trig, OUTPUT);
  pinMode(_p_echo, INPUT);
  pinMode(_p_R, OUTPUT);
  pinMode(_p_G, OUTPUT);
  pinMode(_p_B, OUTPUT);
  digitalWrite(_p_R, !_tipo);
  digitalWrite(_p_G, !_tipo);
  digitalWrite(_p_B, !_tipo);
  quijada.attach(_p_servo);
  quijada.write(5);
}

/* Función para ejecutar todo el funcionamiento de los componentes */
void Calaverita::activar(int dist, int cancion, int color)
{

  float distancia = Calaverita::medir(); 
  int tiempo_an = 0;
  int tiempo_ac;
  int bandera = 0;

  //x = constrain(x, 5, 150); //limita el valor de la distancia a estar entre 5 y 150
  
  if (distancia <= dist)
  {
    for (int x = 0; x < n_notas[cancion]; x ++)
    {
      tone(_p_buzzer, notas[cancion][x]);
      delay(tiempos[cancion][x]);
      noTone(_p_buzzer);
      tiempo_ac = millis();
      if (tiempo_ac - tiempo_an > 300)
      {
        tiempo_an = tiempo_ac;
        if (!bandera)
        {
          quijada.write(5);
          Calaverita::color_a();
        }
        else
        {
          quijada.write(90);
          Calaverita::color_e(color);
        }
        bandera = !bandera;
      }
      if (Calaverita::medir() > dist) break;
    }
  }
  else
  {
    noTone(_p_buzzer);
    color_a();
    quijada.write(5);
    delay(100);
  }
}

/* Función para medir la distancia con el ultrasónico */
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

/* Función para encender el LED RGB con el color seleccionado */
void Calaverita::color_e(int color)
{
  switch (color)
  {
    case 1: //ROJO
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, !_tipo);
      digitalWrite(_p_B, !_tipo);
      break;
    case 2: //VERDE
      digitalWrite(_p_R, !_tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, !_tipo);
      break;
    case 3: //AZUL
      digitalWrite(_p_R, !_tipo);
      digitalWrite(_p_G, !_tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 4: // MAGENTA
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, !_tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 5: //AMARILLO
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, !_tipo);
      break;
    case 6: //CYAN
      digitalWrite(_p_R, !_tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 7: //BLANCO
      digitalWrite(_p_R, _tipo);
      digitalWrite(_p_G, _tipo);
      digitalWrite(_p_B, _tipo);
      break;
    case 8: //ALEATORIO
      digitalWrite(_p_R, random(2));
      digitalWrite(_p_G, random(2));
      digitalWrite(_p_B, random(2));
      break;
  }
}

/* Función para apagar el LED RGB */
void Calaverita::color_a()
{
  digitalWrite(_p_R, !_tipo);
  digitalWrite(_p_G, !_tipo);
  digitalWrite(_p_B, !_tipo);
}
