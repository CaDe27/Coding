import random
import os
import itertools as it
from math import *

nombreProblema = "AntojitosDeJG"
cases = 20
productos = ["Muffin", "Brownie", "Dona", "Galleta", "Pastel"]

for i in range(2, cases):
    caseName = 'g0.{}.in'.format(i)
    N = random.randint(1, 100)
    caseString = "%d\n" % N
    for i in range(N):
        caseString += "%s\n" % productos[random.randint(0, len(productos)-1)]
    
    M = random.randint(1, 100)
    caseString += "%d\n" % M
    for i in range(M):
        caseString += "%s\n" % productos[random.randint(0, len(productos)-1)]
        
    casePath = os.path.join(nombreProblema+'/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))