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
#define inf (1<<4)
#define ll long long int
using namespace std;

#define MAXN 8+10

int n, m;
int a[MAXN];
int Max = 0;

int main(int argc, char const *argv[])
{
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        a[i] = i ;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            Max += i;
        }
    }
    do
    {
        int tmp = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                int Min = inf;
                for (int k = i; k <= j; k++)
                {
                    Min = min(a[k], Min);
                }
                tmp += Min;
            }
        }
        if (tmp == Max)    m--;
    }
    while (m  && next_permutation(a + 1, a + n + 1));
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}