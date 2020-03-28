/*
   Calaverita.h - Librería para crear con facilidad una
   "calaverita" que detecte distancia, mueva la quijada,
   genere sonidos y emita luz de colores.
   Creada por Mónica P. Arroyo, 27 de marzo del 2020.
*/

#ifndef Calaverita_h
  #define Calaverita_h

  #include "WProgram.h"
  #include <Servo.h>

  class Calaverita
  {
    public:
      Calaverita(int p_buzzer, int p_servo, int p_trig, int p_echo, int p_R, int p_G, int p_B);
      float medir();
      void activar();
    private:
      int 
  };

  #endif
