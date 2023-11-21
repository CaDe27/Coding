n = int(input())
for i in range(n):
    if ''.join(sorted(input())) == ''.join(sorted(input())):
        print("SI")
    else:
        print("NO")