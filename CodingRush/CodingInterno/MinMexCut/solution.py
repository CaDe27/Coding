def puedeSerCero(s):
    #tiene que no haber ceros
    hayCero = False
    i = 0
    while i < len(s) and not hayCero:
        if s[i] == '0':
            hayCero = True
        i += 1
    
    return not hayCero

def puedeSerUno(s):
    #tendriamos que poder dividir al string en substrings
    # de los cuales haya a lo mas uno con respuesta 1 
    # y todos los demas con respuesta 0
    
    #esto se reduce en que los ceros esten todos juntitos
    bloquesDeCeros = 0
    if s[0] == '0':
        bloquesDeCeros += 1
    
    for i in range(1, len(s)):
        if s[i] == '0' and s[i-1] == '1':
            bloquesDeCeros += 1

    return bloquesDeCeros <= 1

s = input()

if puedeSerCero(s):
    print(0)
elif puedeSerUno(s):
    print(1)
else: 
    print(2)