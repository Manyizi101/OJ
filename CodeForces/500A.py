n ,t = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))
b = [a[i]+i+1 for i in range(n-1)]

def dfs(i):
    if i == t:
        return True
    if i > t or i > n - 1 or b[i-1] > n or b[i-1] > t:
        return False
    return dfs(b[i-1])

if dfs(1):
    print("YES")
else:
    print("NO")
