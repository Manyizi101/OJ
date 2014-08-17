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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;

int r[1005];
int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f, g, h, i;
    int j;
    int test;
    cin >> test;
    while (test--)
    {
        scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
        r[0] = a;
        r[1] = b;
        r[2] = c;
        for (j = 3; j <= i; j++)
        {

            if (j % 2 == 1)
            {
                r[j] = (d * r[j - 1] + e * r[j - 2] - f * r[j - 3]) % g;
                if (r[j] < 0) r[j] += g;

            }
            else
            {
                r[j] = (f * r[j - 1] - d * r[j - 2] + e * r[j - 3]) % h;
                if (r[j] < 0)  r[j] += h;

            }
        }
        cout << r[i] << endl;
    }
}