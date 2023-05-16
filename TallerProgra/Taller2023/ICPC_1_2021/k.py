def solve():
    b = "0"+input()
    resp =[]

    suma = 0
    for x in b:
        suma =(suma+int(x))%3
    if int(b[-1]) %2 == 0:
        resp.append('2')
    if suma % 3 == 0:
        resp.append('3')
    if int(b[len(b)-2: len(b)]) %4 == 0:
        resp.append('4')
    if b[-1] == '0' or b[-1]=='5':
        resp.append('5')
    if '2' in resp and '3' in resp:
        resp.append('6')
    if len(resp) > 0:
        print(resp[0], end="")
        for i in range(1, len(resp)):
            print(" "+resp[i], end="")
        print("")
    else:
        print("-1")


t = int(input())
for i in range(t):
    solve()