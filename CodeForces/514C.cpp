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

#define MAXN 600000+10

int n, m;
string mechanism[MAXN / 2];
string query[MAXN / 2];

void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        cin >> mechanism[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> query[i];
    }
}

bool cal(string a, string b)
{
    int len = a.length();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])  ans++;
        if (ans > 1)   return false;
    }
    if (ans == 1)  return true;
    else return false;
}

bool judge(string a)
{
    for (int j = 0; j < n; j++)
    {
        if (a.length() == mechanism[j].length() && cal(a, mechanism[j]))    return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    init();
    for (int i = 0; i < m; i++)
    {
        if (judge(query[i])) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
