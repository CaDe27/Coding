k = int(input())
s = input()
for c in s:
    if c in ['0', '6', '8']:
        k -= 1
print(k)