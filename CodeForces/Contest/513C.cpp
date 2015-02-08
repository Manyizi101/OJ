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

#define MAXN 5+10

int n;
int l[MAXN], r[MAXN];
int Minl = 10001, Maxr = 0;
int sum = 1;
int ans = 0;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        Minl = min(l[i], Minl);
        Maxr = max(r[i], Maxr);
        sum *= (r[i] - l[i]) + 1;
    }
    for (int i = Minl; i <= Maxr; i++)
    {
        int tmp = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i <= l[j])
            {
                tmp *= 1;
            }
            else if (i >= r[j])
            {
                tmp *= 1;
            }
            else
            {
                tmp *= (i - l[j]) * (r[j] - i);
            }
        }
        if (tmp != 1)
            ans += tmp * i;
    }
    printf("%.8f\n", (double)ans / (double)sum);
    return 0;
}