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

const int maxn = 2*1e5+10;

int t,n,x,y;
map<int, int> mp;
int xx[maxn];

struct node
{
    int id,val;
}ans[maxn];

bool cmp(node a, node b)
{
    if(a.val==b.val)    return a.id<b.id;
    return a.val>b.val;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        mp.clear();
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &x,&y);
            mp[x]++;
            mp[y]++;
            if(x==y)    mp[x]--;
        }
        int cnt=0;
        for(auto it = mp.begin();it!=mp.end();++it)
        {
            ans[cnt].val = it->second;
            ans[cnt].id = cnt;
            cnt++;
        }
        sort(ans,ans+cnt,cmp);
        printf("%d\n",ans[0].val);
    }
}
