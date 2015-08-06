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
int flag = 1;
int anss;

struct node
{
    int st, ed;
} ans[maxn];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        anss = 0;
        flag = 1;
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%I64d", &a[i]);
            sum += a[i];
        }
        if (sum % n != 0)    flag = 0;
        else
        {
            ll divide = sum / n;
            for (int i = 1; i <= n; ++i)        b[i] = a[i] - divide;
            if (abs(b[1]) > 2)
            {
                flag = 0;
                continue;
            }
            if (b[1] > 0)
            {
                if (b[2] < b[n])
                {
                    b[2]++;
                    b[1]--;
                    ans[anss].st = 1;
                    ans[anss++].ed = 2;
                }
                else
                {
                    b[n]++;
                    b[1]--;
                    ans[anss].st = 1;
                    ans[anss++].ed = n;
                }
            }
            else
            {
                if (b[2] > b[n])
                {
                    b[2]--;
                    b[1]++;
                    ans[anss].st = 2;
                    ans[anss++].ed = 1;
                }
                else
                {
                    b[n]--;
                    b[1]++;
                    ans[anss].st = n;
                    ans[anss++].ed = 1;
                }
            }
            for (int i = 2; i < n ; ++i)
            {
                if (abs(b[i]) > 2)
                {
                    flag = 0;
                    break;
                }
                if (b[i] > 0)
                {
                    b[i + 1]++, b[i]--;
                    ans[anss].st = i;
                    ans[anss++].ed = i + 1;
                }
                else if (b[i] < 0)
                {
                    b[i + 1]--, b[i]++;
                    ans[anss].st = i + 1;
                    ans[anss++].ed = i;
                }
            }
        }
        if (flag == 0)     printf("NO\n");
        else
        {
            printf("YES\n");
            printf("%d\n", anss);
            for (int i = 0; i < anss; ++i)
            {
                printf("%d %d\n", ans[i].st, ans[i].ed);
            }
        }
    }
    return 0;
}