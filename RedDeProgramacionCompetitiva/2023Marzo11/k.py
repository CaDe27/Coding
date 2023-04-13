n = int(input())
cal = dict()
posible = False
sum_min = 1
for i in range(n):
    linea = input().split(" ")
    if linea[0] not in cal.keys():
        cal[linea[0]] = dict()
    cal[linea[0]][linea[1]] = int(linea[2])

for calt in cal.keys():
    tipos = cal[calt].keys()
    if "any" in tipos and cal[calt]["any"] > 1:
        posible = True
        break
    if "left" in tipos and "right" in tipos:
        posible = True
        break

if posible:
    for calt in cal.keys():
        tipos = cal[calt].keys()
        l,r=0,0
        lef = "left" in tipos
        rig = "right" in tipos
        if lef:
            l = cal[calt]["left"]
        if rig:
            r = cal[calt]["right"]
        if lef or rig:
            sum_min += max(l,r)
        else:
            sum_min+=1
    print(sum_min)
else:
    print("impossible")