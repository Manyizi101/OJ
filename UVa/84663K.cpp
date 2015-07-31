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

struct node
{
    int w, h;
    void read()
    {
        scanf("%d%d", &w, &h);
        if (w > h) swap(w, h);
    }
} a[6];

bool cmp(node a, node b)
{
    if (a.w == b.w)    return a.h < b.h;
    else return a.w < b.w;
}

bool judge()
{
    for (int i = 1; i < 4; i++)
    {
        if (a[i].w != a[i - 1].w) return false;
    }
    for (int i = 3; i < 6; i++)
    {
        if (a[i].h != a[i - 1].h)    return false;
    }
    if (a[0].h != a[4].w || a[1].h != a[5].w)  return false;
    return true;
}

int main()
{
    while (cin >> a[0].w >> a[0].h)
    {
        if (a[0].w > a[0].h)   swap(a[0].w, a[0].h);
        for (int i = 1; i < 6; i++)   a[i].read();
        sort(a, a + 6, cmp);
        if (judge())
        {
            puts("POSSIBLE");
        }
        else
        {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}