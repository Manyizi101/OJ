#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>

using namespace std;
const int Max = 100010;

int c[Max], n, rating[Max];

int lowbit(int x)
{
    return x & (-x);
}

void  update(int i,  int x)
{
    while (i <= Max)
    {
        c[i] = c[i] + x;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int  ans = 0;
    while (i > 0)
    {
        ans += c[i];
        i -= lowbit(i);
    }

    return ans;
}

int main()
{
    int a, b, i, j;
    while (scanf("%d", &n) && n)
    {
        memset(c, 0, sizeof(c));
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            update(a, 1);
            update(b+1, -1);
        }
        printf("%d", sum(1));
        for (i = 2; i <= n; i++)
        {
            printf(" %d", sum(i));
        }
        printf("\n");
    }
    return 0;
}