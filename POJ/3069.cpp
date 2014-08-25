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

#define MAXN 1001

int point[MAXN];
int r, n;
int cover[MAXN];

void init()
{
    memset(point, 0, sizeof(point));
    memset(cover, 0, sizeof(cover));
    for (int i = 0; i < n; i++)    cin >> point[i];
    sort(point, point + n);
}

int main(int argc, char const *argv[])
{
    while (cin >> r >> n && r != -1 && n != -1)
    {
        init();
        int i = 0, ans = 0;
        while (i < n)
        {
            int s = point[i++];
            while (i < n && point[i] <= s + r) i++;
            int p = point[i - 1];
            while (i < n && point[i] <= p + r) i++;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}