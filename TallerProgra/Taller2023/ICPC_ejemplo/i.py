n = input()

cont = 0
for c in n:
    if int(c)!=0 and int(n) % int(c) == 0:
        cont += 1
print(cont)
