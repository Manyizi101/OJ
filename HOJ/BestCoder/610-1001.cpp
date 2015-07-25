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

const int MAXN = 100000;

int t, n, m, p, q;
int ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> p >> q;
        ans = 0;
        double val = (double)q / (double)m;
        if (val < p)
        {
            ans = n / m * q;
            n %= m;
            ans += min(p * n, q);
        }
        else
        {
            ans = n * p;
        }
        cout << ans << endl;
    }
    return 0;
}