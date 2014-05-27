
#include<cstdio>

const int maxn = 50000+10;

int p[maxn];
int r[maxn];

void set(int n)
{
    for(int x = 1; x <= n; x++)
    {
        p[x] = x;
        r[x] = 0;
    }
}

int find(int x)
{
    if(x == p[x]) return x;

    int t = p[x];
    p[x] = find(p[x]);
    r[x] = (r[x]+r[t])%3;
    return p[x];
}

void Union(int x, int y, int d)
{
    int fx = find(x);
    int fy = find(y);

    p[fy] = fx;
    r[fy] = (r[x]-r[y]+3+(d-1))%3;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    set(n);

    int ans = 0;
    int d, x, y;
    while(m--)
    {
        scanf("%d%d%d", &d, &x, &y);

        if(x > n || y > n || (d == 2 && x == y)) ans++;

        else if(find(x) == find(y))
        {
            if(d == 1 && r[x] != r[y]) ans++;
            if(d == 2 && (r[x]+1)%3 != r[y]) ans++;
        }
        else Union(x, y, d);
    }
    printf("%d\n", ans);
    return 0;
}
