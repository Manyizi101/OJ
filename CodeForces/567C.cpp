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

const int maxn = 2 * 1e5 + 10;

int n, k;
ll a[maxn];
ll ans;

map<ll, ll> l, r;

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        l.clear();
        r.clear();
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%I64d", &a[i]);
        }
        for (int i = 3; i <= n; ++i)
        {
            r[a[i]]++;
        }
        for (int i = 2; i <= n - 1; ++i)
        {
            l[a[i - 1]]++;
            if (a[i] % k != 0)
            {
                if (r[a[i + 1]] != 0)
                    r[a[i + 1]]--;
                continue;
            }
            ll tj = a[i] / k, tx = a[i] * k;
            ans += l[tj] * r[tx];
            if (r[a[i + 1]] != 0)
                r[a[i + 1]]--;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}