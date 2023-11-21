# Anagramas y Cubetas.
Hoy en la escuela pedro aprendió que los anagramas son palabras que tienen exactamente las mismas letras pero en un orden distinto. A Pedro le encantaron los anagramas pero está teniendo problemas para identificarlos en la tarea que le mandaron. En su tarea le dan $N$ pares de dos palabras de las cuáles debe indicar si son anagramas o no y necesita tu ayuda para identificarlos. 
En la tarea solo vienen cadenas de números (de dígitos de 0-9).

# Entradas:
Se recibe el número $N$, el número de pares a comparar, seguido de N pares de strings.

# Salidas:
SI en caso de que sean anagramas y NO en caso contrario.

# Ejemplo:
||input
4
1234321
1122334
1
12
9
9
12345
53412
||output
SI
NO
SI
SI
||description
Cuatro pares de cadenas de números. La única que no tiene los mismos dígitos la misma cantidad de veces es el segundo par ('1' y '12')
||end

# Límites
* $1 \leq $N$ \leq 100$

<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}