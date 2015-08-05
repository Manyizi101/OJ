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


ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

const int maxn = 10006;
int t;
ll x, y, k, m;
ll num[maxn];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        m = 0;
        scanf("%I64d%I64d%I64d", &x, &y, &k);
        ll n = gcd(x, y);
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                num[m++] = i;
                if (i * i != n)  num[m++] = n / i;
            }
        }
        if (m < k) printf("-1\n");
        else
        {
            sort(num, num + m);
            printf("%I64d\n", num[m - k]);
        }
    }
    return 0;
}