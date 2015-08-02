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

ll qpow(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}

int main()
{
    ll n, m, ans;
    while (scanf("%I64d%I64d", &n, &m) != EOF)
    {
        if (n & 1) ans = (qpow(2, n + 1, m * 3) - 1) / 3;
        else ans = (qpow(2, n + 1, m * 3) - 2) / 3;
        printf("%I64d\n", (ans % m));
    }
    return 0;
}