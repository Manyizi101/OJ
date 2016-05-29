n ,t = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))
q = 1

while q<t:
    q = q + a[q-1]

if q == t:
    print("YES")
else:
    print("NO")
