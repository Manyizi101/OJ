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

#define MAXN 50001

int t, n, a[MAXN];
int left;
void init()
{
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)    scanf("%d", &a[i]);
}

int main(int argc, char const *argv[])
{
    freopen("2479.in", "r", stdin);
    freopen("2479.out", "w", stdout);
    scanf(" % d", &t);
    while (t--)
    {
        init();
    }
    cout<<"Hello,world!!!!";
    return 0;
}