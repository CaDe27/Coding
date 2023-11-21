# ¿Cómo subir un problema en OmegaUp?

Primero copia la carpeta base y cambia su nombre por el del problema a subir.

Hay cuatro cosas en la carpeta base. La carpeta más importante, y realmente la más valiosa es la que dice `nombreProblema`. Los otros archivos son para ayudarte a hacer algunas cosas más fácil. 

Ya que hayas modificado cada cosa, mándanos la carpeta en un .zip a **itamcodingrush@gmail.com**. Si tienes peticiones sobre los límites de tiempo y de memoria, igual puedes incluirlos en el correo. 

Ahor así, veamos cómo modificar cada cosa. 

## nombreProblema
Cambia el nombre de la carpeta por el nombre del problema a subir (sin espacios, solo es un nombre para identificar al problema). Hay tres carpetas dentro. Esto es lo que harás en cada una:

### statements
Hay una archivo que se llama `es.markdown`. Ahí pega la redacción del problema. Checa que se vea bien la redacción en esta [página](https://omegaup.com/redaccion.php).

Es también en esta carpeta donde se pone la plantilla, en caso de que quieras incluir una. Nombra al archivo `plantilla.py`, e inclúyela en la redacción del problema poniendo este bloque de código al final del archivo:
```
<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}
```

### cases
Aquí es donde pondrás los casos que deberá pasar el algoritmo para considerarse correcto. Puedes crear tantos casos como quieras. 

La recomendación es que crees manualmente casos extremos, y que crees algunos mediante el archivo generador_inputs.py que se encuentra dentro de la carpeta base inicial. Esto te ayudará a crear casos donde el input sea muy grande, que claramente no queremos generar a mano. 

También puedes generar los casos completamente a mano, solo asegúrate de que las pruebas sean adecuadas y no insuficientes para que algoritmos incorrectos sean calificados como correctos. 

Cada caso tendrá un archivo de entrada y un archivo con la salida esperada. La terminación del archivo de entrada es `.in` y la de la salida esperada es `.out`. Dentro del archivo de entrada literalmente va el caso a evaluar, y en el archivo de salida va la respuesta. 

Así, supongamos que hay tres casos. Entonces, habría seis archivos en esta carpeta: $0.in$, $0.out$, $1.in$, $1.out$, $2.in$, y $2.out$.

#### Agrupar casos
Hay una cosa importante para los problemas en los que la salida es `SI` o `NO`, o en los que son pocas las opciones de salida. En el caso de "SI"/"NO", alguien podría mandar una solución que sea `print("SI")` y obtener la mitad de los puntos del problema. Es por esto que se pueden agrupar casos. Para esto, ponle a los casos que quieras agrupar el prefijo que indique el nombre del grupo.

Siguiendo con el ejemplo de tener tres casos, y suponiendo que queremos agrupar los primeros dos casos, entonces el contenido de la carpeta sería:  $grupo1.0.in$, $grupo1.0.out$, $grupo1.1.in$, $grupo1.1.out$, $2.in$, y $2.out$.

### solutions(Opcional)
En la carpeta **solutions**, hay un archivo que se llama `es.markdown`. Hay redacta la solución a tu problema, es decir, las ideas u observaciones que llevan a crear el algoritmo que resuelve el problema. 

## solution.py
Pega aquí la solución del problema.

## genera_inputs.py
Como se mencionó, este archivo ayuda a generar casos *automáticamente*. Solo genera la entrada de los casos, es decir, los archivos `.in`. Para generar los `.out` se usará el archivo `genera_outputs.py`.

Lo que hace el archivo es usar un for. En cada iteración del for creará un caso nuevo. Para que esto pase, necesitamos crear un string que contenga el caso y luego guardarlo dentro de un archivo `.in` dentro de la carpeta de cases. La variable `nombre_caso` guardará el nombre del archivo donde se va a guardar el caso.

Así, lo que hay que modificar es lo siguiente:
1. la variable `nombre_problema`: asígnale un string que contenga el nombre de la carpeta del problema (en la que dentro está la carpeta cases).  
2. la variable `cantidad_casos`: un entero que contenga el número de casos que quieres generar en total. 
3. la variable `nombre_grupo`: solo es necesario modificarla si los casos a generar van dentro de un grupo. 
4. la función `genera_input_string`: debe devolver un string que contenga el caso que se va a guardar dentro del archivo de entrada.
    
    Te puedes ayudar de la librería random de python para generar números diferentes en cada caso. 

    También usa el caractér `\n` para representar los saltos de línea en el archivo. 

    Habrá veces en que quieras pegarle valores numéricos o valor de variables al caso. Para esto puedes usar *f-strings* de python. Búscalos en línea si no los conoces.  

    Por ejemplo, supongamos que nuestro input tiene primero una línea con un entero $n$ que está entre 1 y 100, luego hay $n$ líneas, cada una con un entero entre 30 y 1000. 

    Entonces la función se escribiría de la siguiente forma:
    ```python
    def genera_input_string():
        n = random.randint(1, 100)
        input_string = f'{n}\n'
        for _ in range(n):
            num = random.randint(30, 1000)
            input_string += f'{num}\n'
        return input_string
    ```
    
También nota que si tú generaste algunos archivos de forma manual, tendrás que cambiar los límites del for para no sobreescribir esos archivos. 

Supón que tú generaste tres casos a mano, `0.in`, `1.in` y `2.in`. En ese caso, no quieres que este archivo sobreescriba estos casos. Entonces tendrías que cambiar el for de la variable $caso$ por `for caso in range(3, cantidad_casos):`. De esa forma, los casos se empezarán a generar desde el `3.in` hasta el límite que tú pusiste. 

Ya que dejaste tu programa `generador_inputs.py` como querías, tienes que correrlo. Esto es corriéndolo como cualquier otro archivo de python. Por ejemplo, si estás en una terminal colocado en la misma carpeta donde está el archivo, solo corre `python generador_inputs.py`.

## genera_outputs.py
Con `genera_inputs.py` ya se generaron los casos, pero también hay que generar su respuesta. Para eso se usa `genera_outputs.py`.

Nota que tiene una gran similitud con el archivo `genera_inputs` en la forma en que itera sobre los casos y en la forma en que generan los paths. 

El objetivo es que para cada caso, tome el input del archivo `.in`, corra el algoritmo que soluciona el problema, e imprimir la respuesta en un archivo con el mismo nombre pero con terminación `.out`. 

Hay varias modificaciones, pero casi todas son análogas a las que hiciste en `genera_inputs.py`. Para correr el algoritmo se usa la función `algoritmo_solucion(archivo_input)`. Ahí pega la solución del problema, pero en lugar de usar la función `input()` para leer una línea de la consola, usar `archivo_input.readline()`. También, en vez de imprimir la respuesta como usualmente, haz que ese sea el `return` de la función.

Aquí también podrías modificar como itera la variable `caso` sobre los casos para no sobreescribir los `.out` que tú generaste, pero también es una buena idea dejar que los sobreescriba para ver que el algoritmo está funcionando correctamente. 

Cuando el archivo esté listo, córrelo como corriste el archivo `generador_inputs.py`. Por ejemplo, corriendo en la terminal `generador_outputs.py`.

