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

int t,n;
int tmp;

struct node
{
    int x,id;
}a[maxn];

bool cmp(node a, node b)
{
    if(a.x==b.x)    return a.id<b.id;
    return a.x>b.x;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=100;++i) a[i].id=i;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &tmp);
            a[tmp].x++;
        }
        sort(a+1,a+110,cmp);
        printf("%d\n",a[1].id);
    }
}
