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
    int x,m;
} l[2*maxn];

int t,n,ans,tmp;

bool cmp(node a, node b)
{
    if(a.x==b.x)    return a.m<b.m;
    else    return a.x<b.x;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d", &l[i*2].x, &l[i*2+1].x);
            l[i*2+1].x++;
            l[i*2].m=1;
            l[i*2+1].m=-1;
        }
        sort(l,l+n*2,cmp);
        ans=tmp=0;
        for(int i=0; i<2*n; ++i)
        {
            tmp+=l[i].m;
            ans=max(tmp,ans);
        }
        printf("%d\n", ans);
    }
}
