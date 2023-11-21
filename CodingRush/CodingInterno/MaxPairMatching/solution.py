n = int(input())
resp = 0
n = 2*n
proms = [0]*n
for i in range(n):
    [a,b] = [int(x) for x in input().split(' ')]
    if a > b:
        c = b
        b = a
        a = c
    resp += b-a
    proms[i] = a+b

n = n//2
proms = sorted(proms)
for i in range(n):
    resp += proms[2*n-1-i] - proms[i]
resp >>=1
print(resp)