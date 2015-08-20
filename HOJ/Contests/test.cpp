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
const int maxn  =  1e6+10;
ll t,n;
ll fac[maxn];

ll quickpow(ll a, ll b)
{
    if(b<0) return 0;
    ll ret = 1;
    a %= mod;
    for(; b; b>>=1,a=(a*a)%mod)
        if(b&1)
            ret = (ret*a)%mod;
    return ret;
}

ll inv(ll a)
{
    return quickpow(a,mod-2);
}

ll init()
{
    fac[1]=1;
    for(ll i=2; i<=maxn; ++i)
    {
        fac[i]=(fac[i-1]*(i*(inv(__gcd(fac[i-1],i))%mod))%mod)%mod;
    }
}



int main()
{
    init();
    scanf("%I64d", &t);
    while(t--)
    {
        scanf("%I64d", &n);
        printf("%I64d\n", fac[n+1]*inv(n+1)%mod);
    }
}
