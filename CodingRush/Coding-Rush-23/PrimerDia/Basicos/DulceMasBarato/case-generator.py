import random
import os
import itertools as it
from math import *

nombreProblema = "DulceMasBarato"
cases = 20
for i in range(0, cases):
    caseName = 'g0.{}.in'.format(i)
    
    precio1 = random.randint(1,100000)
    precio2 = random.randint(1,100000) 

    while precio1 == precio2:
        precio2 = random.randint(1,100000) 

    caseString = "%d\n" % precio1
    caseString = caseString + ("%d\n" % precio2)

    casePath = os.path.join(nombreProblema+'/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))