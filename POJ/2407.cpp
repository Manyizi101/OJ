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


int Euler (int n)
{
    int i, res = n;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            n /= i;
            res = res - res / i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res = res - res / n;
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    while (scanf ("%d", &n), n)
        printf ("%d\n", Euler(n));
    return 0;
}
