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

int t,n;

int cal(int n)
{
    if(n==4)    return 2;
    if(n<NP)
    {
        if(ispri[n])    return 0;
        else    return n-1;
    }
    else
    {
        int flag = 1;
        for(int i=1;prime[i]*prime[i]<=n;++i)
        {
            if(n%prime[i]==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)    return n-1;
        else return 0;
    }
}

int main()
{
    getprime();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n",cal(n));
    }
}
