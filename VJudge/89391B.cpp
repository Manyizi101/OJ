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
const int maxn = 10000000+10;


int n;
ll fac[maxn];
ll ans[maxn];


void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<maxn;++i)
    {
        fac[i]=i*fac[i-1]%mod;
    }
}

ll dp(int n)
{
    if(ans[n]>0)  return ans[n];
    if(n==1)    return ans[1]=1;
    else if(n==2)   return ans[2]=2;
    else return ans[n]=(fac[n])%mod*(dp(n-1)%mod)%mod;
}

int main()
{
    memset(ans,0,sizeof(ans));
    ans[1]=1;
    ans[2]=2;
    init();
    while(~scanf("%d", &n))
    {
        cout<<dp(n)<<endl;
    }
}
