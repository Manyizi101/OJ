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

const int maxn = 1e5 + 5;

int n;
ll m[maxn];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d", &m[i]);
        }
        printf("%I64d %I64d\n", m[1] - m[0], m[n - 1] - m[0]);
        for (int i = 1; i < n - 1; ++i)
        {
            printf("%I64d %I64d\n", min(m[i + 1] - m[i], m[i] - m[i - 1]), max(m[n - 1] - m[i], m[i] - m[0]));
        }
        printf("%I64d %I64d\n", m[n - 1] - m[n - 2], m[n - 1] - m[0]);
    }
    return 0;
}