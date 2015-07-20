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


const int MAXN = 10 + 10;

ll n, m;
double a[MAXN], b[MAXN];
int num[MAXN];

double arrange(int n)
{
    double tmp = 1;
    for (int i = 1; i <= n; i++)
    {
        tmp *= i;
    }
    return tmp;
}

int main()
{
    while (~scanf("%I64d%I64d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++)    scanf("%I64d", &num[i]);
        for (int i = 0; i <= num[0]; i++)   a[i] = 1.0 / arrange(i);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < MAXN; j++)
            {
                for (int k = 0; k <= num[i] && k + j < MAXN; k++)
                {
                    b[j + k] += a[j] / arrange(k);
                }
            }
            for (int j = 0; j < MAXN; j++)
            {
                a[j] = b[j];
                b[j] = 0;
            }
        }
        printf("%.f\n", a[m] * arrange(m));
    }
    return 0;
}