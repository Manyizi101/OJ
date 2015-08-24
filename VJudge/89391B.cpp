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

const ll mod =  1000000007;
const int maxn = 10000000+10;


int n;
double ans=0;
double g[maxn];

ll qPow(ll a, ll b)
{
    if(b<0) return 0;
    ll ret = 1;
    a %= mod;
    for(; b; b>>=1,a=(a*a)%mod)
        if(b&1)
            ret = (ret*a)%mod;
    return ret%mod;
}

void init()
{
    for(int i=2; i<=maxn; ++i)
        g[i]+=g[i-1]+log10(i);

}

int main()
{
    memset(g,0,sizeof(g));
    g[1]=0;
    init();
    while(~scanf("%d", &n))
    {
        ans=0;
        for(int i=1; i<=n; ++i)
        {
            ans+=g[i];
        }
        ll p = (ll)ans;
        double e = ans-p;
        printf("%I64d\n", (ll)(qPow(10,p)*pow(10,e)));
    }
}
