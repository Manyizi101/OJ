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

const int maxn = 1010;
const int maxm = 65;
int t, n;
ll a[maxn];
int mat[maxm][maxm];

int rnk(int mat[][maxm], int n, int m)
{
    int ret = 0;
    for (int i = 0, it = 0; i < n && it < m; ++it)
    {
        int pos = -1;
        for (int j = i; j < n; ++j)
        {
            if (mat[j][it])
            {
                pos = j;
                break;
            }
        }
        if (pos == -1)   continue;
        ++ret;
        if (pos != i)
        {
            for (int j = it; j < m; ++j)
            {
                swap(mat[i][j], mat[pos][j]);
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (i != j && mat[j][it])
            {
                for (int k = it; k < m; ++k)
                {
                    mat[j][k] ^= mat[i][k];
                }
            }
        }
        ++i;
    }
    return ret;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll sum = 0;
        memset(mat, 0, sizeof(mat));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%I64d", &a[i]);
            sum ^= a[i];
        }
        if (sum == 0 || n > maxm)
        {
            printf("Yes\n");
            continue;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < maxm; ++j)
            {
                mat[i][j] = (a[i] >> j) & 1;
            }
        }
        int ret = rnk(mat, n, maxm);
        if (ret < n)  printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
