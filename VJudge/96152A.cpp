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

int t;
int a,b,ans;
int s[4]= {1000,1500,2000,2500};
int cs=1;

int main()
{
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        for(int i=0; i<4; ++i) {
            scanf("%d%d", &a,&b);
            ans += max((int)(s[i]*0.4),(int)((250-a)*s[i]/250-b*50));
        }
        printf("Case #%d: %d\n", cs++, ans);
    }
}
