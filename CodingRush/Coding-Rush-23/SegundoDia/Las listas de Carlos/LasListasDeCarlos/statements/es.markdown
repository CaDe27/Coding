# Descripción
Carlos, un profesor de primaria, está intentando mejorar los juegos de ahorcado que le hace a sus alumnos. Para ello, acude a ti por tus excelentes habilidades de programación.

Carlos tiene una lista enorme de palabras que pone en juego con sus alumnos, y quiere una manera rápida de seleccionar palabras que no se parezcan a las que ya puso en juego. Se ha dado cuenta de que sus alumnos suelen intentar las mismas letras que fueron exitosas en juegos pasados. 

Para mejorar los juegos de Carlos, desarrolla un programa que reciba una lista de palabras e imprima solo aquellas palabras que no contengan una cierta letra que él te dará.

Para desarrollar tu programa, es muy importante considerar que la lista de Carlos solo tiene palabras en minúsculas.

# Entrada
Primero un número entero positivo $n$ que representará el tamaño de la lista de palabras.

Después, $n$ líneas, una palabra **en minúsculas** por línea.

Finalmente, darás la letra que Carlos no quiere ver en su nueva lista.

# Salida

Debes imprimir todas aquellas palabras que no contengan la letra que ingresaste. Se garantiza que siempre habrá al menos una palabra que no contenga la letra prohibida. 

# Ejemplo

||input
2
pana
miguel
p
||output
miguel
||description
Solo se imprime la palabra "miguel", pues esta no contiene la letra p.
||input
5
juego
carro
sol
parque
perro
e
||output
carro
sol
||description
Solo se imprimen las palabras "carro" y "sol", pues estas no contienen la letra e.
||end

<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}

