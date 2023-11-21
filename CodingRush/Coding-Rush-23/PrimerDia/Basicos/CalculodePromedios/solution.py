num1 = int(input())
num2 = int(input())
num3 = int(input())
num4 = int(input())

promedio = (num1 + num2 + num3 + num4)/4

if promedio <= 6:
    print("No pasaste, tu promedio es: " + str(promedio))
else:
    print("Pasaste, tu promedio es: " + str(promedio))