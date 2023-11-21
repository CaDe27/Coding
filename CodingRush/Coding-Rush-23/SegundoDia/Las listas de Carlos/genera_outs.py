nombre_problema = 'LasListasDeCarlos'
grupo = 'g0'
path = nombre_problema + '/cases/' + grupo + '.'

cases = 7
for t in range(cases):
    input_file = open(path + str(t) + '.in', 'r')
    output_file = open(path + str(t) + '.out', 'w')

    n = int(input_file.readline())

    palabras = []
    for i in range(n):
        palabra = input_file.readline()
        palabras.append(palabra)

    letra = input_file.readline()

    for palabra in palabras:
        if letra not in palabra:
            print(palabra, file = output_file, end='')

    input_file.close()
    output_file.close()
