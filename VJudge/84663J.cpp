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

const int MAXN = 10000000;

char s[MAXN], t[MAXN];

int main()
{
    while (~scanf("%s%s", s, t))
    {
        int i = 0, j = 0;
        for (; t[i]; i++)
        {
            if (t[i] == s[j])  j++;
        }
        if (!s[j]) puts("Yes");
        else    puts("No");
    }
    return 0;
}