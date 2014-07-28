#include <cstdio>

int f[50005], sum;

int find(int x)
{
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void make(int a, int b)
{
    int f1 = find(a);
    int f2 = find(b);
    if (f1 != f2)
    {
        f[f2] = f1;
        sum--;
    }
}

int main(int argc, char const *argv[])
{
    int n, m, p = 1, i;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)  break;
        for (i = 1; i <= n; i++)    f[i] = i;
        sum = n;
        for (i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            make(a, b);
        }
        printf("Case %d: %d\n", p++, sum );
    }
    return 0;
}