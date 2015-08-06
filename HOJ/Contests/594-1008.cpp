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

const int maxn = 1e5 + 10;

int t, n, num;
int ans[maxn];
int vis[maxn];

struct node
{
    int l, r, id;
} a[maxn];

bool cmp(node a, node b)
{
    if (a.l == b.l)        return  a.r < b.r;
    else return a.l < b.l;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        num = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i].l);
            a[i].id = i + 1;
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i].r);
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; ++i)
        {
            if (a[i].l <= num && a[i].r >= num)
            {
                ans[num++] = a[i].id;
                vis[a[i].id] = 1;
                break;
            }
        }
        printf("%d\n", num);
        if (num)
            printf("%d", ans[0]);
        for (int i = 1; i < num; ++i)      printf(" %d", ans[i]);
        for (int i = 0; i < n; ++i)
        {
            if (vis[a[i].id] == 0)
                printf(" %d", a[i].id);
        }
        printf("\n");
    }
    return 0;
}