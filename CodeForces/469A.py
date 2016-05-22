import io
n = int(input())
a = input().split(' ')
b = input().split(' ')

ans = []

for i in range(n+1):
    ans.append(0)

for i in a[1:]:
    ans[int(i)] = 1

for i in b[1:]:
    ans[int(i)] = 1

flag = 0

for i in ans:
    if i == 0:
        flag = 1
        break

if flag:
    print("Oh, my keyboard!")
else:
    print("I become the guy.")
