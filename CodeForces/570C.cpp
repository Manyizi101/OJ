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

const int maxn = 3 * 1e5 + 10;

int n, m;
int x, ans;
char c, a[maxn];

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        scanf("%s", a + 1);
        a[0] = a[n + 1] = 'a';
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == '.' && a[i - 1] == '.')  ans++;
        }
        for (; m; --m)
        {
            scanf("%d %c", &x, &c);
            if (c == '.' && a[x] == '.')
            {
                printf("%d\n", ans);
            }
            else if (c == '.' && a[x] != '.')
            {
                a[x] = c;
                if (a[x - 1] == '.' && a[x + 1] != '.')    ans++;
                else if (a[x + 1] == '.' && a[x - 1] != '.')   ans++;
                else if (a[x - 1] == '.' && a[x + 1] == '.')   ans += 2;
                printf("%d\n", ans);
            }
            else if (c != '.' && a[x] == '.')
            {
                a[x] = c;
                if (a[x - 1] == '.' && a[x + 1] != '.')    ans--;
                else if (a[x + 1] == '.' && a[x - 1] != '.')   ans--;
                else if (a[x - 1] == '.' && a[x + 1] == '.')   ans -= 2;
                printf("%d\n", ans);
            }
            else
            {
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}