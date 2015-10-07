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

int t,n;
bitset<maxn> a;
int x,y;

int main()
{
    scanf("%d", &t);
    while(t--) {
        a.reset();
        scanf("%d", &n);
        for(int i=0; i<n; ++i) {
            scanf("%d%d", &x,&y);
            a[x]=(y&1);
        }
        cout<<a.to_ulong()-2*(a>>1).to_ulong()<<endl;
    }
}
