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

const int MAXN = 1010;
string x, y;
int dp[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> x >> y)
    {
        int xlen = x.size();
        int ylen = y.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= xlen; i++)
        {
            for (int j = 1; j <= ylen; j++)
            {
                if (x[i - 1] == y[j - 1])  dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                //cout << dp[i][j] << " ";f
            }
        }
        //cout << endl;
        cout << dp[xlen][ylen] << endl;
    }
    return 0;
}