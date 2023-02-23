grupos = [[] for i in range(3)]
print(grupos)
grupos[0].append(10)
grupos[1].append(1000)
grupos[1].append(1000)
#grupos[2].append(1000)
print(grupos)
print( max([len(grupos[i]) for i in range(3)]) )