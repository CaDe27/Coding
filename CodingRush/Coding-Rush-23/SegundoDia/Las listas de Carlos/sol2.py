n = int(input())
palabras = []
for i in range(n):
    palabras.append(input())
prohibida = input()

for palabra in palabras:
    tiene = False
    for letra in palabra:
        if letra == prohibida:
            tiene = True
    if not tiene:
        print(palabra)