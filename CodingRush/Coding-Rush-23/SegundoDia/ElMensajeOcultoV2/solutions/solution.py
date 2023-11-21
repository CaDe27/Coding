texto = input()

vocales = ["A", "a", "E", "e", "i", "I", "O", "o", "U", "u"]

cifrar = ""

for i in range(len(texto)):
   if texto[i] in vocales:
      cifrar += chr(ord(texto[i]) + (len(texto) // (i + 1)))
   else:
      cifrar += chr(ord(texto[i]) + (len(texto) % (i + 1)))

print(cifrar)