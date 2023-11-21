# El Mensaje Oculto

Imagínate que estás chateando con tu gran amigo Pedro, a quien confías varios de tu secretos. Le quieres enviar mensajes que solo él pueda leer. Un día, durante las clases se ponen de acuerdo para ver de qué manera van a cifrar los mensajes para que solamente ustedes entiendan lo que están leyendo.

Una vez que eligieron el método de cifrado, le dices a tu amigo que vas a hacer un programa que codifique los mensajes por ustedes.

- **Hint 1:** utiliza las funciones `ord()` y `chr()` para resolver este ejercicio.
- **Hint 2:** para las vocales recuerda incluir mayúsculas y minúsculas.

## Entrada

Recibirás una cadena con el mensaje que deseas encriptar.

## Salida

Mostrarás el mensaje cifrado usando las siguientes dos reglas:

1. Si es una vocal, entonces tienes que avanzar tantas letras como: la longitud de la cadena divida (división entera) entre la posición en la que se encuentra esa vocal.
2. Si la letra no es una vocal, entonces tienes que avanzar tantas letras como: la longitud de la cadena módulo la posición en la que se encuentra esa vocal.


## Ejemplo

||input
Hola
Armando
Pedro
||output
Hqmb
Hsnbpep
Pgfsp
||description
La primer letra es una **H**, como no es vocal entonces avanzas 4 % 1 = 0  (comenzamos a contar desde 1, por lo tanto la **H** tiene la posición 1), por lo tanto, la nueva letra es **H**. La siguiente letra es la **o**, como es vocal avanzas 4 // 2 = 2, por lo tanto, la nueva letra es **q**, y así sucesivamente.