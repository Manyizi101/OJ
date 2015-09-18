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

int n;
int p,q;
char x;


long long fac[1000020];

void init(ll p)
{
    fac[0]=1;
    for(int i=1; i<=1000010; i++)
        fac[i]=(fac[i-1]*i)%p;
}

long long quick(long long a, long long n, long long p)
{
    long long tmp=a%p, ret=1;
    while(n)
    {
        if(n&1)
            ret=(ret*tmp)%p;
        tmp=(tmp*tmp)%p;
        n>>=1;
    }
    return ret%p;
}

long long C(long long n, long long m, long long p)
{
    if(m>n) return 0;
    return (fac[n]*quick(fac[m]*fac[n-m], p-2, p))%p;
}

int flag = 0;

int main()
{
    init(mod);
    while(~scanf("%d", &n))
    {
        flag = 0;
        p=q=n/2;
        getchar();
        while((x=getchar())&&x!='\n')
        {
            if(x=='(')  p--;
            if(x==')')  q--;
            if(p>q)
            {
                flag = 1;
            }
        }
        if(flag)    printf("%d\n", 0);
        else
        {
        if(n&1)
        {
            printf("%d\n", 0);
            continue;
        }
        if(p==0)
        {
            printf("%d\n", 1);
            continue;
        }
        if(p<=q)
            printf("%I64d\n", (C(p+q,p,mod)-C(p+q,p-1,mod)+mod)%mod);
        else
            printf("%d\n", 0);
        }
    }
}
