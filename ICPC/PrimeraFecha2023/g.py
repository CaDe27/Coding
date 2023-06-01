n = int(input())
turno = 1
numeroASumar = 2
suma = 1

#indice
while suma < n:
    turno += 1
    suma += numeroASumar

    if suma < n:
        turno += 1
        suma += numeroASumar
        numeroASumar += 1
        

if turno %2 == 0:
    print("John")
else:
    print("Jane")