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

int t,n;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n==0)    puts("1");
        else if(n==1) puts("9");
        else if(n==2) puts("18");
        else if(n==3) puts("54");
        else if(n==4) puts("90");
        else if(n==5) puts("174");
        else puts("258");
    }
}





























































