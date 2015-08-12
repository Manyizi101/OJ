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

const int maxn = 50+10;

int n,m;
int b[maxn];
int len=0;
int ans,Max;
int tmp;

struct node
{
    int x,y;
} cnt[maxn];

inline int cal(node a, node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int main()
{
    while(~scanf("%d%d", &n,&m))
    {
        len=0;
        Max=inf;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                scanf("%d", &tmp);
                if(tmp>0)
                {
                    if(i==1&&j==1)  continue;
                    b[len]=len;
                    cnt[len].x=i;
                    cnt[len].y=j;
                    ++len;
                }
            }
        }
        do
        {
            ans=0;
            ans+=cnt[b[0]].x+cnt[b[0]].y+cnt[b[len-1]].x+cnt[b[len-1]].y;
            for(int i=2; i<len-1; ++i)
            {
                ans+=cal(cnt[b[i]],cnt[b[i-1]]);
                if(ans>Max) break;
            }
            Max=min(ans,Max);
        }
        while(next_permutation(b,b+len));
        printf("%d\n",Max);
    }
}
