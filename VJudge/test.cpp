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

const int maxn = 3 * 1e6 + 10;

int d[maxn];
int t[maxn];

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        int i;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &d[i]);
        }
        memset(t, 0, sizeof(t));
        int ans = n;
        for (i = 1; i <= n; ++i) {
            if (t[d[i]] == 1) continue;
            int start = i;
            int x = i;
            t[x] = 1;
            while (1) {
                x = d[x];
                t[x] = 1;
                if (x == start)
                    break;
            }
            --ans;
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}