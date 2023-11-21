a = int(input())
b = int(input())
k = int(input())

resp = 0
if k > b:
    resp = 0
else:
    if a%k != 0:
        a = ((a//k) * k) + k
    if b%k != 0:
        b = (b//k) * k
    if a <= b:
        b = b//k
        a = a//k
        resp = (b*(b+1))//2 -((a*(a+1))//2) + a 
        resp *= k
print(resp) 