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

const int maxn = 100 + 10;

int n, m;
int a[maxn][maxn];
int ans[maxn];

struct node
{
    int id, val;
} x[maxn];

bool cmp(node  a, node  b)
{
    if (a.val == b.val)    return a.id < b.id;
    return a.val > b.val;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(x, 0, sizeof(x));
        for (int j = 1; j <= n; ++j)
        {
            x[j].id = j;
        }
        for (int i = 1; i <= m; ++i)
        {
            int Max = -1;
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &a[i][j]);
                if (Max < a[i][j])
                {
                    Max = a[i][j];
                    ans[i] = j;
                }
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            x[ans[i]].val++;
        }
        sort(x + 1, x + n + 1, cmp);
        printf("%d\n", x[1].id);
    }
    return 0;
}