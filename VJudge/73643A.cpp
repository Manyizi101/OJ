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
#define ll long long int
const double pi = acos(-1.0);
const double eps = (1e-8);
const int inf = 1<<31;
using namespace std;

int n, xa, ya, xb, yb, dist;

void init()
{
	scanf("%d%d%d%d%d", &n, &xa, &ya, &xb, &yb);
}

int main(int argc, char const *argv[])
{
    init();
    if(((xa-ya)*(xb-yb)>=0))
        dist = abs(xa+ya-xb-yb);
    else
        dist = xa+xb+ya+yb;
    printf("%d", min(dist, 4*n-dist));
    return 0;
}