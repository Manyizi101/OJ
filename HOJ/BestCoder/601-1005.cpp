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
using namespace std;
const int maxn = 100005;
const int oo = 0x3fffffff;
int a[maxn];
int lis[maxn], pos[maxn];

int main()
{
    int n, t, flag = 0;
    scanf("%d", &t);
    while (t--)
    {
        memset(lis, 0, sizeof(lis));
        memset(pos, 0, sizeof(pos));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        int top = 0;
        lis[0] = -oo;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > lis[top] && a[i] - lis[top] - 1 >= i - pos[top] - 1)
            {
                lis[++top] = a[i];
                pos[top] = i;
            }
            else
            {
                int l = 0, r = top, tp = -1;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (a[i] - lis[mid] - 1 >= i - pos[mid] - 1)
                    {
                        tp = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                if (tp != -1) lis[tp + 1] = a[i], pos[tp + 1] = i;
            }
        }
        printf("Case #%d:\n", ++flag);
        cout << n - top << endl;
    }
    return 0;
}