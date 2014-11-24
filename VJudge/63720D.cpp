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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 5000+10

ll n;
ll a[MAXN];
ll b[MAXN];
ll dp[MAXN];
ll small,ans,flag;

void init()
{
    memset(dp, 0, sizeof(dp));
    scanf("%I64d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d", &a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
}

int main(int argc, char const *argv[])
{
    init();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[j]+=abs(a[i]-b[j]);
            if(j>1)
            {
                dp[j]=min(dp[j-1],dp[j]);
            }
            for(int x=0;x<n;x++)
            {
                printf("%I64d ",dp[x]);
            }
            printf("\n");
        }
    }
    printf("%I64d\n", dp[n-1]);
    return 0;
}
