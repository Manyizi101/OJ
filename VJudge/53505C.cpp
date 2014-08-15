#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct edge
{
    int s;
    int t;
    int len;
} e[1000];

int n, m;
int father[100];

bool cmp(edge a1, edge a2)
{
    return a1.len < a2.len;
}

void init()
{
    for (int i = 0; i < 100; i++)
        father[i] = i;
}

int fin(int x)
{
    if (x == father[x])
        return x;
    fin(father[x]);
}

void krus()
{
    int ans = 0;
    int k = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int a_root = fin(e[i].s);
        int b_root = fin(e[i].t);
        if (a_root == b_root)
            continue;
        if (a_root != b_root);
        {
            k++;
            ans += e[i].len;
            if (a_root < b_root)
                father[b_root] = a_root;
        }
        if (k == m - 1)
            break;
    }
    if (k < m - 1)
        printf("?\n");
    else
        printf("%d\n", ans);
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &m);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &e[i].s, &e[i].t, &e[i].len);
        init();
        sort(e, e + n, cmp);
        krus();
    }
    return 0;
}