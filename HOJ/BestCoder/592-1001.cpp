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

const int MAXN = 1000000 + 10;
int t, n;
int a[MAXN];
int ap[MAXN];
double gp[MAXN];
int ansa, ansg;
int dpa, dpg;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(ap, 0, sizeof(ap));
        memset(gp, 0, sizeof(gp));
        ansa = ansg = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)    scanf("%d", &a[i]);
        for (int i = 1; i < n; i++)
        {
            ap[i] = a[i] - a[i - 1];
            gp[i] = a[i] / (a[i - 1] * 1.0);
        }
        ap[0] = ap[1], ap[n] = a[n - 1];
        gp[0] = ap[1], gp[n] = a[n - 1];
        int tmpa = 0, tmpg = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ap[i] == ap[i - 1])  tmpa++;
            else
            {
                tmpa = 0;
            }
            if (gp[i] == gp[i - 1])  tmpg++;
            else
            {
                tmpg = 0;
            }
            ansa = max(tmpa, ansa);
            ansg = max(tmpg, ansg);

        }
        printf("%d\n", max(ansg, ansa) + 1);
    }
    return 0;
}