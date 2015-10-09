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

struct node {
    char se;
    int val;
    bool operator<(const &b) const
    {
        if(se==b.se)
            return val<b.val;
        return se<b.se;
    }
    void in()
    {
        getchar();
        scanf("%c%d", &se,&val);
    }
} c[6];

vetcor<node> v;
int t;

int main()
{
    scanf("%d", &t);
    while(t--) {
        memset(num,0,sizeof(num));
        for(int i=0; i<5; ++i) {
            c[i].in();
        }
        sort(c,c+5);
    }
}
