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

int n,d;
int t=0,one,two,temp;

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d",&n,&d))
    {
        t=0;
        scanf("%d",&one);
        for (int i=2; i<=n; i++)
        {
            scanf("%d",&two);
            if (one>two)
            {
                temp=(one-two)/d+1;
                t+=temp;
                two+=temp*d;
            }
            else if (one == two)
                t++,two+=d;
            one=two;
        }
        printf("%d\n",t);
    }
    return 0;
}
