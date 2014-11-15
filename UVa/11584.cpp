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

#define MAXN 1000+10

char str[MAXN];
int dp[MAXN];
int t;

bool isPalind(int l, int r)
{
    while(l<r)
    {
        if(str[l] != str[r]) return false;
        ++l;
        --r;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str+1);
        int len = strlen(str+1);
        memset(dp, 0, sizeof(int)*len);
        for(int i=1; i<=len; ++i)
        {
            dp[i] = i+1;
            for(int j=1; j<=i; ++j)
            {
                if(isPalind(j, i))
                {
                    dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
        printf("%d\n", dp[len]);
    }
    return 0;
}
