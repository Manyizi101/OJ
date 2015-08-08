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
ll a[100]= {0,1};

double phi = (1+sqrt(5))/2;

int main()
{
    a[1]=1;
    for(int i=2; i<=60; ++i)
    {
        a[i]=floor(phi*pow(1.5,i-1));
    }
    while(~scanf("%d", &n))
    {
        printf("%I64d\n",a[n]);
    }

}
