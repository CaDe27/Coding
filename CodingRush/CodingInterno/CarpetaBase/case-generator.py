import random
import os
import itertools as it
from math import *

def generaCaso(opcion, size):
    return "ejemplo"

baseString = """{N}
{entrada}
""".strip(' \t\n\r')

cases = 15
for i in range(3, cases):
    caseName = '{}.in'.format(i)
    N = 1
    entrada = "ejemplo"
    
    entrada = generaCaso(0, N)
    case = {
        "N": N,
        "entrada": entrada
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('eliminationRing/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
