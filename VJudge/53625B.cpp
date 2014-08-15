#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>

using namespace std;
const int Max = 32005;

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
    int x, y, i;
    memset(c, 0, sizeof(c));
    memset(rating, 0, sizeof(rating));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        int tmp = sum(x + 1);
        update(x + 1, 1);
        rating[tmp]++;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n", rating[i]);
    }
    return 0;
}