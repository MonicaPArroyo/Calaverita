/*
   Calaverita.h - Librería para crear con facilidad una
   "calaverita" que detecte distancia, mueva la quijada,
   genere sonidos y emita luz de colores.
   Creada por Mónica P. Arroyo, 27 de marzo del 2020.
*/

#ifndef Calaverita_h
  #define Calaverita_h

  #include "Arduino.h"
  #include <Servo.h>

  /* AQUÍ DEBO DECLARAR LAS NOTAS Y LOS TIEMPOS */
  /*¿TAMBIÉN LAS CONSTANTES DEL USUARIO?*/
  #define ROJO 1
  #define VERDE 2

  class Calaverita
  {
    public:
      Calaverita(int p_buzzer, int p_trig, int p_echo, int p_R, int p_G, int p_B, int p_servo);
      float medir();
      void activar(int color);
      Servo quijada;
    private:
      int _p_buzzer;
      int _p_trig;
      int _p_echo;
      int _p_R;
      int _p_G;
      int _p_B;
      int _p_servo;
  };

#endif
