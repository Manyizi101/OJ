a,b = input(), input()
print(''.join('01'[i!=j] for i,j in zip(a,b)))
