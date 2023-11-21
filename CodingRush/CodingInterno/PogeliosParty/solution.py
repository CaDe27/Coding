[n, k] = [int(x) for x in input().split(' ')]
arre = [int(x) for x in input().split(' ')]
slices = sum(arre)

while( slices % (k+1) != 0):
    k-=1
print(k)