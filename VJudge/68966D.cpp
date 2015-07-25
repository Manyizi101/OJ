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

const int MAXN = 15 + 10;

int t, n;
int dead;

struct  node
{
    string name;
    int d, c;
} course[MAXN];

bool cmp(node a, node b)
{
    if (a.d == b.d && a.c == b.c)  return a.name < b.name;
    else if (a.d == b.d)   return a.c > b.c;
    else return a.d < b.d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> course[i].name >> course[i].d >> course[i].c;
        }
        sort(course, course + n, cmp);
        dead = course[0].d - course[0].c;
        for (int i = 1; i < n; i++)
        {
            if ((course[i].d - course[i - 1].d) > (course[i].c - course[i - 1].c))
                continue;
            else
            {
                dead += course[i].d - course[i].c;
            }
        }
        cout << dead << endl;
        for (int i = 0; i < n; i++)    cout << course[i].name << endl;
    }
    return 0;
}