

tasa = {1:955, 3:863}
n = 4
#todo lo que se pueda a tres meses al inicio

def estrategia1(monto):
    y = [0] * n
    y[0] = monto
    for i in range(0, n-1):
        if i + 3 <= n-1:
            y[i+3] += (y[i]//tasa[3])*1000
            y[i] -= (y[i]//tasa[3])*tasa[3]
        
        y[i+1] += (y[i]//tasa[1])*1000
        y[i] -= (y[i]//tasa[1])*tasa[1]

        y[i+1] += y[i]
        y[i] = 0
    return y[n-1]

def estrategia2(monto):
    y = [0] * n
    y[0] = monto
    y[1] += (y[0]//tasa[1])*1000
    y[0] -= (y[0]//tasa[1])*tasa[1]
    y[1] += y[0]

    for i in range(1, n-1):
        if i + 3 <= n-1:
            y[i+3] += (y[i]//tasa[3])*1000
            y[i] -= (y[i]//tasa[3])*tasa[3]
        
        y[i+1] += (y[i]//tasa[1])*1000
        y[i] -= (y[i]//tasa[1])*tasa[1]

        y[i+1] += y[i]
        y[i] = 0
    return y[n-1]

def bin(L1, estrategia):
    ini = 0
    fin = L1
    while ini != fin:
        mitad = (ini + fin) // 2
        if estrategia(mitad) >= L1:
            fin = mitad
        else:
            ini = mitad + 1
    return ini

last1 = -1
last2 = -1
i = 863
for i in range(1000, 1100):
    a = bin(i, estrategia1)
    b = bin(i, estrategia2)
    last2 = last1
    if a < b:
        print("est1", i, a, b)
    elif  b < a:
        print("est2", i, a, b)
    else:
        print("same", i, a, b)
#print(t1, tasa[3], i, bin(i, estrategia1), bin(i, estrategia2))
