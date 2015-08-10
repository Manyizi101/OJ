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

const int maxn = 100+10;

int n;
ll a[maxn],b[maxn];
ll c[maxn],d[maxn];
int lena,lenb;

bool judge()
{
    if(lena!=lenb)  return false;
    else
    {
        for(int i=0; i<lena; ++i)
        {
            if(c[i]!=d[i])  return false;
        }
    }
    return true;
}

int main()
{
    while(~scanf("%d", &n))
    {
        lena=0,lenb=0;
        for(int i=0; i<n; ++i)    scanf("%I64d", &a[i]);
        for(int i=0; i<n; ++i)    scanf("%I64d", &b[i]);
        sort(a,a+n);
        sort(b,b+n);
        c[lena++]=a[0];
        d[lenb++]=b[0];
        for(int i=1; i<n; ++i)
        {
            if(a[i]!=a[i-1])    c[lena++]=a[i];
        }
        for(int i=1; i<n; ++i)
        {
            if(b[i]!=b[i-1])    d[lenb++]=b[i];
        }
        if(judge()) printf("YES\n");
        else printf("NO\n");
    }

}
