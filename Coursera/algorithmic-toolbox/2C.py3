a, b = sorted(list(map(int,input().split())))

def gcd(x,y):
	while(y != 0):
		y , x = x%y , y
	return x

print(gcd(a,b))
