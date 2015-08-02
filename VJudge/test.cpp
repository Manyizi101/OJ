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

int a[] = {0, 1, 2, 5, 10, 21, 42, 85, 170, 341, 682, 1365, 2730, 5461, 10922, 21845, 43690, 87381, 174762, 349525, 699050, 1398101, 2796202, 5592405, 11184810, 22369621, 44739242, 89478485, 178956970, 357913941, 715827882, 1431655765};

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (m > a[min(30, n)]) printf("%d\n", a[min(30, n)]);
        else if (a[min(30, n)] == m)   printf("%d\n", 0);
        else
        {
            for (int i = min(30, n); i >= 1; i -= 2)
            {
                if (a[i] < m)
                {
                    printf("%d\n", a[i]);
                    break;
                }
            }
        }
    }
    return 0;
}