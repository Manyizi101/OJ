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

const int MAXN = 2000 + 10;

int n, k, one[MAXN], two[MAXN];
int dp[MAXN];
int hh, mm, ss, flag, ans;

int main()
{
    //ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        hh = 0, mm = 0, ss = 0, flag = 0;
        memset(dp, inf, sizeof(dp));
        cin >> k;
        for (int i = 1; i <= k; i++)    cin >> one[i];
        for (int i = 1; i < k; i++)  cin >> two[i];
        dp[1] = one[1];
        dp[2] = min(two[1], one[1] + one[2]);
        for (int i = 3; i <= k; i++)
        {
            dp[i] = min(dp[i - 1] + one[i], dp[i - 2] + two[i - 1]);
        }
        //cout << dp[k] << endl;
        ans = dp[k];
        hh = ans / 3600;
        ans %= 3600;
        mm = ans / 60;
        ans %= 60;
        ss = ans;
        if (hh + 8 > 12)
        {
            flag = 1;
            hh -= 12;
        }
        printf("%02d:%02d:%02d ", hh + 8, mm, ss);
        flag == 0 ? puts("am") : puts("pm");
    }

    return 0;
}