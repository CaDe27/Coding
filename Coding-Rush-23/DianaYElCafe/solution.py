L = int(input())
N = int(input())

numeroTaza = 0
cafeinaAcumulada = 0

while cafeinaAcumulada <= L:
  cafeinaTaza = int(input())
  cafeinaAcumulada += cafeinaTaza
  numeroTaza += 1
  
print(numeroTaza)