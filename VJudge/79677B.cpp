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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int MAXN = 10000 + 10;
int n, k, a[MAXN];

int judge(double m)
{
    double x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= m) x += a[i] - m;
        else y += m - a[i];
    }
    if (x * (1 - k / 100.0) - y < -eps) return -1;
    else if (x * (1 - k / 100.0) - y > eps)    return 1;
    else return 0;
}

double cal()
{
    double l = a[0], r = a[n-1];
    double m = (l + r) / 2.0;
    while (l - r < -eps)
    {
        if (judge(m) == -1)
        {
            r = m + eps;
            m = (l + r) / 2.0;
        }
        else if (judge(m) == 1)
        {
            l = m - eps;
            m = (l + r) / 2.0;
        }
        else
        {
            return m;
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        printf("%.7f\n", cal());
    }
    return 0;
}