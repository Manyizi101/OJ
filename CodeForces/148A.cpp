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

const int maxn = 1e5+10;
int k,l,m,n,d,ans;

int main()
{
    while(~scanf("%d%d%d%d%d", &k, &l, &m, &n, &d)) {
        ans = 0;
        for(int i=1; i<=d; ++i) {
            if(i%k&&i%l&&i%m&&i%n)  ans++;
        }
        cout<<d-ans<<endl;
    }
    return 0;
}
