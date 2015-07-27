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

const int N = 17;
int t, n;

struct node
{
    string s;
    int d, c;
} course[N];

struct nodedp
{
    int w, sd, next, mj;
} dp[1 << N];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        dp[0].w = 0;
        dp[0].next = -1;
        dp[0].sd = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            cin >> course[i].s;
            scanf("%d%d", &course[i].d, &course[i].c);
        }
        for (int i = 1; i < (1 << (n + 1)); i++)
        {
            dp[i].w = inf;
            for (int j = n - 1; j >= 0; j--)
            {
                if ((i >> j) & 1)
                {
                    int k = i - (1 << j);
                    int c = dp[k].w;
                    if (course[j].c + dp[k].sd > course[j].d)
                        c += course[j].c + dp[k].sd - course[j].d;
                    if (dp[i].w > c)
                    {
                        dp[i].w = c;
                        dp[i].next = k;
                        dp[i].mj = j;
                        dp[i].sd = dp[k].sd + course[j].c;
                    }
                }
            }
        }
        int u = (1 << n) - 1;
        printf("%d\n", dp[u].w);
        stack<string> str;
        while (u)
        {
            str.push(course[dp[u].mj].s);
            u = dp[u].next;
        }
        while (!str.empty())
        {
            cout << str.top() << endl;
            str.pop();
        }
    }
    return 0;
}