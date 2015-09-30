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

int n;
char a[maxn];
int x;

bool judge()
{
    for(int i=0;i<n;++i)
    {
        if(a[i]!=a[n-i-1])  return false;
    }
    return true;
}

int main()
{
    while(~scanf("%d", &n))
    {
        x=-1;
        scanf("%s", a);
        for(int i=0;i<n;++i)
        {
            if(a[i]=='?')
            {
                if(!(n&1)||i!=n/2)
                    x=i;
                a[i]='a';
            }
        }
        if(judge())
        {
            if(((n&1)&&(x==n/2))||x==-1)
            {
                puts("QwQ");
            }
            else
            {
                a[x]++;
                puts(a);
            }
        }
        else
        {
            puts(a);
        }
    }
}
