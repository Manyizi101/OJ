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

const int MAXN = 10000;
const int Max = 1000000000;
int x[MAXN];
int t, n;
int ans = 0;

int cal(int x)
{
    return 3 * x * (x - 1) + 1;
}

int pos(int x)
{
    return floor(0.5 + sqrt(12 * x - 3) / 6.0);
}

int dp(int n)
{
    if (n == 0)    return ans;
    ans++;
    dp(n - x[pos(n)]);
}

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 10000; i++)
    {
        x[i] = cal(i);
    }
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        cout << dp(n) << endl;
    }
    return 0;
}