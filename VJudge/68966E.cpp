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

const int MAXN = 1000 + 10;

int sum, n, a[MAXN], dp[MAXN];
int Max;

int main()
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            dp[i] = a[i];
        }
        Max = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] > a[i])
                {
                    dp[j] = max(dp[j], dp[i] + a[j]);
                    Max = max(Max, dp[j]);
                }
            }
        }
        cout << Max << endl;
    }
    return 0;
}