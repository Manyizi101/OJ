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
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int maxn = 50 + 10;

int t, n;
double a[maxn];

bool check(double x)
{
    double t = a[0];
    for (int i = 1; i < n - 1; ++i)
    {
        if (t == a[i]) continue;
        else if (t <= (a[i] - x))  t = a[i];
        else if ((a[i] + x) <= a[i + 1]) t = a[i] + x;
        else return false;
    }
    return  true;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)    scanf("%lf", &a[i]);
        sort(a, a + n);
        double ans = 0;
        for (int i = 1; i < n ; ++i)
        {
            if (check(a[i] - a[i - 1]))  ans = max(ans, a[i] - a[i - 1]);
            else if (check((a[i] - a[i - 1]) / 2.0))   ans = max(ans, ((a[i] - a[i - 1]) / 2.0));
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}