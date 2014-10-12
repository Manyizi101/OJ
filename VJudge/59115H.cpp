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
#define MAXN 50+10
#define MAXM 2000+10

int n, m;
int a[MAXN];
int i, j;

struct node
{
    int c, l1, d, l2, money;
} course[MAXM];

void init()
{
    for (i = 0; i < n; i++)    scanf("%d", &a[i]);
    for (i = 0; i < m; i++)    scanf("%d%d%d%d%d", &course[i].c, &course[i].l1, &course[i].d, & course[i].l2, & course[i].money);
}

int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("59115H.in", "r", stdin);
    //freopen("59115H.out", "w", stdout);
#endif
    while (scanf("%d%d", &n, &m) && (n != 0 || m != 0))
    {

    }
    return 0;
}