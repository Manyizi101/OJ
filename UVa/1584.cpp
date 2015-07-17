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

const int MAXN = 105;

int t;
char s[MAXN];

int judge(const char s[], int p, int q)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[(p + i) % len] != s[(q + i) % len])
            return s[(p + i) % len] < s[(q + i) % len];
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> s;
        int ans = 0;
        int len = strlen(s);
        for (int i = 1; i < len; i++)
        {
            if (judge(s, i, ans))  ans = i;
        }
        for (int i = 0; i < len; i++)
        {
            cout << s[(i + ans) % len];
        }
        printf("\n");
    }
    return 0;
}