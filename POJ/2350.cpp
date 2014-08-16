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
#define inf (1<<30)
using namespace std;

int main(int argc, char const *argv[])
{
    int t, n, i, a[1000];
    float sum, num;
    scanf("%d", &t);
    while (t--)
    {
        sum = 0;
        num = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sum /= n;
        for (i = 0; i < n; i++)
            if (a[i] > sum)
                num++;
        printf("%2.3f%%\n", 100 * num / n);

    }
}