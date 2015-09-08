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

const int maxn = 1000+10;

int t,n;
double k[maxn],c[maxn];
double ans=0;
int cs=0;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans=0;
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%lf", &k[i]);
            ans+=k[i];
        }
        for(int i=0; i<n; ++i)
        {
            scanf("%lf", &c[i]);
        }
        printf("Case #%d: ", ++cs);
        printf("%.6f\n", (n+1)/ans);
    }
}
