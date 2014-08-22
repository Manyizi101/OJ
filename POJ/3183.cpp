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

int main(int argc, char const *argv[])
{
    int n;
    int i, j;
    int flag;
    int now, last, next;

    scanf("%d", &n);
    last = -1, now = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &next);
        if (last <= now && now >= next)
        {
            printf("%d\n", i - 1);
        }
        last = now;
        now = next;
    }
    if (now >= last)
    {
        printf("%d\n", i - 1);
    }
    return 0;
}
