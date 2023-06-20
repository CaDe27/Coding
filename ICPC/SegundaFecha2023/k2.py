[n, k] = [int(x) for x in input().split(' ')]
mat = []
for i in range(n):
    mat.append(input())

cont = 0
for i in range(n-k+1):
    for j in range(n-k+1):
        if mat[i][2*j] == mat[i][2*(j+k-1)] == mat[i+k-1][2*j] == mat[i+k-1][2*(j+k-1)]:
            cont += 1
print(cont)
