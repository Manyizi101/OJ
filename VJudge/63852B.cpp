/*
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| : |||// \
//                     / _||||| -:- |||||- \
//                       | | \\\ - /// | |
//                     | \_| ''\---/'' | |
//                      \ .-\__ `-` ___/-. /
//                   ___`. .' /--.--\ `. . __
//                ."" '< `.___\_<|>_/___.' >'"".
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  佛祖镇楼                  BUG辟易
//          佛曰:
//                  写字楼里写字间，写字间里程序员；
//                  程序人员写程序，又拿程序换酒钱。
//                  酒醒只在网上坐，酒醉还来网下眠；
//                  酒醉酒醒日复日，网上网下年复年。
//                  但愿老死电脑间，不愿鞠躬老板前；
//                  奔驰宝马贵者趣，公交自行程序员。
//                  别人笑我忒疯癫，我笑自己命太贱；
//                  不见满街漂亮妹，哪个归得程序员？
*/
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

#define MAXN 100000*4+10

const ll maxd = 1E13;
int v[MAXN],w[MAXN],next[MAXN],pre[MAXN],res[MAXN];
int first[MAXN],inq[MAXN],e;
ll d[MAXN];
int m,n;
int x,y,z;


void addeage(int x,int y,int z)
{
    v[e]=y;
    w[e]=z;
    next[e]=first[x];
    first[x]=e;
    e++;
}

void spfa(int s)
{
    queue<int> q;
    for(int i =0; i<MAXN; i++)
        d[i]=maxd;
    d[s]=0;
    inq[s]=1;
    q.push(s);
    while(q.empty()==false)
    {
        int u = q.front();
        q.pop();
        inq[u]=0;
        for(int i =first[u]; i!=-1; i=next[i])
        {
            if(d[v[i]]>d[u]+w[i])
            {
                d[v[i]]=(d[u]+w[i]);
                pre[v[i]]=u;
                if(inq[v[i]]==0)
                {
                    q.push(v[i]);
                    inq[v[i]]=1;
                }
            }
        }
    }
}

void init()
{
    for(int i=0; i<MAXN; i++)
    {
        first[i]=-1;
    }
    e=0;
    scanf("%d%d",&m,&n);
    while(n--)
    {
        scanf("%d%d%d",&x,&y,&z);
        addeage(x,y,z);
        addeage(y,x,z);
    }
}


int main(int argc, char const *argv[])
{
    init();
    spfa(1);
    if(d[m]==maxd)
        printf("-1");
    else
    {
        int now=m;
        int cnt=0;
        while(now!=1)
        {
            res[cnt++] = now;
            now = pre[now];
        }
        res[cnt++] = 1;
        for(int i = cnt-1; i >= 0; i--)
            printf("%d ",res[i]);
    }
    return 0;
}
