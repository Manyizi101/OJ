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

const int MAXN = 100000 + 10;

int g[MAXN][12], dp[MAXN][12];
int n, t, x;
int num = 0;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n, n)
    {
        memset(g, 0, sizeof(g));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> x >> t;
            g[t][x + 1]++;
            num = max(t, num);
        }
        /*
        cout << "  0 1 2 3 4 5 6 7 8 9 10" << endl;
        for (int i = 1; i <= num; i++)
        {
            cout << i  << " ";
            for (int j = 0; j < 11; j++)   cout << g[i][j] << " ";
            cout << endl;
        }
        **/
        for (int i = num, j = 0; j <= 12; j++)
        {
            dp[i][j] = g[i][j];
        }
        for (int i = num - 1; i >= 0; i--)
        {
            for (int j = 1; j <= 11; j++)
            {
                dp[i][j] = g[i][j] + max(max(dp[i + 1][j - 1], dp[i + 1][j]), dp[i + 1][j + 1]);
                //cout << dp[i][j] << endl;
            }

        }
        cout << dp[0][6] << endl;
    }
    return 0;
}