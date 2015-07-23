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

set<int> ans;
int n;

void chk(int n, set<int> &ans)
{
    int high;
    int a, b, c;
    for (int k = 1; k <= n; k *= 10)
    {
        high = n / k;
        c = high / 11;
        b = high % 11;
        if ((b != 0 || c != 0) && b < 10)
        {
            a = n - (b + 11 * c) * k;
            //cout << a << " " << b << " " << c << endl;
            if (!(a & 1))
            {
                ans.insert(a / 2 + b * k + 10 * c * k);
            }
        }
        b = high % 11 - 1;
        if ((b != 0 || c != 0) && b >= 0)
        {
            a = n - (b + 11 * c) * k;
            //cout << a << " " << b << " " << c << endl;
            if (!(a & 1))
            {
                ans.insert(a / 2 + b * k + 10 * c * k);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n && n)
    {
        ans.clear();
        chk(n, ans);
        if (ans.empty())
        {
            cout << "No solution." << endl;
        }
        else
        {
            set<int>::iterator it = ans.begin();
            cout << *it;
            while (++it != ans.end())
            {
                cout << " " << *it;
            }
            cout << endl;
        }
    }
    return 0;
}