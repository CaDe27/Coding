n=int(input())

for i in range(n):
  cadena1=input()
  cadena2=input()
  cubeta=[0]*10
  for elem in cadena1:
    cubeta[int(elem)]+=1
  for elem in cadena2:
    cubeta[int(elem)]-=1
  
  indice=0
  while indice < 10:
    if cubeta[indice]!=0:
      print('NO')
      break
    indice+=1
    
  if indice==10:
    print('SI')