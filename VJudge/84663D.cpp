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

const int MAXN = 1000000000;

int n, t;
char a[MAXN];
int len;
int x[10];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(x, 0, sizeof(x));
        scanf("%d", &n);
        len = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = i;
            while (tmp > 0)
            {
                x[tmp % 10]++;
                tmp /= 10;
            }
        }
        printf("%d", x[0]);
        for (int i = 1; i < 10; i++)   printf(" %d", x[i]);
        printf("\n");
    }
    return 0;
}