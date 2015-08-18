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

map<pair<int, int>,int> mp;
const int maxn = 1e5+10;

int visit[maxn],dist[maxn];

int prim(int cur, int n)
{
    int index;
    int sum = 0;
    memset(visit, false, sizeof(visit));
    visit[cur] = true;
    for(int i = 1; i <= n; i ++)
    {
        //dist[i] = graph[cur][i];
        if(mp[make_pair(cur,i)]>1)
            dist[i] = mp[make_pair(cur,i)];
        else
            dist[i]=1;
    }

    for(int i = 2; i <= n; i ++)
    {

        int mincost = inf;
        for(int j = 1; j <= n; j ++)
        {
            if(!visit[j] && dist[j] < mincost)
            {
                mincost = dist[j];
                index = j;
            }
        }

        visit[index] = true;
        sum += mincost;

        for(int j = 1; j <= n; j ++)
        {
            /*
            if(!visit[j] && dist[j] > graph[index][j])
            {
                dist[j] = graph[index][j];
            }
            **/
            if(!visit[j]&&dist[j]>(mp[make_pair(index,j)]>1?mp[make_pair(index,j)]:1))
            {
                dist[j] = (mp[make_pair(index,j)]>1?mp[make_pair(index,j)]:1);
            }
        }
    }
    return sum;
}

int n;

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(__gcd(i,j)>1)
                {
                    mp[make_pair(i,j)]=__gcd(i,j);
                }
            }
        }
        printf("%d\n", prim(1,n));
    }
}

