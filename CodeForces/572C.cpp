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

int a,b,c,l;
ll ans;

bool judge(int a, int b, int c)
{
    if(a+b>c&&a+c>b&&b+c>a) return true;
    else return false;
}

int main()
{
    while(~scanf("%d%d%d%d", &a,&b,&c,&l))
    {
        ans=0;
        for(int i = a ; i<=a+l; ++i)
        {
            for(int j = b; i+j<=a+b+l; ++j)
            {
                int z = a+b+c+l-i-j;
                for(int k = c; k<=z; ++k)
                {
                    if(judge(i,j,k))    ans++;
                }
            }
        }
        printf("%I64d\n", ans);
    }
}
