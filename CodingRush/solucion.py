#leemos n
n = int(input())

#leemos m
m = int(input())

#usamos un arreglo para guardar las piezas que ya tenemos 
#¿dónde vamos a guardar que ya tenemos una pieza?
cubeta = [0]*(n+1)

#checamos el numero de las piezas que tenemos y marcamos que sí la tenemos
for i in range(m):
    pieza = int(input())
    cubeta[pieza] = 1

#hacemos un recorrido para ver si tenemos todas las piezas
piezasDiferentes = 0
for i in range(1, n+1):
    #si si esta, ...
    if cubeta[i] == 1:
        piezasDiferentes = piezasDiferentes + 1

#si no tenemos todas las piezas
if piezasDiferentes < n:
    print("chale")
#si las tenemos todas
else:
    print("WUU")
  