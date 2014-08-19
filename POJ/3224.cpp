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

int main(int argc, char const *argv[])
{
    int n;
    int max, maxi, sum, tmp;
    int i, j;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 1, max = -1; i <= n; i++)
        {
            for (j = 1, sum = 0; j <= n; j++)
            {
                scanf("%d", &tmp);
                if (tmp == 3)
                {
                    sum ++;
                }
            }
            if (sum > max)
            {
                max = sum;
                maxi = i;
            }
        }
        printf("%d\n", maxi);
    }
    return 0;
}
