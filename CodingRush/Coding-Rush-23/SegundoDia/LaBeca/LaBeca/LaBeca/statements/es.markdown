# Descripción
Fabio es un estudiante del ITAM y quiere calcular su promedio de este semestre para ver si puede mantener su beca el siguiente semestre o no.

Actualmente está cursando 5 materias, por lo que tendrá 5 calificaciones $C$.  Para poder mantener su beca, deberá mantener un promedio igual o mayor a 9.

Ayúdale a Fabio a calcular su promedio para ver si mantuvo la beca.

# Entrada
Cinco enteros positivos, uno en cada línea. Estos enteros representan las calificaciones de Fabio en las materias. 

# Salida
En la primera línea imprime el promedio. 
En la segunda línea imprime SI si mantiene la beca o NO si no la mantiene.


# Example
||input
9
10	
7	
10	
9 	

||output
9.0
SI
||description
La suma de las calificaciones es 9+10+7+10+9=45, por lo que el promedio es 45/5 = 9. Como 9 >= 9, sí la mantiene. 
||input
5
6
5
5
5
||output
5.2
NO
||description
La suma de las calificaciones es 5+6+5+5+5=26, por lo que el promedio es 26/5 = 5.2. Como 5.2 < 9, no la mantiene.  
||end

# Constraints
* Cada calificación es un número entero positivo entre 5 y 10, inclusive. 
