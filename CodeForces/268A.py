n = int(input())
a = []
b = []
ans = 0

for i in range(n):
    x = list(map(int, input().split(' ')))
    a.append(x[0])
    b.append(x[1])

for i in a:
    for j in b:
        if i == j:
            ans += 1

print(ans)
