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

#define MAXN 50000+10

char s[MAXN];
ll ss;
int cnt;
int a,b;

priority_queue<pair<ll, int> > que;

int main(int argc, char const *argv[])
{
    scanf("%s", s+1);
    ss=0,cnt=0;
    for(int i=1; s[i]; i++)
    {
        if(s[i]=='(')
        {
            cnt++;
        }
        else if(s[i]==')')
        {
            cnt--;
        }
        else
        {
            scanf("%d%d", &a,&b);
            ss+=b;
            cnt--;
            s[i]=')';
            que.push(pair<ll,int> (b-a,i));
        }
        if(cnt<0)
        {
            if(que.empty()) break;
            pair<ll,int> f = que.top();
            que.pop();
            ss-=f.first;
            cnt+=2;
            s[f.second]='(';
        }
    }
    if(cnt!=0)
        printf("-1\n");
    else
        printf("%lld\n%s\n", ss,s+1);
    return 0;
}
