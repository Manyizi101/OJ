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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
using namespace std;

#define MAXN 20000

int n, m;
int w[MAXN], d[MAXN];
int dp[MAXN];

void init()
{
    memset(w, 0, sizeof(w));
    memset(d, 0, sizeof(d));
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> d[i];
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    solve();
    printf("%d\n", dp[m]);
    return 0;
}