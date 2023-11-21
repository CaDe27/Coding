nombreProblema = "SucesionInfinita"
grupo = "g0"
path = nombreProblema + "/cases/case"

cases = 25
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    k = int(inputFile.readline())
    maximo = 50000
    minimo = 0
    li = 10000000000
    ld = 0

    while maximo - minimo > 1:
        mid = (maximo + minimo) // 2
        posicion = (mid * (mid + 1)) / 2
        if posicion >= k:
            ld = posicion
            maximo = mid
        elif posicion < k:
            li = posicion
            minimo = mid

    print(maximo, file= outputFile)

    inputFile.close()
    outputFile.close()