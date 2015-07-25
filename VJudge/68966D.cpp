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

const int MAXN = 17;
int dp[1 << MAXN], c[MAXN], d[MAXN];
int t, n;

struct node
{
    int pre,t,
};

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        string a;
        int b;
        for (int i = 1; i <= n; i++)
        {
            cin >> a >> d[i] >> c[i];
        }
        for (int i = (1 << MAXN) - 1; i >= 0; i--)
        {
            for (int j = 1; j <= n && (i - (1 << j) >= 0); j++)
            {
                dp[i] += max(dp[i - (1 << j)] + c[j], dp[i]);
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }
    return 0;
}