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

const int maxn = 1e6;

double p[maxn + 5];

void init ()
{
    p[1] = 1;
    for (int i = 2; i <= maxn; i++)
        p[i] = p[i - 1] + 1.0 / i;
}

int main () {
    init();
    int n;
    while (scanf("%d", &n) == 1)
    {
        printf("%.4lf\n", n >= maxn ? 0.577215664901 + log((double)n) : p[n]);
    }
    return 0;
}