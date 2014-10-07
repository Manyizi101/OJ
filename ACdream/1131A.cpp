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
#define MAXN 10001

int n, m, net[MAXN][MAXN], a, b;

void init()
{
    int x, y;
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        scanf("%d", &net[x][y]);
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}