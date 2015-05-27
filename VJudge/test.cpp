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

const int MAXN = 100010;
int t, n, a[MAXN];
vector<int> v;

inline void gao(int now)
{
    if (v.empty() || now >= v[v.size() - 1])
    {
        v.push_back(now);
    }
    else
    {
        v[upper_bound(v.begin(), v.end(), now) - v.begin()] = now;
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        v.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)    scanf("%d", &a[i]);
        int now;
        for (int i = n; i >= 1; i--)
        {
            now = 2 * a[i] + 1;
            gao(now);
        }
        for (int i = 1; i <= n; i++)
        {
            now = a[i] * 2;
            gao(now);
        }
        cout << v.size() << endl;
    }
    return 0;
}