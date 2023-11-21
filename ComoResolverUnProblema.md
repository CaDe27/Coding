# Cómo resolver un problema de programación competitiva
## Pasos generales
1. Entender el problema 
2. Entender los límites de tiempo y de memoria
3. Diseñar una solución o algoritmo
4. Implementar el algoritmo

## Diseñar una solución
Significa encontrar un algoritmo que funciona para cualquier tipo de caso descrito y que cumple el objetivo planteado sin importar el tipo de caso que me presenten. 

Hasta cierto punto, esto significa encontrar un patrón global. Al inicio del problema, los casos parecen tener mucho caos. La idea de solucionar un problema es ir reduciendo el caos. 

### Caja de herramientas de técnicas
0. Solo simular / Brute force
1. Recordar problemas similares. 
   
#### Técnicas que sirven para empezar a atacar
1. Hacer y entender casos pequeños (Ir complicándolos poco a poco).
2. Buscar patrones. ¿Qué cosas siempre pasan?
3. Poner atención a las cosas que son diferentes o a las cosas que parecen romper los patrones. 
4. Considerar casos extremos:
   1. entrada vacía
   2. el número más -*alguna propiedad*-
      1. más grande
      2. más pequeño
      3. más a la derecha (el último)
      4. más a la izquierda (el primero)
      5. en teoría de números: números primos
      6. en grafos: hojas
   3. entradas límite
      1. el número más pequeño que me pueden dar
      2. el número más grande que me pueden dar
      3. la máxima cantidad de datos que me pueden dar
5. Considerar otras formas de representar la información de entrada (estructuras de datos): 
   Estas observaciones se pueden hacer al inicio, pero aveces también surgen de preguntas que se le hacen después al problema y de pensar "para responder esta pregunta más fácil puedo organizar la entrada de esta forma". 
   1. ordenar la entrada
   2. representación binaria
   3. pre-procesar la entrada
6. Trabajar hacia atrás.
7. Considerar paridad.
8. Dividir en casos
9.  Ponerse curioso con las preguntas que le haces al problema. 

#### Técnicas especializadas
1. Divide y vencerás. 
2. Greedy 
3. Dos punteros (sliding window)
4. Búsqueda binaria
5. Programación dinámica
6. Backtracking
7. Teoría de grafos
   1. ciclos
   2. dfs, bfs, junion-find, diikstra
   3. no dirigidas: árbol dfs
   4. dirigidas: componentes fuertemente conexas, topological sort
8. Buscar simetrías
9. Análisis matemático
   1. Inducción matemática
   2. teoría de números: divisibilidad, números primos, factorización en primos
   3. combinatoria
   4. teoría de la probabilidad
10. juegos
11. 

#### Formalizar tu solución 
Tienes que asegurar que tu prueba es **correcta**. Para ello debes enunciar los supuestos que haces e irlos probando. 

Técnicas para formalizar:
1. Usar variables en lugar de números
2. Inducción matemática
3. Contradicción
4. Dividir en casos
5. Invarianza.
6. Enunciar teoremas conocidos (conocer las hipótesis necesarias para que se cumpla el resultado).