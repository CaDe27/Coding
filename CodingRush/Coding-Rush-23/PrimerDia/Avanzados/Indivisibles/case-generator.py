import random
import os
import itertools as it
from math import *

nombreProblema = "Indivisibles"
cases = 20
for i in range(3, cases):
    if nombre_grupo:
        nombre_caso = f'{nombre_grupo}.{i}'
    else:
        nombre_caso = f'{i}'
    
    N = random.randint(4, 1000)
    caseString = "%d\n" % N

    casePath = os.path.join(nombreProblema+'/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))