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
ll a[maxn], b[maxn];
int na, nb;
ll ans;

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        ans = 0;
        na = nb = 0;
        ll tmp;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%I64d", &tmp);
            if (tmp > 0)
            {
                a[++na] = tmp;
            }
            else if (tmp < 0)
            {
                b[++nb] = tmp;
            }
        }
        for (int i = 2; i <= na - 1; ++i)
        {
            int ansa = 0, ansb = 0;
            if (a[i] % k != 0)   continue;
            ll tj = a[i] / k, tx = a[i] * k;
            for (int j = 1; j < i; ++j)
                if (a[j] == tj) ansa++;
            for (int x = i + 1; x <= na; ++x)
                if (a[x] == tx) ansb++;
            ans += ansa * ansb;
        }
        for (int i = 2; i <= nb - 1; ++i)
        {
            int ansa = 0, ansb = 0;
            if (b[i] % k != 0)   continue;
            ll tj = b[i] / k, tx = b[i] * k;
            for (int j = 1; j < i; ++j)
                if (b[j] == tj) ansa++;
            for (int x = i + 1; x <= nb; ++x)
                if (b[x] == tx) ansb++;
            ans += ansa * ansb;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}