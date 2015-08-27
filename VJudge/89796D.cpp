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

const int maxn = 2000+10;
const int mod = 1e9+7;

int t,n;
ll a[maxn];

ll qPow(ll a, ll b)
{
    if(b<0) return 0;
    if(b==0)    return 1;
    ll ret = 1;
    a %= mod;
    for(; b; b>>=1,a=(a*a)%mod)
        if(b&1)
            ret = (ret*a)%mod;
    return ret;
}

int main()
{
scanf("%d", &t);
while(t--)
{
    ll Min = inf;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%I64d", &a[i]);
        Min = min(a[i],Min);
    }
    printf("%I64d\n", qPow(Min+1,n-1));
}
}
