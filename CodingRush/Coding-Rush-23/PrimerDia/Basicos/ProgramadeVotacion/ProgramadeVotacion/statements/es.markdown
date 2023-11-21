#Descripción

Escribe un programa que pida al usuario su nombre y año de nacimiento.
El programa tendrá que determinar si el usuario es mayor de edad. 
Finalmente, como impresión, el programa debe mostrar uno de tres mensajes (suponiendo que el nombre dado es "Dave"): 

 1. "¡Dave, tienes suficiente años de edad para votar y has sido elegible durante {x} años!", si el usuario tiene 18 años o más y ha sido elegible para votar durante x años (donde x es el número de años desde que el usuario cumplió 18 años). 
 2. "¡Dave, tienes suficientes años de edad para votar!", si el usuario tiene 18 años o más pero aún no ha sido elegible para votar durante un año completo.
 3. "¡Dave, aún no tienes edad para votar. ¡Por favor, vuelve en {x} años!", si el usuario es menor a 18 años (donde x es el número de años hasta que el usuario cumpla 18 años).

Para calcular la edad del usuario y el número de años que ha sido elegible para votar, puedes restar su año de nacimiento del año actual (puedes asumir que el año actual es 2023).

#Entrada:
El nombre del usuario (cadena de caracteres).

El año de nacimiento del usuario (entero) $A$.

#Salida:
Un mensaje que indica si el usuario es lo suficientemente mayor como para votar en una elección, tal como se indica en la descripción. 

#Ejemplo:

||input
Alice
2000
||output
¡Alice, tienes suficientes años de edad para votar y has sido elegible durante 5 años!
||description
2023 - 2000 = 23
23 - 18 = 5.
||input
Bob
2007
||output
¡Bob, aún no tienes edad para votar. ¡Por favor, vuelve en 2 años!
||description
2023 - 2007 = 16
18 - 16 = 2.
||input
Juanito
2005
||output
¡Juanito, tienes suficientes años de edad para votar!"
||description
2023 - 2005 = 18
||end

<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}

# Límites

* $0 \leq A \leq 2023$
