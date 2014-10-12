#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
using namespace std;

//#define LOCAL

long long int m, n, i, j, k, sum;
long long int a[100];
int ans;

void init()
{
    a[0] = 1;
    a[1] = 2;
    a[2] = 5;
    a[3] = 25;
    a[4] = 125;
    k = 5;
    sum = 1;
    for (i = 1; i <= 10; i++)
    {
        a[k++] = sum * 10; sum *= 10;
    }
    sum = 10;
    for (i = 1; i <= 10; i++)
    {
        a[k++] = sum * 2; sum *= 10;
    }
    sum = 5;
    for (i = 1; i <= 10; i++)
    {
        a[k++] = sum * 10; sum *= 10;
    }
    sum = 10;
    for (i = 1; i <= 10; i++)
    {
        a[k++] = sum * 25; sum *= 10;
    }
    sum = 10;
    for (i = 1; i <= 8; i++)
    {
        a[k++] = sum * 125; sum *= 10;
    }
    sort(a, a + k);
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("59115I.in", "r", stdin);
    freopen("59115I.out", "w", stdout);
#endif
    init();
    while (~scanf("%lld%lld", &m, &n))
    {
        ans = 0;
        for (i = 0; i < k; i++)
        {
            if (a[i] >= m && a[i] <= n) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}