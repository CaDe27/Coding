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
    N = random.randint(2, 100000)
    entrada = [str(random.randint(0, 10000)) for _ in range(N)]
    case = {
        "N": N,
        "entrada": ' '.join(entrada)
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('containerWithMostWater/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
