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

const int maxn = 16;

int t, n;
vector<int> a;

int judgel(vector<int> b)
{
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != a[i]) return 1;
    }
    return 0;
}

int judgez(vector<int> b)
{
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != 0) return 1;
    }
    return 0;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int tmp;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
        vector<int> b(a);
        while (judgel(b))
        {
            for (int i = 0; i < n; ++i)
            {
                a[i % n] = abs(a[(i + 1) % n] - a[i % n]);
            }
        }
        if (judgez(b) == 1) cout << "ZERO" << endl;
        else cout << "LOOP" << endl;
    }
    return 0;
}