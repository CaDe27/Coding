import random
import os
import itertools as it
from math import *

baseString = """
{N}
{entrada}
""".strip(' \t\n\r')

cases = 18

for i in range(cases):
    caseName = '{}.in'.format(i+2)

    N = random.randint(1, 500000)
    ini = random.randint(0, random.randint(0, 10))
    if random.randint(0, 1) == 0:
        ud = 'U'
    else:
        ud = 'D'
    
    entrada = ""
    while(len(entrada) != N):
        if(len(entrada) == N-1):
            entrada += ud
        else:
            if(random.randint(0, 1) == 0):
                entrada += "LR"
            else:
                entrada += ud
    
    case = {
        'N': str(N),
        "entrada": entrada
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
