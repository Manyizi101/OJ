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

int n;

int main()
{
    while(~scanf("%d", &n))
    {
        if(n-15>0)  printf("%d ", n-15);
        if(n-7>0)   printf("%d ",n-7);
        if(n-4>0)   printf("%d ", n-4);
        if(n-2>0)   printf("%d ",n-2);
        if(n-1>0)   printf("%d\n",n-1);
    }
}
