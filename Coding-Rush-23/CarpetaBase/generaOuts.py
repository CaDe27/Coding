nombreProblema = ""
grupo = "g0"
path = nombreProblema + "/cases/" + grupo + "."

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")


    inputFile.close()
    outputFile.close()