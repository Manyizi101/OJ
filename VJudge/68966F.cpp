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

const int MAXN = 500 + 10;
int t, e, f, n, p[MAXN], w[MAXN], dp[10010];

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        memset(dp, inf, sizeof(dp));
        cin >> e >> f >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> w[i];
        }
        dp[f - e] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = f - e; j >= 0; j--)
            {
                if (j + w[i] <= f - e)
                    dp[j] = min(dp[j], dp[j + w[i]] + p[i]);
            }
        }
        if (dp[0] == inf)  cout << "This is impossible." << endl;
        else cout << "The minimum amount of money in the piggy-bank is " << dp[0] << "." << endl;
    }
    return 0;
}