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
#define inf (1<<28)
using namespace std;

int main(int argc, char const *argv[])
{
    int p[1005], t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int i = 0;
        while (i < n)
            cin >> p[i++];
        sort(p, p + n);
        int sum = 0;
        while (n)
        {
            if (n == 1)
            {
                sum += p[0];
                n = 0;
            }
            else if (n == 2)
            {
                sum += p[1];
                n = 0;
            }
            else if (n == 3)
            {
                sum += (p[0] + p[1] + p[2]);
                n = 0;
            }
            else if (n == 4)
            {
                if (p[2] - 2 * p[1] + p[0] <= 0)
                    sum += (p[3] + p[2] + p[1] + 2 * p[0]);
                else
                    sum += (p[3] + 3 * p[1] + p[0]);
                n = 0;
            }
            else
            {
                if (p[n - 2] - 2 * p[1] + p[0] <= 0)
                    sum += (p[n - 1] + p[n - 2] + 2 * p[0]);
                else
                    sum += (p[n - 1] + 2 * p[1] + p[0]);
                n -= 2;
            }
        }
        cout << sum << endl;
    }
    return 0;
}