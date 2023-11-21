import random
import os
import itertools as it
from math import *


baseString = """{N} {K}
{entrada}
""".strip(' \t\n\r')

cases = 20
for i in range(3, cases):
    caseName = '{}.in'.format(i)
    N = random.randint(1, 100000)
    K = random.randint(1, 100)

    entrada = [str(random.randint(1, 100)) for _ in range(N)]
    case = {
        "N": N,
        "K": K,
        "entrada": ' '.join(entrada)
    }

    caseString = baseString.format(**case)
    casePath = os.path.join('pogeliosParty/cases', caseName)
    with open(casePath, 'w') as f:
        f.write(caseString)
