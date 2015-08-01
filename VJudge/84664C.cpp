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

const int maxn = 20 + 10;

int n, m, k, a[maxn];

int go(int p, int d, int t)
{
    while (t--)
    {
        do
        {
            p = (p + d + n - 1) % n + 1;
        }
        while (a[p] == 0);
    }
    return p;
}

int main()
{
    while (~scanf("%d%d%d", &n, &k, &m) && n)
    {
        for (int i = 1; i <= n; ++i)   a[i] = i;
        int left = n;
        int p1 = n, p2 = 1;
        while (left)
        {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            printf("%3d", p1);
            left--;
            if (p2 != p1)  {printf("%3d", p2); left--;}
            a[p1] = a[p2] = 0;
            if (left)    printf(",");
        }
        printf("\n");
    }
    return 0;
}