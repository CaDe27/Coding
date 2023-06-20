fibo = [0]*10
suma = [0]*10
pot = [0]*10
fibo[0] = 1
fibo[1] = 1
for i in range(2, 10):
    fibo[i] = fibo[i-1] + fibo[i-2]
for i in range(10):
    pot[i] = fibo[i]**3
    if i > 0:
        suma[i] = pot[i] + suma[i-1]
    else:
        suma[i] = pot[i]
print(fibo)
print(pot)
print(suma)
fff = [pot[i] + pot[i+1] for i in range(10-1)]
print(fff)
