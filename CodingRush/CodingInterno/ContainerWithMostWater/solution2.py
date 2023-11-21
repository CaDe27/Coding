n = int(input())
arre = input().split(' ')
for i in range(n):
    arre[i] = [int(arre[i]), i]
    
indxMin = 100001
indxMax = -1
resp = 0
for x in sorted(arre, reverse=True):
    indxMin = min(indxMin, x[1])
    indxMax = max(indxMax, x[1])
    resp = max(resp, x[0]*(x[1] - indxMin))
    resp = max(resp, x[0]*(indxMax - x[1]))
print(resp) 