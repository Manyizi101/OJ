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

const int mod = (1e9 + 7);

LL euler_phi(int n) {
    LL ans = n;
    for (int i = 2; i <= (int)sqrt(n + 0.5); i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
int n, k;
int main()
{
    while (scanf("%d%d", &n, &k) != EOF) {
        if (n == 1 || k == 2) puts("1");
        else if (k > 2) puts("0");
        else {
            LL ans = 0;
            for (int g = 1; g <= sqrt(n * 1.0); g++)
                if (n % g == 0) {
                    if (g != n / g) ans = ans + euler_phi(n / g) * euler_phi(g) * 2;
                    else ans = ans + euler_phi(n / g) * euler_phi(g);
                }
            printf("%I64d\n", ans % mod);
        }
    }
}