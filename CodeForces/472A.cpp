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
        if (ispri[i] == 0) {
            prime[++pcnt] = i;
            for (long long j = i * i; j < NP; j += i)
                ispri[j] = 1;
        }
}

int cnt, f[NP],n;

int main()
{
    getprime();
    for(int i=2; i<NP; ++i) {
        if(ispri[i])    f[cnt++]=i;
    }
    while(~scanf("%d", &n)) {
        for(int i=0; f[i]<=n/2; ++i) {
            int flag = lower_bound(f,f+cnt,n-f[i])-f;
            //cout<<flag<<endl;
            if(f[flag]==n-f[i]) {
                cout<<f[i]<<" "<<n-f[i]<<endl;
                break;
            } else continue;
        }
    }
    return 0;
}
