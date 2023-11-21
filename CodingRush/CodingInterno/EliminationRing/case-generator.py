import random
import os
import itertools as it
from math import *

def generaCaso(opcion, size):
    if size % 2 == 1:
        opcion = 1
    
    if opcion == 0:
        x = random.randint(1, size-1)
        y = random.randint(x+1, size)
        arre = [ x if i%2 == 1 else y for i in range(size)]
    elif opcion == 1:
        x = random.randint(1, size-2)
        y = random.randint(x+1, size-1)
        arre = [ x if i%2 == 1 else y  for i in range(size)]
        arre[0] =  size
    else:
        arre = [0] * size
        for i in range(size):
            arre[i] = random.randint(1, size)
            if i > 0:
                while arre[i] == arre[i-1]:
                    arre[i] = random.randint(1, size)
    return ' '.join([str(x) for x in arre])

baseString = """{N}
{entrada}
""".strip(' \t\n\r')

cases = 15
for i in range(3, cases):
    caseName = '{}.in'.format(i)
    if i == 3:
        N = 10000
        opcion = 0
    elif i == 4:
        N = 10000
        opcion = 1
    else:
        N = random.randint(2, 10000)
        opcion = random.randint(0, 2)
    
    entrada = generaCaso(opcion, N)
    case = {
        "N": N,
        "entrada": entrada
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('eliminationRing/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
