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

const int MAXN = 100 + 10;
char a[MAXN], b[MAXN];
int xa[26], xb[26];
int len = 0;

bool judge()
{
    for (int i = 0; i < 26; i++)
    {
        if (xa[i] != xb[i])    return false;
    }
    return true;
}

int main()
{
    while (~scanf("%s%s", a, b))
    {
        len = strlen(a);
        for (int i = 0; i < len; i++)
        {
            xa[a[i] - 'A']++;
            xb[b[i] - 'A']++;
        }
        sort(xa, xa + 26);
        sort(xb, xb + 26);
        if (judge()) puts("YES");
        else puts("NO");
        memset(xa, 0, sizeof(xa));
        memset(xb, 0, sizeof(xb));
    }
    return 0;
}