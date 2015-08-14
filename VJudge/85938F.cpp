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

string line;
map<ll, int> base;
int sum;

void dfs(int depth, int s, int e)
{
    if(line[s]=='[')
    {
        int p = 0;
        for(int i=s+1; i!=e; ++i)
        {
            if(line[i]=='[')    ++p;
            if(line[i]==']')    --p;
            if(p==0&&line[i]==',')
            {
                dfs(depth+1,s+1,i-1);
                dfs(depth+1,i+1,e-1);
            }
        }
    }
    else
    {
        ll w=0;
        for(int i=s; i<=e; ++i)
        {
            w=w*10+line[i]-'0';
            ++sum,++base[w<<depth];
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>line;
        base.clear();
        sum=0;
        dfs(0,0,line.size()-1);
        int maxn =0 ;
        for(auto it = base.begin(); it!=base.end(); ++it)
        {
            maxn = max(maxn, it->second);
        }
        cout<<sum-maxn<<endl;
    }
}

