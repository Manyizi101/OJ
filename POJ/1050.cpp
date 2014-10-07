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

//#define LOCAL
#define MAXN 102

int n, a[MAXN][MAXN];
int tmp[MAXN];
int maxALL, maxONE;

void init()
{
    scanf("%d", &n);
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int dp(int *arr, int n)
{
    int max = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        if (x < 0) x = arr[i];
        else
        {
            x += arr[i];
            if (x > max)   max = x;
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("1050.in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif
    init();
    for (int i = 0; i < n; i++)
    {
        memset(tmp, 0, sizeof(tmp));
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++)    tmp[k] += a[j][k];
            maxONE = dp(tmp, n);
            if (maxONE > maxALL)   maxALL = maxONE;
        }
    }
    cout << maxALL << endl;
    return 0;
}