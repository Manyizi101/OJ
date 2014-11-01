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

#define MAXN 1001

long long n,i,j,f[MAXN];

int main(int argc, char const *argv[])
{
    cin>>n;
    f[1]=1;
    for(i=2; i<=n; i++)
    {
        f[i]=1;
        for(j=1; j<=i/2; j++)
            f[i]+=f[j];
    }
    cout<<f[n]<<endl;
    return 0;
}
