def solve(fin, height):
    resp = 0
    if fin <= 1:
        return 0

    acum = [0]*len(height)
    for i in range(fin+1):
        acum[i] = height[i]
        if i > 0:
            acum[i] += acum[i-1]

    last = 0
    while last < fin:
        it = last + 1
        while height[it] < height[last]:
            it += 1
        resp += height[last]*(it-1 - last) 
        resp -= acum[it-1] - acum[last]
        last = it

    return resp

def trap(height):
    n = len(height)
    resp = 0
    indxMax = 0
    for i in range(1, n):
        if height[i] > height[indxMax]:
            indxMax = i

    otraN = n - indxMax
    otro = [0]*otraN
    for i in range(indxMax, n):
        otro[otraN + indxMax - 1 - i] = height[i]

    resp += solve(indxMax, height)
    resp += solve(otraN-1, otro)
    return resp

n = int(input())
altura = []
for i in range(n):
  altura.append(int(input()))
print(trap(altura))