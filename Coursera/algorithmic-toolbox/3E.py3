from math import floor,sqrt

n = int(input())
k = floor(sqrt(2*n+0.25)-0.5)

if(n==k*(k+1)/2):
	print(k)
	for i in range(1,k+1):
		print(i, end=' ')
else:
	print(k)
	for i in range(1, k):
		print(i, end=' ')
	print(n-(k-1)*k//2)
