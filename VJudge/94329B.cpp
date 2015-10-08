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

typedef long long int LL;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
using namespace std;

LL PowMod(LL a,LL b,LL MOD)
{
    LL ret=1;
    while(b) {
        if(b&1) ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}

LL fac[100005];
LL GetFact(LL p)
{
    fac[0]=1;
    for(LL i=1; i<=100000; i++) {
        fac[i]=fac[i-1]*i%p;
    }
}

LL Lucas(LL n,LL m,LL p)
{
    if(n<m) return 0;
    LL ret=1;
    while(n&&m) {
        LL a=n%p,b=m%p;
        if(a<b) return 0;
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p;
        n/=p;
        m/=p;
    }
    return ret;
}

int main()
{
    int x1,x2,y1,y2,p;
    while(scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&p)!=EOF) {
        GetFact(p);
        LL ans=0;
        for(int i=y1+1; i<=y2+1; i++) {
            ans=(ans+Lucas(x2+1,i,p)-Lucas(x1,i,p)+p)%p;
        }
        cout<<ans<<endl;
    }
    return 0;
}
