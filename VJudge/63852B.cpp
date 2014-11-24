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
//                  ������¥                  BUG����
//          ��Ի:
//                  д��¥��д�ּ䣬д�ּ������Ա��
//                  ������Աд�������ó��򻻾�Ǯ��
//                  ����ֻ���������������������ߣ�
//                  ��������ո��գ����������긴�ꡣ
//                  ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
//                  ���۱������Ȥ���������г���Ա��
//                  ����Ц��߯��񲣬��Ц�Լ���̫����
//                  ��������Ư���ã��ĸ���ó���Ա��
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
