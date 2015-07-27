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
int b[N], ans[N];

struct node
{
    int w, s, r;
} mice[N];

int cmp(node a, node b)
{
    if (a.w == b.w)    return a.s < b.s;
    else return a.w > b.w;
}

int bSearch(int num, int k)
{
    int low = 1, high = k;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (num >= b[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int LIS()
{
    int low = 1, high = n;
    cout << n << endl;
    int k = 1;
    b[1] = mice[1].s;
    ans[1] = mice[1].r;
    for (int i = 2; i <= n; ++i)
    {
        if (mice[i].s >= b[k])
        {
            b[++k] = mice[i].s;
            ans[k] = mice[i].r;
        }
        else
        {
            int pos = bSearch(mice[i].s, k);
            b[pos] = mice[i].s;
            ans[pos] = mice[i].r;
        }
    }
    return k;
}

int main()
{
    memset(b, 0, sizeof(b));
    memset(ans, 0, sizeof(ans));
    n = 1;
    while (~scanf("%d%d", &mice[n].w, &mice[n].s))
    {
        mice[n].r = n;
        n++;
    }
    sort(mice + 1, mice + n , cmp);
    //for (int i = 1; i <= n; i++)   printf("%d %d\n", mice[i].w, mice[i].s);
    int k = LIS();
    printf("%d\n", k);
    for (int i = 1; i <= k; i++)
    {
        printf("%d\n", ans[i]);
        //printf("%d %d\n", mice[ans[i]].w, mice[ans[i]].s);
    }
    return 0;
}