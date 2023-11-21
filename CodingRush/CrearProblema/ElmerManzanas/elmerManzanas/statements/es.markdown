# Descripción
A Elmer le encantan las manzanas. Le gustan tanto que hoy ha traído $n$ manzanas al Coding Rush. Cada manzana pesa cierta cantidad de gramos, y el doctor le ha dado un límite de la máxima cantidad de gramos que puede comer antes de que le de indigestión. Ayuda a Elmer a determinar la máxima cantidad de manzanas que puede comer. 

# Entrada
- En la primera línea un número entero positivo $n$, el número de manzanas. 
- En la segunda línea, un número entero positivo $L$ el límite en gramos que puede comer Elmer. 
- Por cada una de las siguientes líneas, un número entero positivo $p_i$ determinando el peso de la $i$-ésima manzana. Los pesos se darán en orden, de menor a mayor. Así, primero estará el peso de la manzana menos pesada, y al final el de la manzana más pesada. 

# Salida
Un solo entero, la máxima cantidad de manzanas que puede comer Elmer.

# Ejemplo

||input
3
10
5
5
10
||output
2
||description
Hay tres manzanas y el límite es de 10 gramos. Así, Elmer se puede comer dos manzanas de 5 gramos. Elmer no puede comer 3 manzanas porque en total serían 5+5+10=20 gramos.
||input
3
4
5
5
10
||output
0
||description
En este ejemplo, Elmer no puede comer ninguna manzana. Comer cualquiera hace que se pasa del límite.
||end

# Límites
* 1 $\leq$ $n$, $L$, $p_i$ $\leq$ 100000