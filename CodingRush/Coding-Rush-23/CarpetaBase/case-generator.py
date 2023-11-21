import random
import os
import itertools as it
from math import *

nombreProblema = ""
cases = 20
for i in range(0, cases):
    caseName = 'g0.{}.in'.format(i)
    
    N = 10
    caseString = "%d\n" % N

    casePath = os.path.join(nombreProblema+'/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))