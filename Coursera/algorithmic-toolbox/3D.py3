n = int(input())
a ,b = [], []
ans = []

for i in range(n):
	ta, tb = list(map(int, input().split()))
	a.append(ta)
	b.append(tb)

for i in range(n):
	for j in range(i,n):
		if(a[i]>a[j]):
			a[i], a[j] = a[j], a[i]
			b[i], b[j] = b[j], b[i]
		elif(a[i]==a[j]):
			if(b[i]>b[j]):
				b[i], b[j] = b[j], b[i]

l, r = a[0], b[0]
ans.append(a[0])

for i in range(1,n):
	if(a[i]<=r):
		l = a[i]
		r = min(b[i],b[i-1])
		ans[len(ans)-1]=l
	else:
		ans.append(a[i])
		l = a[i]
		r = b[i]

print(len(ans))

for i in ans:
	print(i, end=' ')
