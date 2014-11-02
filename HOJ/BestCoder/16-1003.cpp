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

#define MAXN 1000+10

int t,n;
ll a[MAXN];
ll ans;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;i++)    scanf("%I64d", &a[i]);
        ans=a[0];
        for(int i=1;i<n;i++)
        {
            ans^=a[i];
        }
        if(ans!=0) printf("NO\n");
        else printf("YES\n");
    }
	return 0;
}
