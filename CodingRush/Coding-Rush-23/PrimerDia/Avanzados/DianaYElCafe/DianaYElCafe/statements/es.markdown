# Descripción
A Diana le encanta el café, tanto que puede tomarlo toooodo el día. Bueno, casi todo el día. Ella solo puede resistir cierta 
cantidad de cafeína por día. 

Estás comiendo con ella por su cumpleaños y te cuenta de todas las tazas que le trajeron sus amigos y la cantidad 
de cafeína que tenía cada una. La cosa es que no sabe en qué momento sobrepasó su límite de cafeína. Ayúdale a saber 
el número de la primera taza que sobrepasó su límite.

# Entrada
En la primera línea un número entero $L$, el límite de cafeína que soporta Diana

En la segunda línea un número entero $N$, la cantidad de tazas que le han traído

Después, $N$ líneas, en cada una un número entero, la cantidad de cafeína que tenía ese número de taza. Es decir, en la segunda línea viene la cafeína de la primera taza, en la tercera línea la cafeína de la segunda taza, etc. 


# Salida
Imprime el número de la primera taza que hizo a Diana sobrepasar su límite. 
Se garantiza que ella siempre sobrepasa su límite. 

# Ejemplos
||input
5
4
2
2
1
4
||output
4
||description
Hasta la tercer taza se llega al límite, pero no se sobrepasa. Es hasta la cuarta que la cafeína exceda 4. 
||input
3
4
2
2
1
2
||output
2
||description

||end

<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}

# Límites
*1 $\leq L \leq$ 1000000000

*1 $\leq N \leq$ 100000 

*1 $\leq T_i \leq$ 1000000000 donde $T_i$ es la cafeína de la $i$-ésima taza.  

