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

const int mod = 11;
ll t, l, r, ans1, ans2;


bool cal(ll x)
{
    ll odd = 0, even = 0;
    bool flag = false;
    while (x > 0)
    {
        if (flag)
        {
            odd += (x % 10);
            flag = !flag;
        }
        else
        {
            even += (x % 10);
            flag = !flag;
        }
        x /= 10;
    }
    //cout << even + odd << endl;
    if (even - odd == 3) return true;
    else return false;
}

ll solve(ll l, ll r)
{
    ll ans = 0;
    for (ll i = l; i <= r; i++)   if (cal(i))  ans++;
    return ans;
}

ll judge(ll l, ll r)
{
    for (ll i = l; i <= r; i++)
    {
        ans1 = solve(l, i);
        ans2 = (i + 8) / 11 - (l - 1 + 8) / 11;
        if (ans1 != ans2)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    //freopen("84490E.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%I64d%I64d", &l, &r);
        cout << judge(l, r) << endl;
    }
    return 0;
}