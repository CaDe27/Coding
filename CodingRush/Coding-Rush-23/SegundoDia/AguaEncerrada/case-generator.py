import random
import os
import itertools as it
from math import *

nombreProblema = "AguaEncerrada"
cases = 20
for i in range(0, cases):
    caseName = '{}.in'.format(i)
    caseString = ""
    if i < 10:
        n = random.randint(3, 1000)
        maxi = 100000
        a1 = [random.randint(0, maxi) for i in range((n-1)//2)]
        a2 = [random.randint(0, maxi) for i in range(n-1-((n-1)//2))]

        caseString += str(n)+"\n"
        for i in range((n-1)//2):
            caseString += str(a1[i])+"\n" if (i%2 == 1) else "0\n"
        caseString += str(maxi) + "\n"
        for i in range(n - 1 - (n-1)//2):
            caseString += str(a2[i])+"\n" if (i%2 == 1) else "0\n"
    elif i < 15:
        n = random.randint(2, 1000)
        maxi = 100000-1
        a1 = [random.randint(0, maxi-1) for i in range(n-2)]
        caseString += str(n)+"\n"
        caseString += str(maxi) + "\n"
        for i in range(n-2):
            caseString += str(a1[i])+"\n"
        caseString += str(maxi) + "\n"
    else:
        n = random.randint(2, 1000)
        a1 = [random.randint(0, 100000) for i in range(n)]
        caseString += str(n)+"\n"
        for i in range(n):
            caseString += str(a1[i])+"\n"

    casePath = os.path.join(nombreProblema+'/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString.strip('\t\n\r'))