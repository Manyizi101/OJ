n, W = list(map(int, input().split()))
item = []
ans = 0.0

for i in range(n):
	v, w = list(map(int, input().split()))
	item.append(
		{
			'v': v,
			'w': w,
			'worth': v/w
		}
	)

for i in range(n):
	for j in range(i,n):
		if(item[i]['worth']<item[j]['worth']):
			item[i], item[j] = item[j], item[i]

for i in item:
	if(W>=i['w']):
		ans += i['v']
		W -= i['w']
	else:
		ans += (W/i['w'])*i['v']
		W = 0
		break

print(ans)
