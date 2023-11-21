import random
import os
import itertools as it
from math import *

nombreProblema = "SucesionInfinita"
cases = 25
for i in range(0, cases):
    caseName = 'case{}.in'.format(i)
    
    a = random.randint(1,1250025000)

    caseString = "%d\n" % a

    casePath = os.path.join('SucesionInfinita/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))