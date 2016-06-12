a = [0,1,1]
x = int(input())

for i in range(3,x+1):
	a.append((a[i-2]+a[i-1])%10)

print(a[x])
