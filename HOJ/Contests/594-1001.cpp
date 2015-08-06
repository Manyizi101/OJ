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

const int maxn = 1e5 + 10;

int n, t;
ll a[maxn], sum, b[maxn];
int flag = 0;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        flag = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%I64d", &a[i]);
            sum += a[i];
        }

        if (sum % n == 0)    flag = 0;
        else
        {
            ll divide = sum / n;
            for (int i = 0; i < n; ++i)
            {
                b[i] = a[i] - divide;
            }
            for(int i=0;i<n;++i)
            {
                if(min(b[i]-b)
            }
        }
    }
    return 0;
}