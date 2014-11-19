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

#define MAXN 1000+10

struct node
{
    int v,k,c,l;
}s[MAXN];

int n,sum[MAXN],dp[MAXN];

bool cmp(node a, node b)
{
    return a.v<b.v;
}

void init()
{
    memset(sum,0,sizeof(sum));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d", &s[i].v,&s[i].k,&s[i].c,&s[i].l);
    }
    sort(s+1,s+n+1,cmp);
}

int main(int argc, char const *argv[])
{
    while(~scanf("%d", &n)&&n)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            sum[i]+=sum[i-1]+s[i].l;
        }
        dp[1]=s[1].k+s[1].c*s[1].l;
        for(int i=2;i<=n;i++)
        {
            dp[i]=inf;
            for(int j=0;j<i;j++)
            {
                dp[i]=min(dp[i], dp[j]+(sum[i]-sum[j])*s[i].c+s[i].k);
            }
        }
        printf("%d\n", dp[n]);
    }
	return 0;
}
