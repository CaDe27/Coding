
# Descripción
En la última reunión con sus amigos, Javier presumió de sus habilidades matemáticas y les dijo que podía encontrar la suma de todos los números que son múltiplo de $k$ en un intervalo dado. Sus amigos, un poco escépticos lo desafiaron a encontrar varias de estas sumas. Sin embargo, no están seguros de si las respuestas que Javier les dio eran correctas. Por lo tanto, los amigos de Javier acudieron a ti en busca de ayuda para verificar sus respuestas y determinar si estaba diciendo la verdad o no. ¿Puedes ayudarlos a resolver este problema matemático?

Nota: el número entero $k$ es múltiplo del número entero $d$ si $k$ puede ser escrito como $d$*$m$ con $m$ otro número entero. Por ejemplo: 12 es múltiplo de 3 porque 12 = 3*(4), 20 es múltiplo de 2 porque 20 = 2*(10). 

Importante: tu solución no te dará todos los puntos si solo vas sumando todos los múltiplos, uno por uno. Esta solución será muy lenta para algunos casos. Intenta usar el último problema del taller. 

# Entrada:
3 números enteros: $a$, $b$ y $k$
Donde $1$ $\leq$ $a$ $\leq$ $b$. 
Siendo $[a,b]$ el intervalo dado.
Cada entero se da en una línea distinta. 

Nota: en este problema, el intervalo $[a,b]$ representa a todos los números enteros entre $a$ y $b$, incluyéndolos. 

# Salida:
Un entero $N$ que representa la respuesta
# Ejemplo:
||input
5
15
3
||output
42
||description
Los múltiplos de 3 entre 5 y 15 son 6, 9, 12 y 15. Si sumas estos números obtienes 42. 
||end