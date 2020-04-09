#include<Servo.h>
#include "Calaverita.h"
Calaverita calaverita;//(ANODO);

void setup()
{
  calaverita.inicializar(ANODO);
}

void loop()
{

  calaverita.activar(15, JACK, ROJO);
}
