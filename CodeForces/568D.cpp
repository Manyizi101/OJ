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

const int mod = 1e9+7;
ll bell[4010],stir2[4010][4010];

void Bell()
{
    for(int i=1; i<=4008; i++)
    {
        stir2[i][0]=0;
        stir2[i][i]=1;
        for(int j=1; j<i; j++)
            stir2[i][j]=(stir2[i-1][j-1]+j*stir2[i-1][j])%mod;
    }
    for(int i=1; i<=4008; i++)
    {
        bell[i]=0;
        for(int j=0; j<=i; j++)
            bell[i]=(bell[i]+stir2[i][j])%mod;
    }
    return;
}

int n;

int main()
{
    Bell();
    while(~scanf("%d", &n))
    {
        cout<<(bell[n+1]-bell[n]+mod)%mod<<endl;
    }
}





























































