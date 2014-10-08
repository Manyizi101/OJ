/*
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


typedef long long int ll;

ll l, r;
ll ans;
ll remain, k, m, n2, n3, r2, r3;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll zuhe(ll M, ll N)
{
    ll m = M - N ;
    ll ans = 1;
    for (ll i = M; i >= m + 1; i--)
    {
        ll tmp = gcd(i, M - i + 1);
        ans /= (M - i + 1) / tmp;
        ans *= i / tmp;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("twothree.in", "r", stdin);
    //freopen("twothree.out", "w", stdout);
    while (scanf("%lld%lld", &l, &r) != EOF)
    {
        if (l == 1)    printf("%d\n", 1 % r);
        else
        {
            ans = 0;
            if (l % 2 == 0)
            {
                k = l / 2;
                n2 = k;
                n3 = 0;
            }
            else
            {
                k = (l - 3) / 2;
                n2 = k;
                n3 = 1;
            }
            m = k / 3;
            for (ll i = 0; i < m + 1; i++)
            {
                r2 = n2 - i * 3;
                r3 = n3 + i * 2;
                ans += zuhe(r2+r3,r3);
            }
            printf("%lld\n", ans % r);
        }
    }
    return 0;
}
**/

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

const double c = 0.389324199524937508840138455;

int l, r, ans;

int main(int argc, char const *argv[])
{
    freopen("twothree.in", "r", stdin);
    freopen("twothree.out", "w", stdout);
    while (scanf("%d%d", &l, &r) != EOF)
    {
        if (l == 1)    printf("%d", 1 % r);
        else
        {
            ans = ceil(c * pow((4.0 / 3), l) - 0.5);
            printf("%d\n", ans % r);
        }
    }
    return 0;
}