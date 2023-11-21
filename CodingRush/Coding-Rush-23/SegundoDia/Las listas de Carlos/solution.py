n = int(input())

palabras = []
for i in range(n):
    palabra = input()
    palabras.append(palabra)

letra = input()

for palabra in palabras:
    if letra not in palabra:
        print(palabra)