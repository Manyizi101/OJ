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

const int maxn  = 10;
int t,n;

struct node
{
    int rnk,val,id;
} ans[maxn];

bool cmp(node a, node b)
{
    return a.val>b.val;
}

bool cmpid(node a,node b)
{
    return a.id<b.id;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(ans,0,sizeof(ans));
        for(int i=0; i<n; ++i)
        {
            ans[i].id=i;
            int tmp;
            for(int j=0; j<3; ++j)
            {
                scanf("%d", &tmp);
                ans[i].val = max(ans[i].val, tmp);
            }
        }
        sort(ans,ans+n,cmp);
        for(int i=1;i<=n;++i)   ans[i].rnk=i;
        sort(ans,ans+n,cmpid);
        for(int i=0; i<n-1; ++i)
        {
            printf("%d ", ans[i].rnk+1);
        }
        printf("%d\n", ans[n-1].rnk+1);
    }
}
