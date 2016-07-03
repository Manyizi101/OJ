n, *a = list(map(int, input().split()))
k, *b = list(map(int, input().split()))

def binary_search(x):
	l=0
	r=n-1
	m=(l+r)//2
	if(a[0]==x):
		return 0
	if(a[n-1]==x):
		return n-1
	while(l<r):
		if(a[m]==x):
			return m
		elif(a[m]<x):
			l=m+1
			m=(l+r)//2
		else:
			r=m
			m=(l+r)//2
	return -1

for i in b:
	print(binary_search(i), end=' ')
