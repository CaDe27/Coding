import random
import os
import itertools as it
from math import *

nombreProblema = "CalculodePromedios"
cases = 20
for i in range(0, cases):
    caseName = 'g0.{}.in'.format(i)
    
    arreglo = [random.randint(0,10) for _ in range(4)]
    caseString = ""

    for x in arreglo:
        caseString += "%d\n" % x

    casePath = os.path.join("/Users/marianofranco/Desktop/Coding Rush/CalculodePromedios/" + nombreProblema+'/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))