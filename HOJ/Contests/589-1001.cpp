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

const int MAXN = 100000 + 10;
const int MOD = 1000000000 + 7;
const int N = 10010;

int n, a[MAXN];
int p[10010], phi[10010];
ll sum;

void getphi()
{
    for (int i = 1; i <= N; i++) // 初始化
    { p[i] = 1; phi[i] = i; }
    p[1] = 0;   // 1不是素数
    for (int i = 2; i <= N; i++) // 筛素数
    {
        if (p[i])
        {
            for (int j = i * i; j <= N; j += i)
            { p[j] = 0; }
        }
    }
    for (int i = 2; i <= N; i++) // 求欧拉函数
    {
        if (p[i])
        {
            for (int j = i; j <= N; j += i) // 处理素因子p[i]
            {
                phi[j] = phi[j] / i * (i - 1);  // 先除后乘，防止中间过程超出范围
            }
        }
    }
}


int main()
{
    getphi();
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)    scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        a[0] = a[1], a[n + 1] = a[n];
        sum = n;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i - 1] && a[i] == a[i + 1])
            {
                continue;
            }
            else if (a[i] == a[i - 1] && a[i] != a[i + 1])
            {
                sum += (n - i) % MOD;
                //cout << "n-i " << n - i << endl;
            }
            else if (a[i] != a[i - 1] && a[i] == a[i + 1])
            {
                if (phi[a[i]] != 1)    sum += (n - i + (phi[a[i]] - 1)) % MOD;
                //cout << "phi " << phi[a[i]] - 1 << endl;
            }
            else
            {
                sum += n - i;
                if (phi[a[i]] != 1)    sum += (n - i + (phi[a[i]] - 1)) % MOD;
                //cout << "n-i " << n - i << " phi " << phi[a[i]] - 1 << endl;
            }

        }
        printf("%d\n", sum % MOD);
    }
    return 0;
}