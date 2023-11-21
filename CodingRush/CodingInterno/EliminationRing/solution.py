n = int(input())
conjunto = set(int(x) for x in input().split(' '))
if len(conjunto) == 2:
    print(n//2 + 1)
else:
    print(n)