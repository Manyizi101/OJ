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
ll n,fib[50];

void init()
{
    fib[1]=1;
    fib[2]=1;
    for(int i=3; i<=45; ++i)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
}

int main()
{
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d", &n);
        int Mx = 45;
        if(n==0)
        {
            printf("Yes\n");
            continue;
        }
        while(1)
        {
            for(int i=Mx; i>1; --i)
            {
                if(n%fib[i]==0)
                {
                    n/=fib[i];
                    Mx = i;
                    break;
                }
            }
            if(fib[Mx]==1)  break;
        }
        if(n==1)    printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
