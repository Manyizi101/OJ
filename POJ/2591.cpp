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

#define SIZE 10000010
#define MIN(a, b) (a < b ? a : b)

long a[SIZE];

int main(int argc, char const *argv[])
{
    long i2, i3;
    i2 = i3 = 1;
    a[1] = 1;
    for (long i = 2; i < SIZE; i++)
    {
        a[i] = MIN(2 * a[i2] + 1, 3 * a[i3] + 1);
        if (a[i] == 2 * a[i2] + 1) i2++;
        if (a[i] == 3 * a[i3] + 1) i3++;
    }
    long t;
    while (EOF != scanf("%ld", &t))
        printf("%ld\n", a[t]);
    return 0;
}