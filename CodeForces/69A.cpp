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

int n,x,y,z,a,b,c;

int main()
{
    while(~scanf("%d",&n)) {
        x=y=z=0;
        for(int i=0; i<n; ++i) {
            scanf("%d%d%d", &a,&b,&c);
            x+=a;
            y+=b;
            z+=c;
        }
        //cout<<x<<" "<<y<<" "<<z<<endl;
        if(x||y||z) puts("NO");
        else puts("YES");
    }
}
