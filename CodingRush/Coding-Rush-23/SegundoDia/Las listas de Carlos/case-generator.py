import random
import os
import string
from math import *

casos = 7
for i in range(2,casos):
    case_name = f'g0.{i}.in'

    letters = string.ascii_lowercase
    n = random.randint(1,100)
    case_string = str(n) + '\n'
    for j in range(n):
        palabra = random.choice(letters)
        case_string += palabra 
        case_string += '\n'
    case_string += random.choice(letters)[0]

    case_path = os.path.join('LasListasDeCarlos', case_name)
    with open(case_path, 'w') as f:
        f.write(case_string.strip('\n\t\r'))