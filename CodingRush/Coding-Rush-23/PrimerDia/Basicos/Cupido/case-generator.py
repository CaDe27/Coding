import random
import os
import itertools as it
from math import *

cases = 20
for i in range(0, cases):
    caseName = 'g0.{}.in'.format(i)
    
    A = random.randint(2000, 2023)
    M = random.randint(1, 12)
    D = random.randint(1, 28)
    H = random.randint(1, 24)
    Mi = random.randint(1, 60)
    S = random.randint(1, 60)
   
    
    caseString = "{}\n{}\n{}\n{}\n{}\n{}\n".format(A, M, D, H, Mi, S)

    A = random.randint(2000, 2023)
    M = random.randint(1, 12)
    D = random.randint(1, 28)
    H = random.randint(1, 24)
    Mi = random.randint(1, 60)
    S = random.randint(1, 60)

    caseString +="{}\n{}\n{}\n{}\n{}\n{}\n".format(A, M, D, H, Mi, S)

    casePath = os.path.join('CadaSegundoCuenta/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))
