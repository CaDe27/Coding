#Descripción

Este semestre llevas 4 materías: Matemáticas, Historia, Inglés, y Computación.
Quieres generar un programa que te permita ingresar tus promedios finales (sobre 10), y que calcule tu promedio final. 
Utilizando condicionales matemáticos, también deberás de imprimir un mensaje que indica si pasaste o no, junto con el promedio final.

#Entrada:
Cuatro enteros:

 1. La calificación de Matemáticas $M$.
 2. La calificación de Historia $H$.
 3. La calificación de Inglés $I$.
 4. La calificación de Computación $C$.

#Salida:
Una impresión de un mensaje que indica si pasaste o no, y tu promedio final.
Si pasaste, el mensaje deberá ser: "Pasaste, tu promedio es: " seguido del promedio.
Si no pasaste, el mensansaje deberá ser "No pasaste, tu promedio es: " seguido del promedio. 

#Ejemplo:

||input
10
8
6
9
||output
Pasaste, tu promedio es: 8.25
||description
8.25 > 6, por lo tanto, sí pasaste.
||input
6
8
6
0
||output
No pasaste, tu promedio es: 5
||description
5 < 6, por lo tanto, sí pasaste.
||end

<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}

# Límites

* $0 \leq M,H,I,C \leq 10$
