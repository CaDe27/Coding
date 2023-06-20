import numpy as np
import functools
MOD = 1000000007
n = 1
k = 1
maxN = 13
arre = np.empty(maxN, np.int32)
fact = np.empty(maxN, np.int64)
invFacto = np.empty(maxN, np.int64)
bucket = {}

def binPow(base, power):
    resp = 1
    multi = base
    while power > 0:
        if power & 1:
            resp = (resp*multi)%MOD
        power >>= 1
        multi = (multi*multi)%MOD
    return resp

def precalcula():
    fact[0] = 1
    fact[1] = 1
    for i in range(2, maxN):
        fact[i] = (fact[i-1] * i)%MOD
    global invFacto
    invFacto = np.fromiter(map(lambda x: binPow(x, MOD-2), fact), dtype=np.int32)
   
 
n, k = map(int, input().split(' '))
arre = np.fromiter(map(int, input().split(' ')), np.int32)
precalcula()
for x in arre:
    if bucket.get(x) == None:
        bucket[x] = 1
    else:
        bucket[x] += 1
resp = functools.reduce(lambda a, b: (a*fact[b])%MOD, bucket.values()) 
resp = (resp*invFacto[n])%MOD

print(resp)
for _ in range(k):
    a,b = map(int, input().split(' '))
    a-=1
    
    resp = (resp*invFacto[bucket[arre[a]]])%MOD
    bucket[arre[a]] -= 1
    resp = (resp*fact[bucket[arre[a]]])%MOD

    arre[a] = b
    if bucket.get(b) == None:
        bucket[b] = 1
    else:
        bucket[b] += 1
    resp = (resp*bucket[b])%MOD
    print(resp)