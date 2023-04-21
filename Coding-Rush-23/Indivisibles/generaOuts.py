nombreProblema = "Indivisibles"
path = nombreProblema + "/cases/"

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    digitos = int(inputFile.readline())
    num = 15 * (10**(digitos-2)) + 1
    print(num, file= outputFile)

    inputFile.close()
    outputFile.close()