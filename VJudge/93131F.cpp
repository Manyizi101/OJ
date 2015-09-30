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

const int maxn = 100000 +10;

int V,E;
int u[maxn],v[maxn],w[maxn],r[maxn],f[maxn];
int F[30];


int find(int i)
{
    if(i != f[i])
    {
        f[i] = find(f[i]);
    }
    return f[i];
}

bool cmp1(const int & i, const int & j)
{
    return w[i] < w[j];
}

bool cmp2(const int & i, const int & j)
{
    return w[j] < w[i];
}

void init()
{
    for(int i = 1; i <= V; i++)
    {
        f[i] = i;
    }
    for(int i = 1; i <= E; i++)
    {
        r[i] = i;
    }
}

int Kruskal(int flag)
{
    init();
    if(flag==1) sort(r + 1, r + E + 1, cmp1);
    else sort(r + 1, r + E + 1, cmp2);
    int answer = 0;
    int cnt = 0;
    for(int i = 1; i <= E; i++)
    {
        int e = r[i];
        int rx = find(u[e]);
        int ry = find(v[e]);
        if(rx != ry)
        {
            f[rx] = ry;
            cnt++;
            answer+= w[e];
        }
    }
    if(cnt == V - 1)
    {
        return answer;
    }
    else
    {
        return 4;
    }
}

int main()
{
    F[1] = 1,F[2] = 2;
    for(int i = 3; i <= 30; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    int T;
    scanf("%d",&T);
    for(int cs = 1; cs <= T; cs++)
    {
        int flag = 0;
        scanf("%d %d", &V, &E);
        for(int i = 1; i <= E; i++)
        {
            scanf("%d %d %d", &u[i], &v[i], &w[i]);
        }
        int small = Kruskal(1);
        int big = Kruskal(2);
        for(int i = 1; F[i] <= big; i++)
        {
            if(small <= F[i] && F[i] <= big)
            {
                flag = 1;
                break;
            }
        }
        if(flag)    printf("Case #%d: Yes\n", cs);
       else printf("Case #%d: No\n", cs);
    }
    return 0;
}
