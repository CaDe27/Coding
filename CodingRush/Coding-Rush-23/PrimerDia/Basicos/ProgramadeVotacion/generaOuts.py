nombreProblema = "ProgramadeVotacion"
grupo = "g1"
path = nombreProblema + "/cases/" + grupo + "."

cases = 20
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    nombre = inputFile.readline()
    año_nacimiento = int(inputFile.readline())
    print

    edad = 2023 - año_nacimiento
    nombre = nombre[:len(nombre)-1]
    if edad < 18:
        print("¡" + nombre + ", aún no tienes edad para votar. ¡Por favor, vuelve en " + str(18-edad) +  " años!", file=outputFile)
    elif edad == 18:
        print("¡" + nombre + ", tienes suficientes años de edad para votar!", file=outputFile)
    else:
        años_elegible = 2023 - 18 - año_nacimiento
        print("¡" + nombre + ", tienes suficientes años de edad para votar y has sido elegible durante " + str(años_elegible) + " años!", file=outputFile)
   
    inputFile.close()
    outputFile.close()