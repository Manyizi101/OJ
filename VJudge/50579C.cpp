#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

int n, a[21];
bool vis[21];

bool dfs(int nowlen, int Len, int x, int num)
{
    if (num == n) return true;
    int temp = 0;
    for (int i = x; i < n; i++)
    {
        if (vis[i] || a[i] == temp) continue;
        vis[i] = true;
        if (nowlen + a[i] < Len)
        {
            if (dfs(nowlen + a[i], Len, i + 1, num + 1)) return true;
            else temp = a[i];
        }
        if (nowlen + a[i] == Len)
        {
            if (dfs(0, Len, 0, num + 1)) return true;
            else temp = a[i];
        }
        vis[i] = false;
        if (nowlen == 0) break;
    }
    return false;
}

int main()
{
    int t, sum;
    scanf("%d", &t);
    while (t--)
    {
        sum = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n, cmp);
        if (sum % 4 == 0)
        {
            if (dfs(0, sum / 4, 0, 0))
                printf("yes\n");
            else printf("no\n");
        }
        else printf("no\n");
    }
    return 0;
}