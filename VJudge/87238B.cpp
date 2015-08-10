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

const int maxn = 1e5+10;
const int mod = 1e9+7;

int t,n,m,p;
ll a[maxn];
vector<int> op;
char q;
int mul;

ll exp_mod(ll a, ll n, ll b)
{
    ll t;
    if(n==0) return 1%b;
    if(n==1) return a%b;
    t=exp_mod(a,n/2,b);
    t=t*t%b;
    if((n&1)==1) t=t*a%b;
    return t;
}

int fun1(int p)
{
    if(n&1)
    {
        if(p<=(n+1)/2)  p=2*p-1;
        else p=2*p-n-1;
    }
    else
    {
        if(p<=n/2)  p=2*p-1;
        else p=2*p-n;
    }
    return p;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        op.clear();
        mul=0;
        scanf("%d%d", &n,&m);
        for(ll i=1; i<=n; ++i)   a[i]=i;
        while(m--)
        {
            getchar();
            scanf("%c%d",&q,&p);
            if(q=='O')
            {
                if(p==3)    mul++;
                else
                    op.push_back(p);
            }
            else if(q=='Q')
            {
                for(int i=0; i<=op.size()-1; ++i)
                {
                    if(op[i]==1)
                    {
                        p=fun1(p);
                    }
                    else if(op[i]==2)
                    {
                        p=n-p+1;
                    }
                }
                a[p]=exp_mod(a[p],1<<mul,mod);
                printf("%I64d\n",a[p]%mod);
            }
        }
    }
}





























































