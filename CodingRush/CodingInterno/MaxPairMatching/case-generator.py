import random
import os
import itertools as it
from math import *

cases = 15
for i in range(1, cases):
    caseName = '{}.in'.format(i)
    N = random.randint(1, 100000)
    
    entrada = str(N)+"\n"
    for i in range(2*N):
        entrada = entrada + str(random.randint(0, 1000000000)) + " " + str(random.randint(0, 1000000000)) + "\n"

    casePath = os.path.join('maxPairMatching/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(entrada)
