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

const int maxn = 1000+10;

int t,n;
int a[maxn];
ll x,y;

bool judge()
{
    for(int i=0; i<n; ++i)
    {
        if(a[i]!=a[n-i-1])  return true;
    }
    return false;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        x=y=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &a[i]);
            if(i&1) x+=a[i];
            else y+=a[i];
        }
        if(x==y&&judge())   puts("Yes");
        else puts("No");
    }
}
