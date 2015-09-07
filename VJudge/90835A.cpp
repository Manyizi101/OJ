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

const int maxn = 1000+10;

int t,n,vis[maxn];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(vis,0,sizeof(vis));
        int tmp;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &tmp);
            vis[tmp]=1;
        }
        int i;
        for(i=1; i<=n+2; ++i)
        {
            if(!vis[i])
            {
                printf("%d ",i);
                break;
            }
        }
        ++i;
        for(;i<=n+2;++i)
        {
            if(!vis[i])
            {
                printf("%d", i);
                break;
            }
        }
        printf("\n");
    }
}
