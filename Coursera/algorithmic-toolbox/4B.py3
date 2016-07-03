n = int(input())
a = sorted(list(map(int, input().split())))

def judge():
	if(a.count(a[n//2])>n//2):
		return 1
	else:
		return 0

print(judge())
