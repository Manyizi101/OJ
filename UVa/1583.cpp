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

const int MAXN = 100000 + 10;
int a[MAXN], t, n;

int cal(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 100000; i++)
    {
        int gen = cal(i) + i;
        if (a[gen] == 0 || a[gen] > i) a[gen] = i;
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}