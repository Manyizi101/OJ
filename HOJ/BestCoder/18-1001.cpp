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

#define MAXN 10000+10

int n,p1,p2,p3;
bool p[MAXN];
int ans;

bool isPrime(int x)
{
    for(int tmp=2;tmp<=int(sqrt(x));tmp++)
    {
        if(x%tmp==0)    return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    memset(p,false,sizeof(p));
    for(int i=2;i<=MAXN;i++)
    {
        p[i]=isPrime(i);
    }
	while(~scanf("%d", &n))
    {
        ans=0;
        for(p1=2;p1<=n;p1++)
        {
            for(p2=p1;p2<=n;p2++)
            {
                if(p[p1]&&p[p2]&&p[n-p1-p2]&&n-p1-p2>=p2)
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
