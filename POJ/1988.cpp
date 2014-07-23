#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N 30010

int pre[N], son[N], deep[N];

int find(int x)
{
    int temp;
    if (x == pre[x])
        return x;
    temp = pre[x];
    pre[x] = find(temp);
    deep[x] += deep[temp];
    return pre[x];
}

int main(int argc, char const *argv[])
{
    int p;
    char ope;
    int a, b;
    int query;
    int root1, root2;
    scanf("%d", &p);
    for (int i = 1; i < N; ++i)
    {
        pre[i] = i;
        son[i] = 1;
        deep[i] = 0;
    }
    for (int i = 0; i < p; ++i)
    {
        scanf("%*c%c", &ope);
        if (ope == 'M')
        {
            scanf("%d%d", &a, &b);
            root1 = find(a);
            root2 = find(b);
            if (root1 != root2)
            {
                pre[root2] = root1;
                deep[root2] = son[root1];
                son[root1] += son[root2];
            }
        }
        else
        {
            scanf("%d", &query);
            printf("%d\n", son[find(query)] - deep[query] - 1);
        }
    }
    return 0;
}