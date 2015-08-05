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

const int maxn = 1000;

int t, a, b, c;
ll fib[maxn];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        fib[1] = a;
        fib[2] = b;
        int i = 3;
        while (fib[i - 2] + fib[i - 1] <= c)
        {
            fib[i] = fib[i - 2] + fib[i - 1];
            ++i;
        }
        if (fib[i - 1] == c)   printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}