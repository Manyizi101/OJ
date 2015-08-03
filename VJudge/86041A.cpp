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

int t, a, b, c;
int ans = 0;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d%d%d", &a, &b, &c);
        for (int i = 1; a * i < c; i++)
        {
            if ((c - a * i) % b == 0)    ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}