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

unsigned int mod(unsigned int dividend, unsigned int divisor)
{
    if (dividend < divisor)
        return  dividend;
    unsigned int k, c, quotient = 0, remainder;
    while (dividend > divisor)
    {
        for (k = 0, c = divisor; dividend >= c; c <<= 1, k++)
        {
            if (dividend - c < divisor)
            {
                quotient += 1 << k;
                remainder = dividend - c;
                break;
            }
        }
        if (dividend - c < divisor)
            break;
        quotient += 1 << (k - 1);
        dividend -= c >> 1;
    }
    return remainder;
}

int main()
{
    unsigned int n, m, ans, i;
    while (scanf("%u%u", &n, &m) != EOF)
    {
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            if (i & 1)  ans = mod(((ans << 1) + 1), m);
            else ans = mod(ans << 1 , m);
        }
        printf("%u\n", ans);
    }
    return 0;
}