[k, p] = [int(x) for x in input().split(' ')]
prod = [int(x) for x in input().split(' ')]

maxk = 50000 + 100 + 1
generados = [False]*maxk

for i in range(p):
    generados[ prod[i] ] = True

for z in range(maxk):
    for i in range(p):
        if z >= prod[i] and generados[z-prod[i]]: 
            generados[z] = True

for i in range(k):
    n = int(input())
    residuo = 0
    while not generados[n+residuo]:
        residuo += 1
    print(residuo)
