#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXN 1005

int n, m, y, remain;

struct  node
{
    int x, flag;
    int ans;
    int k;
} no[MAXN];

bool cmp(node a , node b)
{
    return a.flag < b.flag;
}

bool cmp2(node a , node b)
{
    return a.k >= b.k;
}
int i;



int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &y);
    remain = m;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &no[i].x);
        no[i].ans = no[i].x * (int)(m / y);
        no[i].k = fabs(no[i].x * 1.0 / y - (no[i].ans+1) * 1.0 / m)-fabs(no[i].x * 1.0 / y - no[i].ans * 1.0 / m);
        remain -= no[i].ans;
        no[i].flag = i;
    }
    sort(no, no + n, cmp2);
    i = 0;
    while (remain)
    {
        no[i].ans++;
        i++;
        remain--;
        if (i >= n)    i -= n;
    }
    sort(no, no + n, cmp);
    for (i = 0; i < n; i++)    printf("%d ", no[i].ans);
    printf("\n");
    return 0;
}