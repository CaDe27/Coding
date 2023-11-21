palabras = ['perro', 'gato', 'Libro', 'Casa', 'jardín',
            'Computadora', 'Ciudad', 'amigo', 'Familia', 'escuela',
            'abril', 'Naranja', 'avión', 'mar', 'Verano',
            'invierno', 'trabajo', 'comida', 'bebida', 'cine']

for i in range(len(palabras)):
   texto = palabras[i]
   vocales = ["A", "a", "E", "e", "i", "I", "O", "o", "U", "u"]
   cifrar = ""

   for j in range(len(texto)):
      if texto[j] in vocales:
         cifrar += chr(ord(texto[j]) + (len(texto) // (j + 1)))
      else:
         cifrar += chr(ord(texto[j]) + (len(texto) % (j + 1)))

   with open(str(i) + ".out", "w") as archivo:
        archivo.write(cifrar)
