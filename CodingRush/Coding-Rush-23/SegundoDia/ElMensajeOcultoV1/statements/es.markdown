# Description

Imagínate que estás chateando con tu gran amigo Pedro, a quien confías varios de tu secretos. Le quieres enviar mensajes que solo él pueda leer. Un día, durante las clases se ponen de acuerdo para ver de qué manera van a cifrar los mensajes para que solamente ustedes entiendan lo que están leyendo.

Decidieron basarse en la tabla ascii para su cifrado. Así, nadie, entenderá el mensaje cifrado. Al escuchar esto, te emocionaste y decidiste ayudarles a crear un programa que haga la codificación. 

- **Hint 1:** utiliza las funciones `ord()` y `chr()` para resolver este ejercicio.
- **Hint 2:** para las vocales recuerda incluir mayúsculas y minúsculas.

## Entrada

Recibirás una cadena con el mensaje que deseas encriptar.

## Salida

Mostrarás el mensaje cifrado usando las siguientes dos reglas:

1. Si es una vocal, necesitas avanzar en la tabla ascii tantas letras como la posición en la que se encuentra esa vocal. Para este problema considera que la primera posición es la 1, diferente a lo que acostumbran los programadores. 
2. Si la letra no es una vocal, entonces tienes que avanzar en la tabla ascii tantas letras como la longitud de la cadena.

Es posible que cuando avances en la tabla ascii, se acaben las letras usuales. Eso está bien, estamos considerando toda la letra ascii como si todas fueran letras. Por ejemplo, al codificar la palabra 'zav' obtendrás '}cy' porque: 

* para ver quien va en lugar de la 'z', que no es una vocal, necesitas avanzar tres posiciones en la tabla ascii (la longitud de la cadena es tres). El caracter tres posiciones después de la 'z' en ascii es el caracter '}'. 

* para ver quien va en lugar de la 'a', que está en la posición 2 y es una vocal, necesitas avanzar dos posiciones en la tabla ascii. En este caso está la 'c' dos posiciones después que la 'a'. 

* para ver quien va en lugar de la 'v', que no es vocal, avanzas tres posiciones en la tabla ascii y obtienes 'y'. 

## Ejemplo
||input
zav
||output
}cy
||description
Explicado arriba en la salida
||input
Hola
||output
Lqpe
||description
La primer letra es una **H**, como no es vocal entonces avanzas 4 posiciones (la longitud de la cadena), por lo tanto, la nueva letra es **L**. La siguiente letra es la **o**, como es vocal avanzas dependiendo la posición en la que se encuentra, es decir, en la posición 2 (contando la H como la posición 1), por lo tanto, la nueva letra es **q**, y así sucesivamente.
||end