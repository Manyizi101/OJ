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

const int MAXN = 100 + 10;
const int MOD = 10000;
int n, p[MAXN], m[MAXN];
int ans[MAXN * MAXN], tmp[MAXN * MAXN];
int sum;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n && n)
    {
        memset(ans, 0, sizeof(ans));
        memset(tmp, 0, sizeof(tmp));
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> m[i];
            sum += p[i] * m[i];
        }
        if (sum % 3)
        {
            cout << "sorry" << endl;
            continue;
        }
        ans[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m[i]; j++)
            {
                for (int k = 0; k + j * p[i] <= sum; k++)
                {
                    tmp[k + j * p[i]] += ans[k];
                }
            }
            for (int j = 0; j <= sum; j++)
            {
                ans[j] = tmp[j];
                tmp[j] = 0;
                ans[j] %= MOD;
            }
        }
        if (ans[sum / 3])  cout << ans[sum / 3] % MOD << endl;
        else cout << "sorry" << endl;
    }
    return 0;
}