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

const int maxn = 10000+10;

int n;
int vis[maxn],ans[maxn],num;
int sum;

int main()
{
    while(~scanf("%d", &n))
    {
        memset(vis,0,sizeof(vis));
        int tmp=0;
        num=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &tmp);
            vis[tmp]++;

        }
        for(int i=0; i<10000; ++i)
        {
            if(vis[i]>n-vis[i])  ans[num++]=i;
        }
        if(num==0)  printf("-1\n");
        else
        {
            printf("%d", ans[0]);
            for(int i=1; i<num; ++i)  printf(" %d", ans[i]);
            printf("\n");
        }
    }
}
