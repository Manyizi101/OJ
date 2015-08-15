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

