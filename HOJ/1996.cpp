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

int n, x;

ll qPow(int A, int n)
{
    if (n == 0) return 1;
    ll rslt = 1LL;
    while (n)
    {
        if (n & 1)
        {
            rslt *= A;
        }
        A *= A;
        n >>= 1;
    }
    return rslt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        cin >> x;
        cout << qPow(3, x) << endl;
    }
    return 0;
}