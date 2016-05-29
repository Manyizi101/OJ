s = set(map(int, input().split()))
ans = {
    4: 0,
    3: 1,
    2: 2,
    1: 3
}
print(ans[len(s)])
