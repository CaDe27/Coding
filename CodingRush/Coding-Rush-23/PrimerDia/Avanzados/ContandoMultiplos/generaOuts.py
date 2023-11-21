nombreProblema = "ContandoMultiplos"
path = nombreProblema + "/cases/g0.case"

cases = 10
for t in range(cases):
    inputFile = open(path+str(t)+".in", "r")
    outputFile = open(path+str(t)+".out", "w")

    a = int(inputFile.readline())
    b = int(inputFile.readline())
    k = int(inputFile.readline())

    li = a + k - (a % k) if a % k != 0 else a  # límite izquierdo
    ld = b - (b % k)  # límite derecho

    cantidad_numeros = (ld - li) // k
    cantidad_k = ((cantidad_numeros * (cantidad_numeros + 1)) // 2) * k
    cantidad_ld = (cantidad_numeros + 1) * li
    suma_numeros = cantidad_ld + cantidad_k

    print(suma_numeros, file= outputFile)

    inputFile.close()
    outputFile.close()