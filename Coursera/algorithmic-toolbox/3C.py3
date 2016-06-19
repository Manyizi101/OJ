n = int(input())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())),reverse = True)
ans = 0

for i,j in zip(a,b):
	ans += i*j

print(ans)
