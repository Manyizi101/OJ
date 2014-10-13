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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

int n;
int dp[50]={0,1,1};

int Fibonacci(int x)
{
    if (dp[x] != 0)    return dp[x];
    else
    {
        if (x == 1)    return 1;
        else if (x == 2)   return 1;
        else return dp[x]=Fibonacci(x - 1) + Fibonacci(x - 2);
    }
}

int main(int argc, char const *argv[])
{
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    printf("%d", Fibonacci(n));
    return 0;
}