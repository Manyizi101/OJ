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

int n,m;

int main()
{
while(~scanf("%d%d", &n,&m))
{
    int Min = inf;
    int a,b;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d", &a,&b);
        Min = min((n+a-1)/a*b,Min);
    }
    printf("%d\n",Min);
}
}
