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

int n;
int a[MAXN];
int a1, a2, a3, a4;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    a1 = a2 = a3 = a4 = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        switch (a[i])
        {
        case 1: a1++; break;
        case 2: a2++; break;
        case 3: a3++; break;
        case 4: a4++; break;
        }
    }
    int ans = a4;
    ans += a3;
    a1 >= a3 ? a1 -= a3 : a1 = 0;
    ans += a2 / 2;
    a2 % 2 == 0 ? a2 = 0 : a2 = 1;
    if (a2 == 1)
    {
        if (a1 <= 2)
        {
            ans++;
            a1 -= 2;
        }
        else
        {
            ans++;
            a1 -= 2;
            ans += a1 / 4;
            a1 % 4 == 0 ? ans : ans++;
        }
    }
    else
    {
        ans += a1 / 4;
        a1 % 4 == 0 ? ans : ans++;
    }
    cout << ans;
    return 0;
}
