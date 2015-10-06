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

const int MAXN = 1e4 + 10;
int a[MAXN], b[MAXN];

int main()
{
    int n;
    while (~scanf ("%d", &n)) {
        memset (b, 0, sizeof (b));
        for (int i=1; i<=n; ++i)    scanf ("%d", &a[i]);
        long long ans = 0;
        for (int i=n; i>=1; --i) {
            ans += b[a[i]];
            for (int j=1; j*j<=a[i]; ++j) {
                if (a[i] % j == 0) {
                    b[j] = i;
                    b[a[i]/j] = i;
                }
            }
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}
