import random
import os
from math import *

def genera_input_string():
    n = random.randint(1, 100000)
    input_string = f'{n}\n'

    L = random.randint(1, 100000)
    input_string += f'{L}\n'    
    
    lista_nums = [random.randint(1, 100000) for _ in range(n)]
    lista_nums.sort()

    for num in lista_nums:
        input_string += f'{num}\n'

    return input_string

nombre_problema = 'elmerManzanas'
cantidad_casos = 20
nombre_grupo = ''
for caso in range(2, cantidad_casos):
    if nombre_grupo:
        nombre_caso = f'{nombre_grupo}.{caso}'
    else:
        nombre_caso = f'{caso}'
    
    input_string = genera_input_string()

    # lo unico que hace la funcion es pegar los strings con una diagonal /
    path_archivo = os.path.join(nombre_problema, 'cases', nombre_caso+'.in')
    with open(path_archivo, 'w') as f:
        f.write(input_string.strip('\t\n\r'))