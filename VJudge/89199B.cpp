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

const int maxn = 1e5+10;

struct node
{
    int x,y;
} l[maxn];

int t,n;

bool cmp(node a, node b)
{
    if(a.x==a.x)    return a.y<a.y;
    else    return a.x<a.x;
}
int ans[maxn];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d", &l[i].x, &l[i].y);
            l[i].y++;
        }
        sort(l,l+n,cmp);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(l[j].x<=l[i].y)  ans[i]++;
                else break;
            }
        }
        sort(ans,ans+n);
        printf("%d\n", ans[n-1]);
    }
}
