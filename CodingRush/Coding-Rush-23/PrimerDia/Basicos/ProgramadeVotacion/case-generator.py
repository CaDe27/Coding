import random
import os
import itertools as it
from math import *

nombreProblema = "ProgramadeVotacion"
cases = 20
for i in range(0, cases):
    caseName = 'g2.{}.in'.format(i)
    
    nombre = "Nombre generico"
    A = random.randint(10,1000)

    caseString = "%s\n" % nombre
    caseString += "%d\n" % A

    casePath = os.path.join(nombreProblema+'/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))