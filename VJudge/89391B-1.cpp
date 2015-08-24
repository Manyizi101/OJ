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
const int maxn =  110000+10;

struct node
{
    int id;
    ll n,ans;
} a[maxn];

bool cmpn(node a, node b)
{
    return a.n<b.n;
}

bool cmpid(node a, node b)
{
    return a.id<b.id;
}

int main()
{
    int cnt=0;
    int Max=0;
    while(~scanf("%I64d", &a[cnt].n))
    {
        a[cnt].id=cnt;
        a[cnt].ans=0;
        cnt++;
    }
    ll ans=1;
    ll x = 1;
    int j=0;
    sort(a,a+cnt,cmpn);
    Max = a[cnt-1].n;
    for(int i=1; i<=Max; ++i)
    {
        x=x*i%mod;
        ans=(ans%mod)*(x%mod);
        for(; j<cnt; ++j)
        {
            if(a[j].n==i)   a[j].ans = ans%mod;
            else break;
        }
    }
    sort(a,a+cnt,cmpid);
    for(int i=0; i<cnt; ++i)
    {
        printf("%I64d\n", a[i].ans%mod);
    }
}
