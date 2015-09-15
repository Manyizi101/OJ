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

int t,cs=0;
int n,b,q;
bool flag;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        flag = 0;
        scanf("%d%d%d", &n,&b,&q);
        printf("Case #%d: ",++cs);
        if(q==1)
        {
            while(b)
            {
                if(n==b)
                {
                    flag = 1;
                    break;
                }
                b/=10;
            }
            if(flag)
                printf("1.00000\n");
            else
                printf("0.00000\n");
        }
        else if(q==10||q==100||q==1000)
        {
            b*=100000;
            while(b)
            {
                if(n==b)
                {
                    flag = 1;
                    break;
                }
                b/=10;
            }
            if(flag)
                printf("1.00000\n");
            else
                printf("0.00000\n");
        }
        else
        {
            printf("%.5f\n", (log(n+1)-log(n))/log(10.0));
        }
    }
}
