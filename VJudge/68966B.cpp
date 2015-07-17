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
int n, a[MAXN];

int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        cout << a[(n + 1) / 2] << endl;
    }
    return 0;
}