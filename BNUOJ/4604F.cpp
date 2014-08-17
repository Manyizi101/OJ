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


typedef double db;
int n;
db l, v, vt, t;

int main()
{
    while (~scanf("%d%lf%lf", &n, &l, &v))
    {
        vt = v * sin(pi / n * 1.0);
        t = l / 2.0 / sin(pi / n * 1.0) / vt;
        printf("%.4lf %.4lf\n", t, t * v);
    }
    return 0;
}