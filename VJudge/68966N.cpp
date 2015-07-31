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
int n;
int a[MAXN];
int dp[MAXN];

int lis()
{
    memset(dp, 0, sizeof(int)*n);
    int len = 1;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        int pos = lower_bound(dp, dp + len, a[i]) - dp;
        len = max(len, pos + 1);
        dp[pos] = a[i];
    }
    return len;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    cout << lis() << endl;
    return 0;

}