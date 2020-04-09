/*
  Ejemplo simple que muestra la aplicación de la librería Calaverita.h

  Asignación de los pines por defecto:

    3  - Servomotor
    5  - Pin G del LED RGB
    6  - Pin B del LED RGB
    7  - Pin R del LED RGB
    9  - Pin echo del Ultrasónico
    10 - Pin trig del Ultrasónico
    11 - Buzzer

  Para el tipo de LED RGB, se ofrecen 2 opciones, que son las siguientes:

    ANODO   | Para un LED RGB con ánodo común
    CATODO  | Para un LED RGB con cátodo común

  Para la elección de la canción, se ofrecen 6 opciones, que son las siguientes:

    STRANGER_THINGS  | Para el tema principal de la serie "Stranger Things"
    SAW              | Para la canción Hello Zepp de la saga "SAW"
    HALLOWEEN        | Para el tema principal de la saga "Halloween"
    EXORCISTA        | Para el tema principal de la película "El Exorcista"
    WALKING_DEAD     | Para el tema principal de la serie "The Walking Dead"
    JACK             | Para el tema principal de la película "El Extraño mundo de Jack

  Para la elección del color, se ofrecen 8 opciones, que son las siguientes:

    ROJO      | Para el color rojo
    VERDE     | Para el color verde
    AZUL      | Para el color azul
    MAGENTA   | Para el color magenta
    AMARILLO  | Para el color amarillo
    CYAN      | Para el color cyan
    BLANCO    | Para el color BLANCO
    ALEATORIO | Para obtener colores aleatorios

  Para la distancia, se aceptan números entre 5 y 150, si se utiliza algún otro se ignorará
  y se utilizará el mínimo(5) o el máximo(150) según sea el caso.

  ////    SINTAXIS    ////

  objeto.inicializar(tipo);

    Donde:
      tipo      -->   Indica si el LED RGB es ánodo o cátodo común

  objeto.activar(distancia, canción, color);

    Donde:
      distancia -->   Indica la distancia mínima con la que se activa la calaverita
      cancion   -->   Indica la canción que el buzzer reproduce
      color     -->   Indica el color que el LEd RGB emite

   Por Mónica P. Arroyo, 8 de abril del 2020.
*/
#include<Servo.h>
#include <Calaverita.h>

Calaverita calaca; //Se crea el objeto de nombre "calaca"

void setup()
{
  calaca.inicializar(ANODO); //Se inicializa indicando el tipo de LED RGB
}

void loop()
{
  calaca.activar(15, SAW, ROJO); // Se activa dando una distancia de 15,
  // la canción  SAW,
  // y el color ROJO.
}
