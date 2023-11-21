# Pedir al usuario su nombre y año de nacimiento

nombre = input()
año_nacimiento = int(input())

# Calcular la edad y el número de años que ha sido elegible para votar
edad = 2023 - año_nacimiento
if edad < 18:
    print("¡" + nombre + ", aún no tienes edad para votar. ¡Por favor, vuelve en " + str(18-edad) +  " años!")
elif edad == 18:
    print("¡" + nombre + ", tienes suficientes años de edad para votar!")
else:
    años_elegible = 2023 - 18 - año_nacimiento
    print("¡" + nombre + ", tienes suficientes años de edad para votar y has sido elegible durante " + str(años_elegible) + " años!")
