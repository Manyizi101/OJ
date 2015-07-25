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

string s, a[3], x = "anniversary";
int t;

bool judge()
{
    int lens = s.size();
    if (lens < x.size())   return false;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = i + 1; j <= 10; j++)
        {
            for (int k = j + 1; k <= 11; k++)
            {
                a[0] = x.substr(0, i);
                a[1] = x.substr(i, j - i);
                a[2] = x.substr(j, 11 - j);
                int x = s.find(a[0]);
                //cout << s.substr(0) << endl;
                if (x < 0) continue;
                int y = s.find(a[1], x + 1);
                //cout << s.substr(x + a[0].size()) << endl;
                if (y < 0) continue;
                int z = s.find(a[2], y + 1);
                //cout << s.substr(y + a[1].size()) << endl;
                if (z < 0) continue;
                // cout << x << " " << y << " " << z << endl;
                // cout << a[0] << endl << a[1] << endl << a[2] << endl;
                if (x >= 0 && (x < y) && (y < z) && z <= lens)
                {
                    // cout << a[0] << endl << a[1] << endl << a[2] << endl;
                    // cout << x << " " << y << " " << z << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    //freopen("610-1002.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (judge()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}