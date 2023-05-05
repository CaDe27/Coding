[n, m] = [int(x) for x in input().split(' ')]

limit = 1
powers = [1]*3985
while (powers[limit]//limit) < m:
    limit +=1
    powers[limit] = limit ** n

found = False
for q in range(2, limit+1):
    for p in range(1, q):
        if (m % ((powers[q] - powers[q-p])//p) ) == 0:
            print(p, q)
            found = True
        
        if found:
            break
    if found:
        break

if not found:
    print("impossible")