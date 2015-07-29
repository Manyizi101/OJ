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

int t, m, n;
string a[50 + 10];
int dp[60];
int tmp = inf;

char cal(int pos)
{
    int x[4] = {0};
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i][pos] == 'A')  x[0]++;
        else if (a[i][pos] == 'C') x[1]++;
        else if (a[i][pos] == 'G') x[2]++;
        else x[3]++;
    }
    for (int i = 0; i < 4; ++i)    tmp = max(tmp, x[i]);
    for (int i = 3; i >= 0; --i)
    {
        if (x[i] == tmp)   ans = i;
    }
    if (ans == 0)  return 'A';
    else if (ans == 1) return 'C';
    else if (ans == 2) return 'G';
    else return 'T';
}

int solve(string a, string b)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])  ans++;
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        tmp = inf;
        string x;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i)    a[i].clear();
        for (int i = 0; i < m; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            x += cal(i);
        }
        int ans = 0;
        for (int i = 0; i < m; i++)    ans += solve(x, a[i]);
        cout << x << endl << ans << endl;
    }
    return 0;
}