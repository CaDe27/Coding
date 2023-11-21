nombreProblema = "CadaSegundoCuenta"
grupo = "g0"
path = nombreProblema + "/cases/" + grupo + "."

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    A = int(inputFile.readline())
    M = int(inputFile.readline())
    D = int(inputFile.readline())
    H =int(inputFile.readline())
    Mi =int(inputFile.readline())
    S = int(inputFile.readline())

    A = int(inputFile.readline())
    M = int(inputFile.readline())
    D = int(inputFile.readline())
    H =int(inputFile.readline())
    Mi =int(inputFile.readline())
    S -= int(inputFile.readline())
    
    if S%2 == 0:
        print("Si!", file=outputFile)
    else:
        print("nel", file= outputFile)

    inputFile.close()
    outputFile.close()