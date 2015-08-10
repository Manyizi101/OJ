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
int a[maxn];
vector<int> op;
char q;

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

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        op.clear();
        scanf("%d%d", &n,&m);
        for(int i=1; i<=n; ++i)   a[i]=i;
        while(m--)
        {
            getchar();
            scanf("%c%d",&q,&p);
            if(q=='O')  op.push_back(p);
            else if(q=='Q')
            {
                for(unsigned i=0; i<op.size(); ++i)
                {
                    if(op[i]==1)
                    {
                        if(n&1)
                        {
                            if(p<=(n+1)/2)  a[p]=a[2*p-1];
                            else a[p]=a[2*i-n-1];
                        }
                        else
                        {
                            if(p<=n/2)  a[p]=a[2*p-1];
                            else a[p]=a[2*i-n];
                        }
                    }
                    else if(op[i]==2)
                    {
                        a[p]=a[n-p];
                    }
                    else
                    {
                        a[p]=exp_mod(a[p],2,mod);
                    }
                }
                printf("%d\n",a[p]%mod);
            }
        }
    }
}





























































