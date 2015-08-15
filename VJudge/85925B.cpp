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

/*

const int maxn = 100;

int t,n,a[maxn],b[maxn];

bool judge()
{
    for(int i=1; i<=n; ++i)
    {
        if(a[i]!=0) return false;
    }
    return true;
}

void next()
{
    for(int i=1; i<=n; ++i)
    {
        b[i]=abs(a[i]-a[i+1]);
    }
    for(int i=1; i<=n; ++i)
    {
        a[i]=b[i];
    }
    a[n+1]=a[1];
}

bool ans;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans = false;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)   scanf("%d", &a[i]);
        a[0]=a[n];
        a[n+1]=a[1];
        for(int k=1; k<=1000; ++k)
        {
            if(judge())
            {
                ans=true;
                break;
            }
            else
            {
                next();
            }
        }
        if(!ans) printf("LOOP\n");
        else printf("ZERO\n");
    }
}

**/
const int maxn = 100;
int t,n,a[maxn];
int b[maxn],c[maxn]= {0};

void next(int a[])
{
    for(int i=1; i<=n; ++i)
    {
        a[i]=abs(a[i]-a[i+1]);
    }
    a[n+1]=a[1];
}

bool equal(int a[], int b[])
{
    for(int i=1; i<=n; ++i)
    {
        if(a[i]!=b[i])  return false;
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            b[i]=a[i];
        }
        a[n+1]=b[n+1]=a[1];
        bool loop =true;
        for(int i=0; i<1010; ++i)
        {
            next(a);
            next(b);
            next(b);
            if(equal(a,c))
            {
                loop = false;
                break;
            }
            if(equal(a,b))
            {
                loop = true;
                break;
            }
            if(equal(b,c))
            {
                loop = false;
                break;
            }
        }
        if(loop)    printf("LOOP\n");
        else printf("ZERO\n");
    }
}
