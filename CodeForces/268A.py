n = int(input())
a = [0] * n
b = [0] * n
ans = 0

for i in range(n):
    a[i], b[i] = list(map(int, input().split(' ')))

for i in a:
    ans += b.count(i)

print(ans)
