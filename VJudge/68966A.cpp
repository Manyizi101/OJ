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
int m, n, x[MAXN];
int MaxSum, ThisSum;
int l, r;

int main()
{
    while (~scanf("%d%d", &m, &n))
    {
        MaxSum = ThisSum = 0;
        l = r = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x[i]);
            ThisSum += x[i];
            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
                r = i;
            }
            if (ThisSum < 0)
            {
                ThisSum = 0;
                l = i;
            }
        }
        sort(x + l, x + r + 1);
        for (int i = l; i < r + 1; i++)
        {
            if (m != 1 && x[i] < 0)
            {
                MaxSum -= x[i];
                m--;
            }
            if (m == 1)    break;
        }
        printf("%d\n", MaxSum);
    }
    return 0;
}