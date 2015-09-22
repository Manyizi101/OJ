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

const int maxn = 20;

int n;
int a[maxn];

double cal(int a, int b, int c)
{
    double p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    while(~scanf("%d", &n) && n)
    {
        double sum=0;
        for(int i=0; i<n; ++i)    scanf("%d", &a[i]);
        sort(a,a+n,cmp);
        for(int i=0; i<n-2; ++i)
        {
            if(a[i]>=a[i+1]+a[i+2]) continue;
            else
            {
                sum+=cal(a[i],a[i+1],a[i+2]);
                i+=2;
            }
        }
        printf("%.2f\n", sum);
    }
}
