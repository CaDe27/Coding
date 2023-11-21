import os

def algoritmo_solucion(archivo_input):
    return respuesta

nombre_problema = 
cantidad_casos = 
nombre_grupo = ''
for caso in range(cantidad_casos):
    if nombre_grupo:
        nombre_caso = f'{nombre_grupo}.{caso}'
    else:
        nombre_caso = f'{caso}'

    path_input = os.path.join(nombre_problema, 'cases', nombre_caso+'.in')
    with open(path_input, "r") as archivo_input:
        respuesta = algoritmo_solucion(archivo_input)
    
    path_output = os.path.join(nombre_problema, 'cases', nombre_caso+'.out')
    with open(path_output, "w") as archivo_output:
        archivo_output.write(respuesta.strip('\t\n\r'))