import random
import os
import itertools as it
from math import *

cases = 20
for i in range(2, cases):
    caseName = 'g0.{}.in'.format(i)
    
    L = random.randint(1, 1000000000)
    N = random.randint(2, 100000)
    arreglo = [random.randint(1, 1000000000) for _ in range(N-1)]
    arreglo.append(1000000000)
    
    caseString = "%d\n" % L
    caseString += "%d\n" %N
    for x in arreglo:
        caseString += "%d\n" % x

    casePath = os.path.join('DianaYElCafe/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))
