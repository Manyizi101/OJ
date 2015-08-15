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
        if(b[i]!=0) return true;
    }
    return false;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)   scanf("%d", &a[i]);
        a[0]=a[n];
        a[n+1]=a[0];
        for(int i=1; i<=n; ++i)
        {
            b[i]=(a[i]+a[i+1])&1;
        }
        if(judge()) printf("LOOP\n");
        else printf("ZERO\n");
    }
}

