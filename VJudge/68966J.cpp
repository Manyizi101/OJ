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

const int N = 1000 + 10;

int n;
int tw, ts;
int dp[N];
stack<int>ans;

struct node
{
    int w, s, r;
} mice[N];

int cmp(node a, node b)
{
    if (a.w == b.w)    return a.s > b.s;
    else return a.w < b.w;
}

int main()
{
    n = 1;
    while (~scanf("%d%d", &mice[n].w, &mice[n].s))
    {
        mice[n].r = n;
        n++;
    }
    n--;
    sort(mice + 1, mice + n + 1 , cmp);
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < i; j++)
        {
            if (mice[i].w > mice[j].w && mice[i].s < mice[j].s)    t = max(t, dp[j]);
            dp[i] = t + 1;
        }
    }
    int ind = max_element(dp, dp + n) - dp;
    ans.push(mice[ind].r);
    int t = ind;
    for (int i = ind - 1; i >= 0; i--)
    {
        if (mice[i].w < mice[t].w && mice[i].s > mice[t].s && dp[t] == dp[i] + 1)
        {
            ans.push(mice[i].r);
            t = i;
        }
    }
    printf("%d\n", dp[ind]);
    while (!ans.empty())
    {
        printf("%d\n", ans.top());
        ans.pop();
    }
    return 0;
}