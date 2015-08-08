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

const int maxn = 20 + 5;

int t, m, n, k;
int a[maxn][maxn], vis[maxn][maxn];
itn dir[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};

bool judge(int x, int y)
{
    if (1 <= x && x <= n && 1 <= y && y <= m && vis[y][x] == 0)    return true;
    else return false;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d", &m, &n, &k);
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
    }
    return 0;
}