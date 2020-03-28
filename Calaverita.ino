//CONSIDERAR HACER LAS VARIABLES LOCALES
#include<Servo.h>
#include "Calaverita.h"
Servo quijada;
Calaverita calaverita(1, 2, 3, 13, 5, 6, 7);

/* Definición de pines 
#define pin_buzzer 3
#define pin_servo 4
#define pin_R 5
#define pin_G 7
#define pin_B 6
#define pin_trig 8
#define pin_echo 9 */

/* Definición de variables */
int tiempo;
float distancia;
float dist;

/* Constantes | Canciones */
#define EXORCISTA       1
#define STRANGER_THINGS 2
//#define SAW 3 

/* Constantes | Colores */
//#define ROJO            1
//#define VERDE           2
//#define AZUL            3
#define MAGENTA         4 
#define AMARILLO        5
#define CYAN            6
#define BLANCO          7
#define ALEATORIO       8

/* Constantes | RGB ánodo/cátodo*/
#define ANODO           1
#define CATODO          2

/* Notas Musicales */
#define DO 523.25

/* Tiempos */
#define prototipo 200

void setup()
{
}

void loop()
{
  calaverita.activar(ROJO);
}

void act(int centim, int cancion, int color)
{
  if(dist <= centim)
  {
    //AQUÍ VA EL FOR 
    quijada.write(5);
    //tone(pin_buzzer, DO);
    delay(200);
    //tone(pin_buzzer, DO);
    delay(200);
    quijada.write(90);
  }
  else
  {
    quijada.write(90);
    //noTone(pin_buzzer);
  }
}
