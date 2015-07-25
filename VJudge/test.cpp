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

int main()
{
    ios::sync_with_stdio(false);
    return 0;
}
const int MAX = 1 << 15 + 1;
int dp[MAX], t[MAX], pre[MAX], all_t[20], fin_t[20]; //dp [i] 是 i 状态下的最小扣分. t [i]是 i 状态下的所花时间. pre [i] 就是到达 i 状态的前驱作业编号.
char str[20][110];
int ca, n;

void out(int x)
{
    if (!x) return;
    out(x - (1 <= 0; j--);
    {
        int step = 1 < dp[i - step] + score)
        {
            dp[i] = dp[i - step] + score;
            t[i] = t[i - step] + fin_t[j];
            pre[i] = j;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &ca);
    out(tot - 1);
    while (ca--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)    scanf("%s%d%d", str[i], &fin_t[i], &t[i]);
        printf("%d\n", dp[n - 1]);

    }
    return 0;
}