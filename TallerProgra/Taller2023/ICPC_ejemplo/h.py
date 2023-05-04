def maxArea(k):
    if k%2 == 1:
        resp = (k+1)//2 * (k-1)//2 
    else:
        resp = (k//2) * (k//2)
    return resp

n = int(input())
nM = n//2
resp = 0
for i in range(1, nM+1):
    resp = max(resp, maxArea(i))
print(resp)