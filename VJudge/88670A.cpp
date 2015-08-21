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

const int NP = 1000005;
int ispri[NP] = {}, prime[NP], pcnt = 0;

void getprime()
{
    ispri[0] = ispri[1] = 1;
    for (long long i = 2; i < NP; i++)
        if (ispri[i] == 0)
        {
            prime[++pcnt] = i;
            for (long long j = i * i; j < NP; j += i)
                ispri[j] = 1;
        }
}

ll a;

int main()
{
    getprime();
    while(~scanf("%I64d", &a))
    {
        if(a==1)    printf("0\n");
        else
        {
            ll ans=a;
            for(int i=1;prime[i]*prime[i]<=ans;++i)
            {
                while(a%prime[i]==0&&a!=prime[i])   a/=prime[i];
            }
            if(ans==a)  printf("1\n");
            else    printf("%I64d\n",ans/a);
        }
    }
}
