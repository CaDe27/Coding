import numpy as np
#maxN = 1000000

def mnss(index):
    if index >= n:
        return 0
    if not visited[index]:
        dp[index] = max(array[index] + mnss(index+2), mnss(index+1))
    return dp[index]

def getResp():
    resp = []
    i = 0
    while i < n:
        # lo uso 
        #ultimo del arreglo 
        if dp[i] == array[i] + (dp[i+2] if i+2 < n else 0):
            resp.append(i)
            i = i+2
        # no lo uso
        else:
            i = i+1
    return resp
        

n = int(input())
array = [int(num) for num in input().split(' ')]
visited = np.full([n], False)
dp = np.full([n], 0)
print(mnss(0))
print(getResp())

