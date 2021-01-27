# Calaverita con Arduino #

Librería de Arduino para crear con facilidad una "calaverita" que detecte distancia, mueva la quijada, genere sonidos y emita luz de colores.

**Versión 1.0**

## Asignación de los pines por defecto: ##

| Pin | Componente |
| :------- | :------- |
| 3 | Servomotor |
| 5 | pin G del LED RGB |
| 6 | pin B del LED RGB |
| 7 | pin R del LED RGB |
| 9 | pin echo del Ultrasónico |
| 10 | pin trig del Ultrasónico |
| 11 | Buzzer |

## Tipo de LED RGB ##
> Para el tipo de LED RGB, se ofrecen 2 opciones, que son las siguientes:

| Constante | Descripción |
| :------- | :------- |
| `ANODO` | Para un LED RGB con ánodo común |
| `CATODO` | Para un LED RGB con cátodo común |

## Canción ##
> Para la elección de la canción, se ofrecen 6 opciones, que son las siguientes:

| Constante | Descripción |
| :------- | :------- |
| `STRANGER_THINGS` | Para el tema principal de la serie "Stranger Things" |
| `SAW` | Para la canción Hello Zepp de la saga "SAW" |
| `HALLOWEEN` | Para el tema principal de la saga "Halloween" |
| `EXORCISTA` | Para el tema principal de la película "El Exorcista" |
| `WALKING_DEAD` | Para el tema principal de la serie "The Walking Dead" |
| `JACK` | Para el tema principal de la película "El Extraño mundo de Jack |

## Color ##
> Para la elección del color, se ofrecen 8 opciones, que son las siguientes:

| Constante | Descripción |
| :------- | :------- |
| `ROJO` | Para el color rojo |
| `VERDE` | Para el color verde |
| `AZUL` | Para el color azul |
| `MAGENTA` | Para el color magenta |
| `AMARILLO` | Para el color amarillo |
| `CYAN` | Para el color cyan |
| `BLANCO` | Para el color blanco |
| `ALEATORIO` | Para obtener colores aleatorios |

## Distancia ##
> Para la distancia, se aceptan números entre 5 y 150, si se utiliza algún otro se ignorará y se utilizará el mínimo(5) o el máximo(150) según sea el caso.

# Sintaxis #
`objeto.inicializar(tipo);`

Donde:

- `tipo` - Indica si el LED RGB es ánodo o cátodo común

`objeto.activar(distancia, canción, color);`

Donde:
- `distancia` - Indica la distancia mínima con la que se activa la calaverita
- `cancion` - Indica la canción que el buzzer reproduce
- `color` - Indica el color que el LED RGB emite

Por Mónica P. Arroyo (monica@cualitec.com), 8 de abril del 2020.
