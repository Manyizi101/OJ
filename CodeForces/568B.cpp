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

int n;
int vis[maxn];

struct node
{
    int id,val;
    bool is;
} a[maxn];

bool cmpval(node a, node b)
{
    if(a.val==b.val)    return a.id<b.id;
    else return a.val<b.val;
}

bool cmpid(node a, node b)
{
    return a.id<b.id;
}

int main()
{
    while(~scanf("%d", &n))
    {
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i].val);
            a[i].id=i;
            a[i].is=0;
            if(a[i].val<=n&&vis[a[i].val]==0)
            {
                a[i].is=1;
                vis[a[i].val]=1;
            }
        }
        queue<int> ans;
        for(int i=1; i<=n; ++i)
        {
            if(vis[i]==0)   ans.push(i);
        }
        for(int i=1; i<=n; ++i)
        {
            if(a[i].is==0)
            {
                int tmp=ans.front();
                ans.pop();
                a[i].val=tmp;
                a[i].is=1;
            }
        }
        for(int i=1; i<n; ++i)
        {
            printf("%d ", a[i].val);
        }
        printf("%d\n",a[n].val);
    }
}





























































