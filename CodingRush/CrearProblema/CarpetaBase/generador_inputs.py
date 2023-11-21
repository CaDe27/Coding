import random
import os
from math import *

def genera_input_string():
    return 'caso_vacio'

nombre_problema =
cantidad_casos = 
nombre_grupo = ''
for caso in range(0, cantidad_casos):
    if nombre_grupo:
        nombre_caso = f'{nombre_grupo}.{caso}'
    else:
        nombre_caso = f'{caso}'
    
    input_string = genera_input_string()

    # lo unico que hace la funcion es pegar los strings con una diagonal /
    path_archivo = os.path.join(nombre_problema, 'cases', nombre_caso+'.in')
    with open(path_archivo, 'w') as f:
        f.write(input_string.strip('\t\n\r'))