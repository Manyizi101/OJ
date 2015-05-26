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

int a, b, c, d;
int ans = 0;

int main()
{
    for (a = 1; a <= 6; a++)
    {
        for (b = 0; b <= 7; b++)
        {
            for (c = 4; c <= 8; c++)
            {
                for (d = 2; d <= 6; d++)
                {
                    if (a + b + c + d == 20) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}