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

const int MAXN = 1000 + 10;

int a, b, b1, b2, n;
int answer[MAXN], user[MAXN];
int flag = 0;

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n && n)
    {
        printf("Game %d:\n", ++flag);
        for (int i = 0; i < n; i++) scanf("%d", &answer[i]);
        while (1)
        {
            a = b = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &user[i]);
                if (answer[i] == user[i])  a++;
            }
            if (user[0] == 0)  break;
            for (int d = 1; d <= 9; d++)
            {
                b1 = b2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (answer[i] == d)    b1++;
                    if (user[i] == d)  b2++;
                }
                b += min(b1, b2);
            }
            printf("    (%d,%d)\n", a, b - a);
        }
    }
    return 0;
}