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

#define MAXN 500000+10

int c[MAXN],n,cnt;
int i,j,ans;

struct node
{
    int b,i,r;
    int id;
} lady[MAXN];

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int d)
{
    while(x>0)
    {
        if(c[x]<d)
            c[x]=d;
        x-=lowbit(x);
    }
}

int getmax(int x)
{
    int s=-1;
    for(int i=x; i<=cnt; i+=lowbit(i))
    {
        if(s<c[i])
            s=c[i];
    }
    return s;
}

bool cmp(node a,node b)
{
    return a.b<b.b;
}

bool cmp1(node a,node b)
{
    return a.i>b.i;
}

void init()
{
    ans=0;
    for(i=0; i<n; i++)
        scanf("%d",&lady[i].b);
    for(i=0; i<n; i++)
        scanf("%d",&lady[i].i);
    for(i=0; i<n; i++)
        scanf("%d",&lady[i].r);
    sort(lady,lady+n,cmp);
    cnt=1;
    lady[0].id=1;
}

int main(int argc, char const *argv[])
{

    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(i=1; i<n; i++)
        {
            if(lady[i].b==lady[i-1].b)
                lady[i].id=cnt;
            else
                lady[i].id=++cnt;
        };
        sort(lady,lady+n,cmp1);
        for(i=1; i<=cnt; i++)
            c[i]=-1;
        for(i=0; i<n;)
        {
            for(j=i; j<n&&lady[i].i==lady[j].i; j++)
            {
                if(getmax(lady[j].id+1)>lady[j].r)
                {
                    ans++;
                }
            }
            for(j=i; j<n&&lady[i].i==lady[j].i; j++)
            {
                add(lady[j].id,lady[j].r);
            }
            i=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
