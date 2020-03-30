//CONSIDERAR HACER LAS VARIABLES LOCALES
#include<Servo.h>
#include "Calaverita.h"
Calaverita calaverita(ANODO);

/* Definición de variables */
float dist;





/* Notas Musicales */
#define DO 523.25

/* Tiempos */
#define prototipo 200

void setup()
{
}

void loop()
{
  calaverita.activar(15, EXORCISTA, ROJO);
}

void act(int centim, int cancion, int color)
{
  if(dist <= centim)
  {
    //AQUÍ VA EL FOR 
    //quijada.write(5);
    //tone(pin_buzzer, DO);
    delay(200);
    //tone(pin_buzzer, DO);
    delay(200);
    //quijada.write(90);
  }
  else
  {
    //quijada.write(90);
    //noTone(pin_buzzer);
  }
}
