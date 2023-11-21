import random
import os
import itertools as it
from math import *

nombreProblema = "La Beca"
cases = 20

for i in range(2, cases):
    caseName = 'g0.{}.in'.format(i)
    C = 4
    
    arreglo = [random.randint(5, 10) for j in range(C)]
    caseString = "%d\n" % random.randint(5,10)
    for x in arreglo:
        caseString += "%d\n" % x

    casePath = os.path.join('LaBeca/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))