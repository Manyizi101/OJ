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

int t, n;
unsigned int ans = 0;

int gcd(int a , int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    const unsigned int mod = pow(2, 32);
    float tmp = 0;
    for (int n = 1; n <= 10; n++)
    {
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= n; ++k)
                {
                    for (int l = 1; l <= n; ++l)
                    {
                        ans += lcm(gcd(i, j), gcd(k, l));
                        //cout << lcm(gcd(i, j), gcd(k, l)) << endl;
                    }
                }
            }
        }
        printf("%f %f\n", log(sqrt(ans % mod)), log(sqrt(ans % mod)) - tmp);
        tmp = log(sqrt(ans % mod));
    }
    return 0;
}