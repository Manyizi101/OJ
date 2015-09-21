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

ll n,p;

ll mult_mod(ll a,ll b,ll mod) //(a*b)%c a,b,c<2^63
{
    return (a*b-(ll)(a/(long double)mod*b+1e-3)*mod+mod)%mod;
}

ll qPow(ll a, ll b,ll mod)
{
    if(b<0) return 0;
    ll ret = 1;
    a %= mod;
    for(; b; b>>=1,a=(mult_mod(a,a,p))%mod)
        if(b&1)
            ret = (mult_mod(ret,a,p))%mod;
    return ret;
}

int main()
{
    while(~scanf("%I64d%I64d", &n, &p))
    {
        if(n==1)    printf("%I64d\n", 1%p);
        else
        {
            ll ans = qPow(2,n,p)-2;
            printf("%I64d\n", (ans+p)%p);
        }
    }
    return 0;
}
