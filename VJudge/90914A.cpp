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

const int maxn = 1e6+10;

int t,n;
int ans[10010],cnt;

struct node
{
    int num,id;
} a[10010];

bool cmp(node a, node b)
{
    if(a.num==b.num)    return a.id<b.id;
    else return a.num>b.num;
}

int main()
{
    scanf("%d", &t);
    for(int i=1; i<=10000; ++i)   a[i].id=i;
    while(t--)
    {
        for(int i=1; i<=10000; ++i)  a[i].num=0;
        memset(ans,0,sizeof(ans));
        cnt=0;
        scanf("%d", &n);
        int t;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &t);
            int x = 10000-(100-t)*(100-t);
            a[x].num++;
        }
        sort(a+1,a+10001,cmp);
        if(n==1)    printf("Bad Mushroom\n");
        else
        {
            ans[cnt++]=a[1].id;
            for(int i=2; i<=10000; ++i)
            {
                if(a[i].num==a[i-1].num&&a[i].num)
                {
                    ans[cnt++]=a[i].id;
                }
            }
            for(int i=0; i<cnt; ++i)
            {
                printf("%d ",ans[i]);
            }
            cout<<endl;
        }
    }
}
