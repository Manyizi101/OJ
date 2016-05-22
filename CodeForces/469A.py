n = int(input())
target = [0] * (n+1)

for i in range(2):
    a = list(map(int, input().split(' ')))
    for j in a[1:]:
        target[j] = 1

if n == sum(target):
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
