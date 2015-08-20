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
const int maxn  =  1e6+10;
ll t,n;
ll fac[maxn];
int ispri[maxn] = {}, prime[maxn],pcnt = 0;

void getprime()
{
    ispri[0]=ispri[1]=1;
    for(ll i =2; i<maxn; ++i)
    {
        if(ispri[i]==0)
        {
            prime[++pcnt]=i;
            for(ll j=i*i; j<maxn; j+=i)
            {
                ispri[j]=1;
            }
        }
    }
}

ll quickpow(ll a, ll b)
{
    if(b<0) return 0;
    ll ret = 1;
    a %= mod;
    for(; b; b>>=1,a=(a*a)%mod)
        if(b&1)
            ret = (ret*a)%mod;
    return ret;
}

ll inv(ll a)
{
    return quickpow(a,mod-2);
}

int a[maxn];
int b[maxn];

void init()
{
    int num;
    for(ll rk=3; rk<maxn; rk++)
    {
        memset(b,0,sizeof(b));
        fac[rk]=fac[rk-1];
        num=rk;
        const int x = sqrt(rk);
        for(int i=1; prime[i]<=x; ++i)
        {
            if(num%prime[i]==0)
            {
                b[prime[i]]++;
                num/=prime[i];
                if(a[prime[i]]<b[prime[i]])
                {
                    fac[rk]=fac[rk]*prime[i]%mod;
                    a[prime[i]]=b[prime[i]];
                }
                i--;
            }
        }
        if(num!=1)
        {
            fac[rk]*=num;
            b[num]++;
            if(a[num]<b[num])
            {
                fac[rk]=fac[rk]*num%mod;
                a[num]=b[num];
            }
        }
    }
}

int main()
{
    fac[1]=1;
    fac[2]=2;
    a[1]=1;
    a[2]=1;
    getprime();
    int ans=0;
    for(int i=1;i<=maxn;++i)
    {
        if(ispri[i])    ans++;
    }
    cout<<ans<<endl;
    //init();
    scanf("%I64d", &t);
    while(t--)
    {
        scanf("%I64d", &n);
        //printf("%I64d\n", fac[n+1]*inv(n+1)%mod);
        printf("%I64d\n", fac[n+1]/(n+1));
    }
}
