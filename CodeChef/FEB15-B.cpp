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
#define ll long long int
using namespace std;

#define MAXN 100000+10

int t, n;
int a[MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        int tmp = 0, Max = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])    tmp++;
            if (a[i] > a[i - 1])	tmp = 0;
            Max = max(Max, tmp);
        }
        cout << n - Max - 1 << endl;
    }
    return 0;
}
