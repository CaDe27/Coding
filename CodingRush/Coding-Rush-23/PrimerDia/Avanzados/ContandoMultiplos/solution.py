a = int(input())
b = int(input())
k = int(input())

li = a + k - (a % k) if a % k != 0 else a #límite izquierdo
ld = b - (b % k)  # límite derecho
cantidad_numeros = (ld - li) // k
cantidad_k = ( (cantidad_numeros * (cantidad_numeros + 1)) // 2) * k
cantidad_ld = (cantidad_numeros + 1) * li
suma_numeros = int(cantidad_ld + cantidad_k)
print(suma_numeros)

