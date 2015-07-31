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
int n;
int a[MAXN];
int dp[MAXN];

int lis()
{
    memset(dp, 0, sizeof(dp));
    int Max;
    for (int i = 0; i < n; ++i)
    {
        Max = 0;
        for (int j = 0; j < i; ++j)
        {
            if (a[i] > a[j])
            {
                Max = max(Max, dp[j]);
            }
        }
        dp[i] = Max + 1;
    }
    Max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] > Max)    Max = dp[i];
    }
    return Max;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    cout << lis() << endl;
    return 0;
}