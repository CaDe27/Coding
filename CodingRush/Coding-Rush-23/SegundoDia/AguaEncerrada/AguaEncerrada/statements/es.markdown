# Descripción
Ha llovido a cantaros anoche en Codinglandia y todo es un caos. La ciudad puede describirse con n enteros no negativos que representan la altura a la que llega la ciudad en ese lugar. Debido a la distinta elevación de la ciudad, hay agua acumulada en algunos puntos. Tu tarea es calcular la cantidad de agua acumulada en la ciudad.

Por ejemplo, supongamos que Codinglandia se describe con los enteros $[0,1,0,2,1,0,1,3,2,1,2,1]$. En la siguiente imagen con negro se describe la tierra de la ciudad y con azul el agua que queda encerrada:
![Texto alternativo](ejemplo.jpg)

Así, la respuesta de este ejemplo será 6. 

### Entrada
Primero un número entero $n$, la cantidad de enteros que describen a la ciudad. 

Después $n$ líneas, un número entero no negativo en cada una que representa altitud de la tierra en ese lugar. 

### Salida
Un número entero, representando la cantidad de agua encerrada. 

### Ejemplos

||input
12
0
1
0
2
1
0
1
3
2
1
2
1
||output
6
||description
Este es el caso descrito en la descripción. 
||input
3
4
2
5
||output
2
||description
||end

## Límites
* $ 1 \leq n \leq 10^3$
* $ 0 \leq h_i \leq 10^5$ donde $h_i$ representa la altura de la tierra en la posición i. Es decir, toda las altitudes están entre 0 y $10^5$.