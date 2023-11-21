nombreProblema = "CalculodePromedios"
grupo = "g0"
path = nombreProblema + "/cases/" + grupo + "."

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    num1 = int(inputFile.readline())
    num2 = int(inputFile.readline())
    num3 = int(inputFile.readline())
    num4 = int(inputFile.readline())

    promedio = (num1 + num2 + num3 + num4)/4

    if promedio <= 6:
        print("No pasaste, tu promedio es: " + str(promedio), file=outputFile)
    else:
        print("Pasaste, tu promedio es: " + str(promedio), file=outputFile)

    inputFile.close()
    outputFile.close()