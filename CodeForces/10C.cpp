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

const int maxn = 1e6+10;
ll c[maxn],n,ans;

int main()
{
    while(~scanf("%I64d", &n)) {
        for(int i=1; i<=n; ++i)   c[i%9]++;
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                ans += c[(i*j)%9]*c[i]*c[j];
            }
        }
        for(int i=1; i<=n; ++i) {
            ans -= n/i;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
