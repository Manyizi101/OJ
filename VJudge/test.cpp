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

ll a[61];


int main()
{
    double x = (1 + sqrt(5)) / 2;
    freopen("test.out", "w", stdout);
    printf("{");
    for (int i = 1; i <= 60; ++i)
    {
        a[i] = floor(x * pow(1.5, i));
        printf("%I64d,", a[i]);
    }
    printf("}");
    return 0;
}