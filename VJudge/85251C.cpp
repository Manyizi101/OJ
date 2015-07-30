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

const ll mod = 1000000007;

int n, k;
const int NP = 1000005;

int ispri[NP] = {}, prime[NP], pcnt = 0;

void getprime()
{
    ispri[0] = ispri[1] = 1;
    for (long long i = 2; i < NP; i++)
        if (ispri[i] == 0)
        {
            prime[++pcnt] = i;
            for (long long j = i * i; j < NP; j += i)
                ispri[j] = 1;
        }
}

ll cal(int n)
{
    int num = n;
    ll ans = 0;
    for (int i = 1; prime[i]*prime[i] <= n; i++)
        if (n % prime[i] == 0)
        {
            n /= prime[i];
            while (n % prime[i] == 0) n /= prime[i];
            ans++;
            if (n == 1) break;
        }
    if (n > 1) ans++;
    return ans;
}

ll qPow(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}

int main()
{
    getprime();
    while (~scanf("%d%d", &n, &k))
    {
        if (k == 2 || n == 1)    cout << 1 << endl;
        else if (k > 2 && n != 1)   cout << 0 << endl;
        else
        {
            ll ans = 0;
            ll x = cal(n);
            ans = qPow(2, x, mod);
            printf("%I64d\n", ans % mod);
        }
    }
    return 0;
}