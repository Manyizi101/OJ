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

ll gao(int nn)
{
    ll dp[maxn];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=nn;j>=0;--j)
        {
            for(int k=1;k<=a[i]&&k<=j;++k)
            {
                dp[j]=(dp[j]+dp[j-k])%mod;
            }
        }
    }
    return dp[nn];
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ll sum=0;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%I64d", &a[i]);
            sum += a[i];
        }
        printf("%I64d\n", gao(sum/2));
    }
}
