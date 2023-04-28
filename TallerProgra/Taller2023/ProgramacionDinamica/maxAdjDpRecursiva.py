import numpy as np
maxN = 1000000

def mnss(index):
    if index >= n:
        return 0
    if not visited[index]:
        dp[index] = max(array[index] + mnss(index+2), mnss(index+1))
    return dp[index]

def getResp():
    it = 0
    indexesResp = []
    while it < n:
        #lo tomo
        if dp[it] == array[it] + (dp[it+2] if it + 2 < n else 0):
            indexesResp.append(it)
            it = it+2
        else:
            it = it+1
    return indexesResp

n = int(input())
array = [int(num) for num in input().split(' ')]
visited = np.full([n], False)
dp = np.full([n], 0)
print(mnss(0))
print(getResp())
