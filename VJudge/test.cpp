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

const int N = 100005;
const ll MOD = 1000000007;

int t, n, m, c;
ll a[N];
int op[N], on;
char str[3];

ll pow_mod(ll x, ll k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ans;
}

ll solve(int c)
{
    ll mul = 1;
    for (int i = on - 1; i >= 0; i--)
    {
        if (op[i] == 1)
        {
            if (c > (n + 1) / 2) c = (c - (n + 1) / 2) * 2;
            else c = (c - 1) * 2 + 1;
        }
        else if (op[i] == 2) c = n - c + 1;
        else mul = mul * 2 % (MOD - 1);
    }
    return pow_mod(a[c], mul);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        on = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) a[i] = i;
        while (m--)
        {
            scanf("%s%d", str, &c);
            if (str[0] == 'O') op[on++] = c;
            else
                printf("%lld\n", solve(c));
        }
    }
    return 0;
}