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
#define ll long long int
using namespace std;

#define MAXN 100+10

int n, m, b, g;
bool x[MAXN], y[MAXN];
int tmp;

void init()
{
    memset(x, false, sizeof(x));
    memset(y, false, sizeof(y));
    scanf("%d%d", &n, &m);
    scanf("%d", &b);
    for (int i = 1; i <= b; i++)
    {
    	scanf("%d", &tmp);
        x[tmp] = true;
    }
    scanf("%d", &g);
    for (int i = 1; i <= g; i++)
    {
    	scanf("%d", &tmp);
        y[tmp] = true;
    }
}

bool judge()
{
    for (int i = 0; i < n; i++)
    {
        if (!x[i])  return false;
    }
    for (int i = 0; i < m; i++)
    {
        if (!y[i])   return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    init();
    for (int i = 0; i <1000000; i++)
    {
        if (x[i % n] || y[i % m])
        {
            x[i % n] = true;
            y[i % m] = true;
        }
    }
    if (judge()) cout << "Yes";
    else cout << "No";
    return 0;
}