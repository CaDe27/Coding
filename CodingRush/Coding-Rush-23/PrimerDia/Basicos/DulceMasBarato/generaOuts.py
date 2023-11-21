nombreProblema = "DulceMasBarato"
grupo = "g0"
path = nombreProblema + "/cases/" + grupo + "."

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    precio1 = int(inputFile.readline())
    precio2 = int(inputFile.readline())

    if (precio1 < precio2):
        print(precio1, file=outputFile)
    else:
        print(precio2, file=outputFile)

    inputFile.close()
    outputFile.close()