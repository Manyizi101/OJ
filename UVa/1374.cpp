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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define N 3005

int aid, tmp, v[N], rec[N], pTow[50], ans[N];

bool dfs(int d, int s)
{
    if (d == tmp && s == aid) return true;
    if (d >= tmp || s > 1500) return false;
    if (s * pTow[tmp - d] < aid) return false;

    rec[d] = s;
    v[s] = 1;

    for (int i = 0; i <= d; i++)
    {
        int u = rec[i] + s;
        if (v[u] == 0)
            if (dfs(d + 1, u)) return true;

        u = abs(s - rec[i]);
        if (v[u] == 0)
            if (dfs(d + 1, u)) return true;
    }
    v[s] = 0;
    return false;
}

int solve()
{
    tmp = 0;
    memset(v, 0, sizeof(v));
    while (1)
    {
        if (dfs(0, 1)) break;
        tmp++;
    }
    return tmp;
}

void init()
{
    pTow[0] = 1;
    for (int i = 1; i <= 31; i++) pTow[i] = pTow[i - 1] * 2;
}

int main(int argc, char const *argv[])
{
    init();
    while (scanf("%d", &aid) == 1 && aid)
    {
        printf("%d\n", solve());
    }
    return 0;
}
