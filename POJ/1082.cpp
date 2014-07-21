#include <iostream>
#include <cstdio>
using namespace std;
const int Max = 50005;

int n, pa[Max], rank[Max];

void make_set()
{
    for (int x = 1; x <= n; x ++)
    {
        pa[x] = x;
        rank[x] = 0;
    }
}

int find_set(int x)
{
    int tmp = pa[x];
    if (x != pa[x])
    {
        pa[x] = find_set(pa[x]);
        rank[x] = (rank[x] + rank[tmp]) % 3;
    }
    return pa[x];
}

void union_set(int x, int y, int w)
{
    int a = find_set(x);
    int b = find_set(y);
    pa[b] = a;
    rank[b] = (rank[x] - rank[y] + w + 3) % 3;
}

int main()
{
    int t, ans = 0;
    scanf("%d %d", &n, &t);
    make_set();
    while (t --)
    {
        int d, x, y;
        scanf("%d %d %d", &d, &x, &y);
        if (x > n || y > n) ans ++;
        else
        {
            if (d == 1)
            {
                if (find_set(x) == find_set(y) && rank[x] != rank[y]) ans ++;
                else union_set(x, y, 0);
            }
            if (d == 2)
            {
                if (find_set(x) == find_set(y) && (rank[x] + 1) % 3 != rank[y]) ans ++;
                else union_set(x, y, 1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}