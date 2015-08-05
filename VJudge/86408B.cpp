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

ll cal(ll n, ll k)
{
    if (k == 1)
    {
        return n;
    }
    ll i = 0; // 循环标志
    int len = 1;
    // n>=2才执行下面的循环
    for (i = 2; i <= n; i++)
    {
        while (n != i)
        {
            if (n % i == 0)
            {
                len++;
                n = n / i;
                if (k == len)  return n;
            }
            else
                break;
        }
    }
    return -1;
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int t;
ll x, y, k;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%I64d%I64d%I64d", &x, &y, &k);
        ll num = gcd(x, y);
        ll ans = cal(num, k);
        // cout << len << endl;
        // for (int i = 0; i < len; i++)  cout << a[i] << " ";
        // cout << endl;
        printf("%I64d\n", ans);
    }
    return 0;
}