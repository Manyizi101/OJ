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

const int M = 1000000000;
const int MAXN = 1000010;

int dp[MAXN];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i)
        if (i & 0x01)
            dp[i] = dp[i - 1];
        else
            dp[i] = (dp[i - 2] + dp[i >> 1]) % M;

    printf("%d\n", dp[n]);
    return 0;
}