#include <stdio.h>
#define N 1000

int father[N], rank[N];

void makeset(int x)
{
    father[x] = x;
    rank[x] = 0;
}

int find(int x)
{
    if (x != father[x])    father[x] = find(father[x]);
    return father[x];
}

int Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)    return 0;
    if (rank[x] > rank[y]) father[y] = x;
    else
    {
        if (rank[x] == rank[y])    rank[y]++;
        father[x] = y;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int k = 1;
    int a, b;
    int flag = 0;
    register int i;
    for (i = 0; i < N; i++)    makeset(i);
    while (scanf("%d%d", &a, &b) != EOF && a >= 0 && b >= 0)
    {
        if (!a && !b)
        {
            int cnt = 0;
            for (i = 0; i < N; i++)
                if (father[i] == i && rank[i])
                    cnt++;
            if (cnt > 1)   flag = 1;
            if (!flag)
                printf("Case %d is a tree.\n", k++);
            else
                printf("Case %d is not a tree.\n", k++);
            for (i = 0; i < N; i++)    makeset(i);
            flag = 0;
            continue;
        }
        if (!flag && !Union(a, b))    flag = 1;
    }
    return 0;
}