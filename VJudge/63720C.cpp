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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 1000+10

int a[MAXN],b[MAXN];
int n,i,j,x;

void init()
{
    scanf("%d%d",&n,&x);
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]>b[i])
        {
            j=a[i];
            a[i]=b[i];
            b[i]=j;
        }
    }
    sort(a,a+n);
    sort(b,b+n);
}

int main(int argc, char const *argv[])
{
    init();
    if(a[n-1]<=b[0])
    {
        if(x<a[n-1])
            printf("%d\n",a[n-1]-x);
        else if(x>b[0])
            printf("%d\n",x-b[0]);
        else puts("0");
    }
    else
        puts("-1");
    return 0;
}
