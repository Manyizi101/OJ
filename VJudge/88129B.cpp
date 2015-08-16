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

const int maxn = 1000+10;
int t,n;
int ans;
ll a[maxn],b[maxn];
bool flag=false;
ll dp[maxn];

int lis(ll a[],int n)
{
    memset(dp, 0, sizeof(int)*n);
    int len = 1;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        int pos = lower_bound(dp, dp + len, a[i]) - dp;
        dp[pos] = a[i];
        len = max(len, pos + 1);
    }
    return len;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        scanf("%d", &n);
        flag=false;
        int len=0;
        for(int i=1; i<=n; ++i)    scanf("%I64d", &a[i]);
        a[0]=0;
        for(int i=1; i<=n; ++i)
        {
            if(a[i]!=a[i-1])
            {
                b[len++]=a[i];
            }
            else
            {
                flag=true;
                continue;
            }
        }
        int ans = lis(b, len);
        /*
        if(flag)    printf("%d\n", ans);
        else if(!flag&&ans>1)    printf("%d\n", ans-1);
        else printf("1\n");
        **/
        if(flag)    printf("%d\n", ans);
        else
        {
            if(ans>1)
                printf("%d\n",ans-1);
            else
                printf("1\n");
        }
    }
}

