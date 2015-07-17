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

const int MAXN = 1000000 + 10;

int dp[MAXN], a[MAXN], n, m;
int Max[MAXN], sum;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> m >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i] = 0;
            Max[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            sum = -inf;
            for (int j = i; j <= n; j++)
            {
                dp[j] = max(dp[j - 1] + a[j], Max[j - 1] + a[j]);
                Max[j - 1] = sum;
                sum = max(dp[j], sum);
            }
        }
        cout << sum << endl;
    }
    return 0;
}