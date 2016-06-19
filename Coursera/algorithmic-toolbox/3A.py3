total = int(input())
unit = [10,5,1]
ans = 0

for i in unit:
	tmp = total // i
	total -= tmp * i
	ans += tmp

print(ans)


