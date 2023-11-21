palabras = ['perro', 'gato', 'Libro', 'Casa', 'jardín',
            'Computadora', 'Ciudad', 'amigo', 'Familia', 'escuela',
            'abril', 'Naranja', 'avión', 'mar', 'Verano',
            'invierno', 'trabajo', 'comida', 'bebida', 'cine']

for i in range(len(palabras)):
    palabra = palabras[i]

    with open(str(i) + ".in", "w") as archivo:
        archivo.write(palabra)
