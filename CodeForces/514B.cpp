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
#define inf (1<<20)
#define ll long long int
using namespace std;

#define MAXN 1000+10

int n, st, ed;
int x[MAXN], y[MAXN];
float k[MAXN];
int ans = 0;

void cal(int i)
{
    if (x[i] - st != 0)
        k[i] = (float)(y[i] - ed) / (float)(x[i] - st);
    else
        k[i] = inf;
}


int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &st, &ed);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        cal(i);
    }
    sort(k, k + n);
    ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (k[i] != k[i - 1])    ans++;
    }
    cout << ans;
    return 0;
}
