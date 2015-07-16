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

const int MAXN = 10000;
int n, q, x[MAXN], y;
int flag = 0;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> q)
    {
        if (n == 0 && q == 0)  break;
        for (int i = 0; i < n; i++)    cin >> x[i];
        sort(x, x + n);
        cout << "CASE# " << ++flag << ":" << endl;
        while (q--)
        {
            cin >> y;
            int p = lower_bound(x, x + n, y) - x;
            if (x[p] == y) cout << y << " found at " << p + 1 << endl;
            else cout << y << " not found" << endl;
        }
    }
    return 0;
}

/*
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
**/