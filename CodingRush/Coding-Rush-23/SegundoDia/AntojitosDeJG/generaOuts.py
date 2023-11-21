nombreProblema = "AntojitosDeJG"
grupo = "g0"
path = nombreProblema + "/cases/" + grupo + "."

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    n = int(inputFile.readline())

    productos =['Muffin', 'Brownie', 'Dona', 'Galleta', 'Pastel']
    # Tenemos que definir el tamaño de la lista
    cant = [0]*5

    # ¿Cuántas iteraciones necesitamos?
    for i in range(n):
        # ¿Cómo guardamos las entradas?
        producto = inputFile.readline().strip('\n')
        index = productos.index(producto)
        cant[index] += 1

    m = int(inputFile.readline())

    # ¿Cuántas iteraciones necesitamos?
    for e in range(m):
        # ¿Cómo guradamos las entradas?
        cat = inputFile.readline().strip('\n')
        index2 = productos.index(cat)

        # ¿Cómo verificamos si la clasificación existe en la lista?
        if cant[index2] >= 1:
            print("Bon appetit", file=outputFile)
            # Tenemos que quitar la compra
            cant[index2] -= 1
        else:
            print("No disponible", file=outputFile)

    inputFile.close()
    outputFile.close()