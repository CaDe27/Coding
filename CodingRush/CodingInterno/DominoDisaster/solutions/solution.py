n = int(input())
s = input()
resp = ""
for i in range(n):
    if s[i] == 'D':
        resp += 'U'
    elif s[i] == 'U':
        resp += 'D'
    else:
        resp += s[i]
print(resp)

    
