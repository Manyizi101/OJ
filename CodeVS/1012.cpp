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
#define inf (1<<28)
#define ll long long int
using namespace std;

int x,y;
int ans=0,flag=0;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main(int argc, char const *argv[])
{
    while(~scanf("%d%d", &x,&y))
    {
        if(x>y) swap(x,y);
        ans=0;
        for(int i=x; i<=y; i+=x)
        {
            for(int j=i; j<=y; j+=x)
            {
                if(i*j/x==y&&gcd(i,j)==x)
                {
                    ans++;
                }
            }
        }
        printf("%d\n", ans<<1);
    }
    return 0;
}
