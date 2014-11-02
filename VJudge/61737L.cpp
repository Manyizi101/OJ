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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 30+10

ll dp[MAXN];
int K,A,B;
int t,tcase=0;

ll f(int n,int k)
{
    if(n==0) return k>=1;
    if(dp[n]!=-1&&(1<<n)==k) return dp[n];
    n--;
    if(k<=(1<<n)) return f(n,k)*2;
    dp[n]=f(n,1<<n);
    return dp[n]*2+f(n,k-(1<<n));
}


int main(int argc, char const *argv[])
{
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&K,&A,&B);
        ll ans=f(K,B)-f(K,A-1);
        printf("Case %d: %lld\n",++tcase,ans);
    }
    return 0;
}
