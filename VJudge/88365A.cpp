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

int t,n,k;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n,&k);
        if(k>n) printf("0\n");
        else
        {
            if(!(n%k))
                printf("%d\n", n*n);
            else
            {
                int ans1 = n*n-(k-n%k)*(k-n%k);
                int ans2 = n*n-(n%k)*(n%k);
                printf("%d\n", max(ans1,ans2));
            }
        }
    }
}

