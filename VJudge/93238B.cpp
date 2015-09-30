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

const int maxn = 1e3+10;
int n,m;
int a[maxn];

int main()
{
    while(~scanf("%d%d", &n,&m))
    {
        for(int i=0; i<m; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a,a+m);
        ll ans =0;
        int l=a[0],r=a[m-1];
        if(l==1||r==n)
        {
            n=n-r+l-1;
            for(int i=1; i<n/2; ++i)
            {
                int flag = (i&1)+((n-i)&1);
                if(flag==1) ans+=i;
                else ans+=i-1;
            }
        }
        else
        {
            int xx,yy;
            xx = min(l-1,n-r);
            yy = max(l-1,n-r);
            if(yy>xx)
            {
                int flag = (xx&1)+(yy&1);
                if(flag==1) ans+=xx;
                else ans+=xx-1;
            }
            else
                ans = 0;
        }
        printf("%I64d\n", ans);
    }
}
