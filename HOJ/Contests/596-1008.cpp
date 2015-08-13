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
int ss,hh,mm;
int s1,s2,h1,h2,m1,m2,s,h,m;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d:%d:%d", &hh,&mm,&ss);
        s = ss*6*3600;
        m = mm*6 *3600 + s /60;
        h= hh*30*3600+mm/12+ss/120;

    }
}

