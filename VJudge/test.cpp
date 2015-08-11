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

string g, b;

string gtob(string g)
{
    string b = "";
    b += (0 ^ (g[0] - '0')) + '0';
    for (unsigned i = 1; i < g.size(); ++i)
    {
        b += ((b[i - 1] - '0') ^ (g[i] - '0')) + '0';
    }
    return b;
}

const int maxn = 2 * 1e5 + 10;

int t, n, a[maxn];
ll ans = 0;;
int cs = 0;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int flag = 0, one = -1;
        ans = 0;
        cin >> g;
        n = g.size();
        for (int i = 0; i < n; ++i)    scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
        {
            if (g[i] == '?')
            {
                one = i;
                break;
            }
            if (g[i] == '1')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            for (int i = 0; i < n; ++i)
            {
                if (g[i] == '?')   g[i] = '0';
            }
        else
        {
            g[one] = '1';
            for (int i = one + 1; i < n; ++i)
            {
                if (g[i] == '?')   g[i] = '0';
            }
        }
        b = gtob(g);
        for (int i = 0; i < n; ++i)
        {
            if (b[i] == '1')   ans += a[i];
        }
        printf("Case #%d: ", ++cs);
        printf("%I64d\n", ans);
    }
}
