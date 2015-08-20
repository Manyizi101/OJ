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

const int fcnt = 1e6+10;
const ll M = 1000000007;
ll fac[fcnt];

void getfac()
{
    fac[0]=1;
    for(int i=1; i<fcnt; ++i)
    {
        fac[i]=fac[i-1]*i%M;
    }
}

ll quickpow(ll a, ll b)
{
    if(b<0)     return 0;
    ll ret =1;
    a %= M;
    for(; b; b>>=1,a=(a*a)%M)
    {
        if(b&1)
        {
            ret = (ret*a)%M;
        }
    }
    return ret;
}

ll inv(ll a)
{
    return quickpow(a, M-2);
}

ll C(ll n, ll m)
{
    return fac[n]*inv(fac[m])%M*inv(fac[n-m])%M;
}

int t,n;
ll ans;

int main()
{
    getfac();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n==1)
            printf("%d\n", 1);
        else
            printf("%I64d\n",C(n,n/2)*C(n,n/2-1)/__gcd(C(n,n/2),C(n,n/2-1))%M);
    }
}
