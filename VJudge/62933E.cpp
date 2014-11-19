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

int n,h;
ll dp[36][36];

void init()
{
    for(int i=0; i<=35; i++) dp[0][i]=1;
    for(int i=1; i<=35; i++)
    {
        for(int j=1; j<=35; j++)
        {
            for(int k=0; k<i; k++)
            {
                dp[i][j]+=dp[k][j-1]*dp[i-k-1][j-1];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    scanf("%d%d",&n,&h);
    printf("%I64d\n",dp[n][35]-dp[n][h-1]);
    return 0;
}
