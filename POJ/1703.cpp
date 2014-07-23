#include<cstdio>

const int maxn = 100000 + 10;

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
    for (int x = 1; x <= n; x++)
    {
        p[x] = x;
        r[x] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int T;
    int n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%*c", &n, &m);
        set(n);

        char c;
        int x, y;
        while (m--)
        {
            scanf("%c%d%d%*c", &c, &x, &y);
            if (c == 'A')
            {
                if (find(x) == find(y))
                {
                    if (r[x] != r[y]) printf("In different gangs.\n");
                    else printf("In the same gang.\n");
                }
                else printf("Not sure yet.\n");
            }
            else if (c == 'D')
            {
                Union(x, y);
            }
        }
    }
    return 0;
}
