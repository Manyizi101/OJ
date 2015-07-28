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

const int MAXN = 51000;

int n, l[MAXN], r[MAXN];
int LIS[MAXN];

// LIS[j] = max(LIS[i]) + 1
int lis(int *arraya, int *arrayb, int nLength)
{
    for (int i = 0; i < nLength; i++)
    {
        LIS[i] = 1;
    }

    for (int i = 1; i < nLength; i++)
    {
        int maxLen = 0;
        for (int j = 0; j < i; j++)
        {
            if (arraya[i] >= arraya[j] && arrayb[i] <= arrayb[j])
            {
                if (maxLen < LIS[j])
                    maxLen = LIS[j];
            }
        }
        LIS[i] = maxLen + 1;
    }
    int maxLIS = 0;
    for (int i = 0; i < nLength; i++)
    {
        if (maxLIS < LIS[i])
            maxLIS = LIS[i];
    }

    return maxLIS;
}

int main()
{
    while (~scanf("%d", &n))
    {
        memset(LIS, 0, sizeof(LIS));
        int tmp[MAXN];
        for (int i = 0; i < n; i++)    scanf("%d", &tmp[i]);
        for (int i = n - 1; i >= 0; i--)    l[n - i - 1] = tmp[i];
        for (int i = 0; i < n; i++)    scanf("%d", &tmp[i]);
        for (int i = n - 1; i >= 0; i--)    r[n - i - 1] = tmp[i];
        int len = lis(l, r, n);
        printf("%d\n", len);
        printf("%d", LIS[0]);
        for (int i = 1; i < len ; i++)  printf(" %d", LIS[i]);
        printf("\n");
    }
    return 0;
}