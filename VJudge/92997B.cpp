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

const int maxn=1e6+100;

int n,m,x,h[maxn],q[maxn];

int  main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(h,0,sizeof(h));
        memset(q,0,sizeof(q));
        for(int i=0; i<n; ++i) scanf("%d",&h[i]);
        sort(h,h+n);
        for(int i=0; i<m; ++i)
        {
            scanf("%d",&x);
            int big=upper_bound(h,h+n,x)-h;
            int small=lower_bound(h,h+n,x)-h;
            if(q[big])
            {
                puts("0");
                continue;
            }
            q[big]=1;
            printf("%d\n",big-small);
        }
    }
    return 0;
}
