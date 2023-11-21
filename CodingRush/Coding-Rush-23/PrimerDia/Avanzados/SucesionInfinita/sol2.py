k = int(input())

ini = 1
fin = 50000

while ini != fin:
    mid = (ini+fin)//2
    if mid*(mid+1)//2 >= k:
        fin = mid
    else:
        ini = mid + 1
print(ini)