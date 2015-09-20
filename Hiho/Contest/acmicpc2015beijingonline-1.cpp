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

int t;
double k;

int cal(double k)
{
    int cnt = 0 ;
    while(k<1)
    {
        k*=2;
        cnt++;
    }
    if(fabs(k-1)<eps)    return 0;
    return cnt;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf", &k);
        int cnt = cal(0.5-k)-1;
        if(cnt==-1)
            printf("-1\n");
        else
            printf("%d\n", 4*cnt);
    }
}
