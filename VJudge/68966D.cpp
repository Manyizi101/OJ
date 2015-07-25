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

const int MAXN = 15 + 10;

int t, n;

struct  node
{
    string name;
    int d, c;
} course[MAXN];

struct nodedp
{
    int w, sd, next, mj;
} dp[1 << 16];

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        dp[0].next = -1;
        dp[0].w = 0;
        dp[0].sd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> course[i].name >> course[i].c >> course[i].d;
        }
        int m = 1 << (n + 1);
        for (int i = 1; i < m; i++)
        {
            dp[i].w = inf;
            for (int j = n - 1; j >= 0; --j)
            {
                if ((i >> j) & 1)
                {
                    int k = i - (1 << j);
                    int c = dp[k].w;
                    if (course[j].d + dp[k].sd > course[j].c)    c += course[j].d + dp[k].sd - course[j].c;
                    if (dp[i].w > c)
                    {
                        dp[i].w = c;
                        dp[i].next = k;
                        dp[i].mj = j;
                        dp[i].sd = dp[k].sd + course[j].d;
                    }
                }
            }
        }
        int u = 0;
        for (int i = 0; i < n; i++)    u |= (1 << i);
        cout << dp[u].w << endl;
        stack<string> str;
        while (true)
        {
            str.push(course[dp[u].mj].name);
            u = dp[u].next;
            if (u == 0)    break;
        }
        while (!str.empty())
        {
            cout << str.top() << endl;
            str.pop();
        }
    }
    return 0;
}