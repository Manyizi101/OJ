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
    double s, r, h, v;
    while (scanf("%lf", &s) != EOF)
    {
        r = sqrt(s / pi) / 2;
        h = sqrt((s * s) / (pi * pi * r * r) - 2 * s / pi);
        v = pi * r * r * h / 3;
        printf("%.2f\n%.2f\n%.2f\n", v, h, r);
    }
    return 0;
}