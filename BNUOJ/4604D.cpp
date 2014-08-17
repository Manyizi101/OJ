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
    int n;
    long long int k;
    int a[1001];
    int i, j, l;
    long long int now, min, max, repeat;


    while (scanf("%d %lld", &n, &k) != EOF)
    {
        min = max = repeat = now = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                if (a[i] > a[j]) now++;
                if (a[i] == a[j]) repeat++;
            }
        }
        max = n * (n - 1) / 2 - repeat;

        if ((max - now) >= k)
        {
            max = now + k;
        }
        else if (repeat == 0 && (k - (max - now)) % 2 == 1)
        {
            max--;
        }
        
        if (now >= k )
        {
            min = now - k;
        }
        else if ( repeat == 0 && (k - now) % 2 == 1)
        {
            min++;
        }
        printf("%lld %lld\n", min, max);
    }
    return 0;
}