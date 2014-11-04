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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 100000+10

map<int,int> cnt;
set<int> sames;
bool no[MAXN];
int t,s,n;
int a[MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        memset(no,0,sizeof(no));
        cnt.clear(),sames.clear();
        scanf("%d%d", &s,&n);
        for(int i=0; i<n; ++i)    scanf("%d", a+i);
        int idx=-1;
        for(int i=0; i<min(s,n); ++i)
        {
            if(cnt[a[i]]>0)
            {
                idx=i;
                break;
            }
            cnt[a[i]]++;
        }
        if(idx==-1)
        {
            printf("%d\n", s);
            continue;
        }
        for(int i=idx; i<min(s,n); ++i)
        {
            if(cnt[a[i]]>0) sames.insert(a[i]);
            cnt[a[i]]++;
        }
        for(int i=0; i<n; ++i)
        {
            if(sames.size())    no[i]=1;
            if(i+s<n)
            {
                if(cnt[a[i+s]]>0)   sames.insert(a[i+s]);
                cnt[a[i+s]]++;
            }
            if(cnt[a[i]]==2)    sames.erase(a[i]);
            cnt[a[i]]--;
        }
        int ans=0;
        for(int i=0; i<idx; ++i)
        {
            bool can=1;
            for(int j=i+1; j<n; j+=s) can&=!no[j];
            ans+=can;
        }
        printf("%d\n",ans);
    }
    return 0;
}
