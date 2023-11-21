import random
import os
import itertools as it
from math import *

def generaCaso(opcion, size):
    if opcion == 0:
        return '1'*size
    elif opcion == 1:
        sizeIni = random.randint(0, N-2)
        sizeBloque = random.randint(1, N-1-sizeIni)
        return '1'*(sizeIni) + '0'*(sizeBloque) + '1'*(N-sizeIni - sizeBloque)
    else:
        chars = [random.randint(0, 1) for i in range(N-3)]
        entrada = "010"
        for x in chars:
            entrada += str(x)
        return entrada
    
baseString = """
{entrada}
""".strip(' \t\n\r')

cases = 19
for i in range(cases):
    caseName = 'g1.{}.in'.format(i)
    if i == 0:
        N = 500000
        opcion = 0
    elif i == 1:
        N = 500000
        opcion = 1
    elif i == 2:
        N = 500000
        opcion = 2
    else:
        N = random.randint(1, 500000)
        opcion = random.randint(0, 2)
    
    entrada = generaCaso(opcion, N)
    case = {
        "entrada": entrada
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
