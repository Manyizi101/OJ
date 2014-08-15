#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>

using namespace std;
const int Max = 100010;

int c[Max], rating[Max];

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
    int a, b, i, j, m, k, t, n, flag=0;
    scanf("%d", &t);
    while (t--)
    {
        flag++;
        memset(c, 0, sizeof(c));
        memset(rating, 0, sizeof(rating));
        scanf("%d%d%d", &n, &m, &k);
        for (i = 0; i < k; i++)
        {
            scanf("%d%d", &a, &b);
            update(a, 1);
            update(b + 1, -1);
        }
    }
    return 0;
}