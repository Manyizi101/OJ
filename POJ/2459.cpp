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
using namespace std;

int account[2100];

int main(int argc, char const *argv[])
{
    int c, f1, f2, d;
    int day1, day2;
    int i, j, result, tmp;

    while (scanf("%d%d%d%d", &c, &f1, &f2, &d) != EOF)
    {
        memset(account, 0, sizeof(account));
        for (i = 0; i < c; i++)
        {
            scanf("%d%d", &day1, &day2);
            for (j = day1; j <= day2; j++)
            {
                account[j]++;
            }
        }
        tmp = f1 - f2;
        for (i = d; i >= 1 && tmp > 0; i--)
        {
            tmp -= account[i];
        }
        printf("%d\n", i + 1);
    }
    return 0;
}
