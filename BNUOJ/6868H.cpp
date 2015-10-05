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
using namespace std;
const int N = 310;
const int INF = 0x3f3f3f3f;
int n;
int op[N][2];
char t[5];
struct node
{
    int val,time;
    node (int vv ,int tt ): val(vv) , time(tt) {}
};
stack<node> s[5];
int gao(int num)
{
    for(int i = 0; i<3; i++)
    {
        while(!s[i].empty()) s[i].pop();
    }
    for(int i = num; i>0; i--)
    {
        s[0].push(node(i,-3));
    }
    int t = 0, i = 0,from,to;
    while(1)
    {
        for(int k = 1; k<3; k++) if(s[k].size()==num) return t ;
        for(int i = 0; i<6; i++)
        {
            from  = op[i][0];
            to = op[i][1];
            if(s[from].size())
            {
                node cur = s[from].top();
                if(cur.time+1<t && (s[to].size()==0 || cur.val < s[to].top().val) )
                {
                    node next = cur;
                    next.time = t ;
                    s[from].pop();
                    s[to].push(next);
                    t++;
                    break;
                }

            }
        }

    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i<6; i++)
        {
            scanf("%s",t);
            op[i][0] = t[0] - 'A';
            op[i][1] = t[1] - 'A';
            // cout<<op[i][0]<<"  "<<op[i][1]<<endl;
        }
        int f1 = 1;
        int f2= gao(2);
        int f3 = gao(3);
        int a = (f3-f2)/(f2-f1);
        int b = f2 - a*f1;
        long long  ans = f1;
        for(int i=2;i<=n;++i)
        {
            ans = a*ans + b;
        }
        cout<<ans<<endl;
    }
}
