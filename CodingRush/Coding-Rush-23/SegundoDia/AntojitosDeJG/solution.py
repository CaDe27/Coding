n = int(input())

productos =['Muffin', 'Brownie', 'Dona', 'Galleta', 'Pastel']
# Tenemos que definir el tamaño de la lista
cant = [0]*5

# ¿Cuántas iteraciones necesitamos?
for i in range(n):
	# ¿Cómo guardamos las entradas?
	producto = input()
	index = productos.index(producto)
	cant[index] += 1

m = int(input())

# ¿Cuántas iteraciones necesitamos?
for e in range(m):
	# ¿Cómo guradamos las entradas?
	cat = input()
	index2 = productos.index(cat)

	# ¿Cómo verificamos si la clasificación existe en la lista?
	if cant[index2] >= 1:
		print("Bon appetit")
		# Tenemos que quitar la compra
		cant[index2] -= 1
	else:
		print("No disponible")