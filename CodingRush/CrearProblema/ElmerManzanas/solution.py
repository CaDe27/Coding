n = int(input())
L = int(input())

peso_acumulado = 0
contador = 0
for i in range(n):
  peso_manzana = int(input())
  if peso_acumulado + peso_manzana <= L:
    peso_acumulado += peso_manzana
    contador += 1
print(contador)