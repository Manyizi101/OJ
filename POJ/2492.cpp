#include<cstdio>

const int maxn = 2000 + 10;

int p[maxn];
int r[maxn];

int find(int x)
{
    if (x == p[x]) return x;

    int t = p[x];
    p[x] = find(p[x]);
    r[x] = (r[x] + r[t]) % 2;
    return p[x];
}

void Union(int x, int y)
{
    int fx = find(x);
    int fy = find(y);

    p[fx] = fy;
    r[fx] = (r[x] + 1 + r[y]) % 2;
}

void set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        set(n);

        int x, y;
        bool flag = true;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            if (find(x) == find(y))
            {
                if (r[x] == r[y])
                {
                    flag = false;
                    continue;
                }
            }
            else Union(x, y);
        }
        printf("Scenario #%d:\n", i);
        if (flag) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}