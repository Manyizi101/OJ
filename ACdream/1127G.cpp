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
#define MAXN 1005

struct node
{
    int flag;
    int k;
    int x;
} no[MAXN];

int n, m, y, remain;
int i;

bool cmp1(node a, node b)
{
    return (abs((a.k + 1) * 1.0 / m - a.x * 1.0 / y) - abs((a.k) * 1.0 / m - a.x * 1.0 / y)) > (abs((b.k + 1) * 1.0 / m - b.x * 1.0 / y) - abs((b.k) * 1.0 / m - b.x * 1.0 / y));
}

bool cmp2(node a, node b)
{
    return a.flag < b.flag;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m >> y;
    remain = m;
    for (i = 0; i < n; i++)
    {
        cin >> no[i].x;
        no[i].k = floor(m * no[i].x / y);
        remain -= no[i].k;
        no[i].flag = i;
    }
    sort(no, no + n, cmp1);
    i = 0;
    while (remain)
    {
        no[i].k++;
        remain--;
        i++;
        if (i >= n) i -= n;
    }
    sort(no, no + n, cmp2);
    for (i = 0; i < n; i++)    cout << no[i].k << ' ';
    return 0;
}