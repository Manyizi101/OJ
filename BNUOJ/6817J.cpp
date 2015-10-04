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

const int maxn = 1010;

int n,a[maxn];

bool cmp(int x, int y)
{
    cout<<"1 "<<x<<" "<<y<<endl;
    cout.flush();
    string cmd;
    cin>>cmd;
    return cmd[0]=='Y';
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i) a[i]=i;
        stable_sort(a+1,a+n+1,cmp);
        cout<<"0";
        for(int i=1;i<=n;++i)    cout<<" "<<a[i];
        cout<<endl;
    }
}
