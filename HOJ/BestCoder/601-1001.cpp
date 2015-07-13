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

const int MAXLEN = 100000;
int n, m, L, left, right, mid;
int arr[MAXLEN + 5], pos[MAXLEN + 5];
int t;
int flag = 0;

int binarySearch(int x, int len)
{
    int lef = 1;
    int rig = len;
    int mid;

    while (lef <= rig)
    {
        mid = (lef + rig) >> 1;
        if (x == arr[mid])
            return mid;
        if (x > arr[mid])
            lef = mid + 1;
        else
            rig = mid - 1;
    }
    return lef;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        memset(pos, 0, sizeof(pos));
        scanf("%d", &n);
        L = 0;
        n--;
        scanf("%d", &arr[++L]);
        pos[1] = 1;
        for (int i = 2; i <= n + 1; ++i)
        {
            scanf("%d", &m);
            if (m < i)
                continue;
            int t = binarySearch(m, L);
            if (m - arr[t - 1] >= i - pos[t - 1])
            {
                arr[t] = m;
                pos[t] = i;
                if (t > L)
                {
                    L = t;
                }
            }
            else
            {
                arr[t - 1] = m;
                pos[t - 1] = i;
            }
        }
        printf("Case #%d:\n", ++flag);
        printf("%d\n", n - L + 1);
    }
}