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

#define MAXN 500+10

int m,k;
ll arr[MAXN],sum,Min, ans;
bool vis[MAXN];

int divide(ll M)
{
    memset(vis,0,sizeof(vis));
    int cnt=0;
    int pos=m-1;
    while(pos>=0)
    {
        ll sum=0;
        bool ok=true;
        while(pos>=0&&sum+arr[pos]<=M)
        {
            ok=false;
            sum+=arr[pos];
            --pos;
        }
        if(ok)
        {
            return k+1;
        }
        if(pos>=0)  vis[pos]=true;
        ++cnt;
        for(int i=0;i<m;i++)
        {
            cout<<vis[i]<<' ';
        }
        cout<<endl;
    }
    return cnt;
}

ll binary()
{
    ll l=Min,r=sum,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(divide(mid)<=k)
            r=mid;
        else
            l=mid+1;
    }
    return r;
}

void init()
{
    scanf("%d%d", &m,&k);
    sum=0,Min=0;
    for(int i=0; i<m; ++i)
    {
        scanf("%lld", &arr[i]);
        sum+=arr[i];
        if(arr[i]>Min)  Min=arr[i];
    }
}

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        init();
        ans=binary();
        int cnt=divide(ans);
        for(int i=0; i<m-1&&cnt<k; ++i)
        {
            if(!vis[i])
            {
                vis[i]=true;
                ++cnt;
            }
        }
        for(int i=0; i<m; ++i)
        {
            if(i)   printf(" %lld", arr[i]);
            else printf("%lld", arr[i]);
            if(vis[i])
            {
                printf(" /");
            }
        }
        printf("\n");
    }
    return 0;
}
