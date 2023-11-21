# Descripción
A Mau y a sus amigos les gusta desayunar en el café afuera del ITAM, “JG”. Es un café muy codiciado, por lo cual, aveces no tienen disponibilidad de ciertos productos. Todas las mañanas llega un camión con los productos para el día. JG te está pidiendo ayuda para que le ayudes a contabilizar cuántos productos hay de cada tipo de acuerdo a la siguiente clasificación:

 - Muffin
 - Brownie
 - Dona
 - Galleta
 - Pastel

Tu trabajo es decirle a clientes como Mau y sus amigos si JG tiene la cantidad de productos específicos que quieren ordenar y una vez que los ordenen, quitar una unidad del inventario.  

# Entrada
Primero vas a leer un número entero $n$ que representa la cantidad de productos que llegan para ese día.

Después $n$ líneas, en cada una una palabra que indica uno de los productos que llegó. 

En la siguiente línea, un número entero $m$, la cantidad de de órdenes que recibe JG. 

Después seguirán $m$ palabras que indican el producto que solicita tal cliente. Los clientes llegan en orden, por lo que primero se atiene al primer cliente, luego al segundo, y así susecivamente. 

# Salida
Por cada orden imprimirás "Bon appetit" si sí está disponible o "No disponible" si ya no hay de tal producto. 

# Ejemplos
||input
6
Muffin
Brownie
Muffin
Galleta
Dona
Dona
5
Muffin
Brownie
Dona
Galleta
Pastel
||output
Bon appetit
Bon appetit
Bon appetit
Bon appetit
No disponible
||description
No llegaron pasteles, por eso no hay disponibles. De todos los demás sí llegaron suficientes para cubrir las órdenes. 
||input
2
Muffin
Muffin
3
Muffin
Muffin
Muffin
||output
Bon appetit
Bon appetit
No disponible
||description
Se acaban los muffins para la tercer orden. 
||end

# Límites
* $1 \leq n \leq 100$
* $1 \leq m \leq 100$

<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}
