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
#define ll long long int
using namespace std;

int n, ans = 0;
int tmp, t;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    while (n--)
    {
        t = 0;
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &tmp);
            t += tmp;
        }
        if (t >= 2)    ans++;
    }
    cout << ans;
    return 0;
}

