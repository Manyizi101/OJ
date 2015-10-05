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



char ch[111];
map<string,string> mp;
map<string,int> vis;
char c;
void skip()
{
    while(c==' '||c==','||c=='.'||c=='('||c==')'||c==';'||c==':'||c=='!'||c=='?'||c=='\n')
    {
        c = getchar();
        printf("%c",c);
    }
}
char ans[111];
int cnt = 0;
void get()
{
   // cout<<"---\n";
    cnt = 0;
    ans[cnt++] = c;
    while((c>='a'&&c<='z')||(c>='A'&&c<='Z') || (c>='0'&&c<='9'))
    {
        c =  getchar();
       cout<<ans<<endl;
        ans[cnt++] = c;
    }
    ans[cnt] = 0;
}
int main()
{
    c = getchar();
    cout<<c<<endl;
    while(1)
    {
        get();
        skip();
         string tmp;
         //cout<<">>>>\n";
        if(ans[1]>='0'&&ans[1]<='9')
        {
             tmp = ans;
            if(mp.find(tmp)!=mp.end())
                cout<<mp[tmp];
        }
        else
        {
           // printf("%s",ans);
            tmp = ans;
            if(vis[tmp]==0)
            {
                vis[tmp] = 1;
                string tmp1;
                tmp1 += ans[0];
                tmp1+=  cnt-2+'0';
                tmp1+=ans[cnt-1];
                mp[tmp1] = tmp;
            }
        }
    }
    return 0;
}
