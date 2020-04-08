//CONSIDERAR HACER LAS VARIABLES LOCALES
#include<Servo.h>
#include "Calaverita.h"
Calaverita calaverita(ANODO);

void setup()
{
}

void loop()
{
  calaverita.activar(15, EXORCISTA, ROJO);
}
