import os, io

def algoritmo_solucion(archivo_input):
    n = int(archivo_input.readline())
    L = int(archivo_input.readline())

    peso_acumulado = 0
    contador = 0
    for _ in range(n):
        peso_manzana = int(archivo_input.readline())
        if peso_acumulado + peso_manzana <= L:
            peso_acumulado += peso_manzana
            contador += 1
    return contador

nombre_problema = 'elmerManzanas'
cantidad_casos = 20
for caso in range(cantidad_casos):
    if caso < 2:
        nombre_grupo = 'g0'
    else:
        nombre_grupo = ''
    
    if nombre_grupo:
        nombre_caso = f'{nombre_grupo}.{caso}'
    else:
        nombre_caso = f'{caso}'

    path_input = os.path.join(nombre_problema, 'cases', nombre_caso+'.in')
    with open(path_input, "r") as archivo_input:
        respuesta = algoritmo_solucion(archivo_input)
    
    path_output = os.path.join(nombre_problema, 'cases', nombre_caso+'.out')
    with open(path_output, "w") as archivo_output:
        archivo_output.write(f'{respuesta}'.strip('\t\n\r'))