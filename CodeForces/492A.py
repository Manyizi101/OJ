i, n = 1, int(input())

while n>=0:
    n-=i*(i+1)/2
    i+=1

print(i-2)
