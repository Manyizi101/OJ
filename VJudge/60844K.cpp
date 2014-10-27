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
#define eps (1e-6)
#define inf (1<<28)
#define ll long long int
using namespace std;

long long int t,n,s1,s2,v1,v2;
double x1,x2;
long long int ans;
int flag=0;

int main(int argc, char const *argv[])
{
    scanf("%lld", &t);
    while(t--)
    {
        ans=0;
        scanf("%lld%lld%lld%lld%lld", &n, &s1, &v1, &s2, &v2);
        x1=v1*1.0/s1;
        x2=v2*1.0/s2;
        if(x1>x2)
        {
            ans+=v1*(n/s1);
            n-=s1*(n/s1);
            ans+=v2*(n/s2);
        }
        else if (fabs(x1-x2)<eps)
        {
            if(s1<s2)
            {
                ans+=v1*(n/s1);
                n-=s1*(n/s1);
                ans+=v2*(n/s2);
            }
            else
            {
                ans+=v2*(n/s2);
                n-=s2*(n/s2);
                ans+=v1*(n/s1);
            }
        }
        else
        {
            ans+=v2*(n/s2);
            n-=s2*(n/s2);
            ans+=v1*(n/s1);
        }
        if(t!=0)
            printf("Case #%d: %lld\n", ++flag,ans);
        else
            printf("Case #%d: %lld", ++flag,ans);
    }
    return 0;
}
