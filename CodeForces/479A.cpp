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

int a,b,c;
int f1,f2;
int ans;

int main()
{
    while(~scanf("%d%d%d", &a,&b,&c)) {
        cout<<max(a+b+c,max(a+b*c, max((a+b)*c,max(a*b+c,max(a*(b+c),a*b*c)))))<<endl;;
    }
}
