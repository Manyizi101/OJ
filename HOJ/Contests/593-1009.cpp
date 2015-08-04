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

string s;

string fib(int n)
{
    string  a;
    if (n == 1)    return a += "b";
    else if (n == 2)   return a += "a";
    else return a = fib(n - 1) + fib(n - 2);
}

string cal(int n)
{
    string s;
    for (int i = 1; i <= n; i++)
    {
        s += fib(i);
    }
    return s;
}

bool judge(string s, int x)
{
    for (int i = 0; i < x; i++)
    {
        if (s[i] != s[s.size() - x + i])  return false;
    }
    return true;
}

int lb(string s, int m)
{
    for (int i = m - 1; i >= 1; i--)
    {
        if (judge(s, i))    return i;
    }
    return 0;
}

int main()
{
    for (int i = 1; i <= 12; i++)
    {
        string s = fib(i);
        for (int j = 1; j <= (int)s.size(); j++)
        {
            printf("%3d", lb(s, j));
        }
        cout << endl;
    }
    return 0;
}