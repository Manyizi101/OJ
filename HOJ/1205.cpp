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

const int MAXN = 1000000 + 10;

ll t, n, m[MAXN];
ll sum, Max;

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        sum = 0;
        Max = -1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> m[i];
            sum += m[i];
            Max = max(Max, m[i]);
        }
        if (sum >= 2 * Max - 1)   cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}