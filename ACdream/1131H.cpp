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
#define inf (1<<28)
using namespace std;

#define LOCAL
#define MAXN 410

int m, n;
char a[MAXN][MAXN];

void init()
{
    scanf("%d%d", &m, &n);
    getchar();
    for (int i = 0; i < 2 * m - 1; i++)
    {
        gets(a[i]);
    }
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("1131H.in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif
    init();
    for (int i = 0; i < 2 * m - 1; i++)
    {
        for (int j = 0; j < 2 * n + 1; j++)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}