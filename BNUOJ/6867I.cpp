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

int m,n,M,N;

int cal(int x, int y)
{
    int ans = 0;
    ans = (M/x)*(N/y);
    if(M%x)
    {
        ans += (N/y)/(x/(M%x));
        if((N/y)%(x/(M%x))) ans++;
    }
    if(N%y)
    {
        ans += (M/x)/(y/(N%y));
        if((M/x)%(y/(N%y))) ans++;
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d%d%d", &M,&N,&m,&n))
    {
        if(M>N) swap(M,N);
        printf("%d\n", min(cal(m,n),cal(n,m)));
    }
}
