k = int(input())
maximo = 50000
minimo = 0
li = 10000000000
ld = 0

while maximo-minimo>1:
    mid = (maximo+minimo) // 2
    posicion = (mid*(mid+1))/2
    if posicion >= k:
        ld = posicion
        maximo = mid
    elif posicion < k:
        li = posicion
        minimo = mid
print(maximo)

