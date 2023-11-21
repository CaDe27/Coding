nombreProblema = "LaBeca"
grupo = "g0"
path = nombreProblema + "/cases/" + grupo + "."

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    contador = 0
    suma = 0
    
    while  (contador<5):
        C = int(inputFile.readline())
        suma = suma + C
        contador = contador + 1
 

    promedio = suma / contador
    print(promedio, file = outputFile)

    if (promedio >= 9):
        print ("SI", file= outputFile)
    else:
        print ("NO", file= outputFile)
    
    

    inputFile.close()
    outputFile.close()