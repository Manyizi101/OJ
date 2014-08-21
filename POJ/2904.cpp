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
    int ii, casenum;
    long long int n, m, i;
    long long int sum;

    scanf("%d", &casenum);
    for (ii = 1; ii <= casenum; ii++)
    {
        scanf("%lld%lld", &n, &m);
        if (n > m)
        {
            i = m;
            m = n;
            n = i;
        }
        sum = (n + m) * (m - n + 1) / 2;
        printf("Scenario #%d:\n%lld\n\n", ii, sum);
    }
    return 0;
}
