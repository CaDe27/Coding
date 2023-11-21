with open('data.in', 'r') as f:
    digitos = int(f.readline())

respConcursante = input()
numConcursante = int(respConcursante)
if len(respConcursante) == digitos and numConcursante%3 != 0 and numConcursante%5 != 0:
    score = 1
else:
    score = 0
print(score)