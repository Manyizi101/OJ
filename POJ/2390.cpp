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
#define inf (1<<30)
using namespace std;

int main(void)
{
    int r, m, y;
    int i;
    double value, rate;
    while (scanf("%d%d%d", &r, &m , &y) != EOF)
    {
        rate = 1 + (double)r / 100.0;
        value = m;
        for (i = 0; i < y; i++)
        {
            value *= rate;
        }
        printf("%d\n", (int)value);
    }
    return 0;
}