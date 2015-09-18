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

struct node
{
    int yi,er;
    int cha,id;
} p[maxn];

bool cmp(node a, node b)
{
    if(a.cha==b.cha&&a.er==b.er)    return a.id<b.id;
    else if(a.cha == b.cha) return a.er<b.er;
    else    return a.cha>b.cha;
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i)
        {
            p[i].id = i;
            scanf("%d%d", &p[i].yi,&p[i].er);
            p[i].cha = p[i].yi-p[i].er;
        }
        sort(p,p+n,cmp);
        printf("%d", p[0].id);
        for(int i=1; i<n; ++i)    printf(" %d", p[i].id);
        printf("\n");
    }
}
