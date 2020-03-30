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

  /* Constantes | Canciones */
  #define EXORCISTA       1
  #define STRANGER_THINGS 2
  //#define SAW 3 

  /* Constantes | Colores */
  #define ROJO            1
  #define VERDE           2
  #define AZUL            3
  #define MAGENTA         4 
  #define AMARILLO        5
  #define CYAN            6
  #define BLANCO          7
  #define ALEATORIO       8

  /* Constantes | RGB ánodo/cátodo*/
  #define ANODO           0
  #define CATODO          1

  /* NOTAS MUSICALES */
  #define c4  261.6
  #define c4s 277.1
  #define d4  293.7
  #define d4s 311.1
  #define e4  329.6
  #define f4  349.2
  #define f4s 370
  #define g4  392
  #define g4s 415.3
  #define a4  440
  #define a4s 466.2
  #define b4  493.9
  #define c5  523.3
  #define c5s 554.4
  #define d5  587.3
  #define d5s 622.3
  #define e5  659.3
  #define f5  698.5
  #define f5s 734
  #define g5  784
  #define g5s 830.6
  #define a5  880
  #define a5s 932.3
  #define b5  987.8

  /* TIEMPOS */
  #define e 500
  #define m e/2
  #define q e/4
  #define d e*2

  class Calaverita
  {
    public:
      Calaverita(int tipo);
      float medir();
      void activar(int dist, int cancion, int color);
      void color_e(int color, int tipo);
      void color_a(int color, int tipo);
      
      Servo quijada;
    private:
      int _p_buzzer;
      int _p_trig;
      int _p_echo;
      int _p_R;
      int _p_G;
      int _p_B;
      int _p_servo;
      int _tipo;
  };

#endif
