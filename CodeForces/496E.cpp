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

#define MAXN 100000+10

int n,m;
int ans[MAXN];
int mark[MAXN];
bool flag=true;

struct nodea
{
    int a,b;
    bool used;
}song[MAXN];

struct nodeb
{
    int c,d,k,id;
}singer[MAXN];

bool cmpa(nodea a, nodea b)
{
    if(a.a==b.a)    return a.b<b.b;
    else    return a.a<b.a;
}

bool cmpb(nodeb a, nodeb b)
{
    if(a.c==b.c)    return a.d<b.d;
    else    return a.c<b.c;
}


int main(int argc, char const *argv[])
{
    memset(ans,0,sizeof(ans));
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &song[i].a,&song[i].b);
        song[i].used=false;
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d", &singer[i].c,&singer[i].d,&singer[i].k);
        singer[i].id=i;
    }
    sort(song+1,song+n+1,cmpa);
    sort(singer+1,singer+m+1,cmpb);

    for(int i=1;i<=m;i++)
    {
        while(singer[i].k)
        {
            bool tmp=false;
            for(int j=1;j<=n;j++)
            {
                if(song[j].a>=singer[i].c&&song[j].b<=singer[i].d&&!song[j].used)
                {
                    tmp=true;
                    song[j].used=true;
                    ans[j]=singer[i].id;
                    singer[i].k--;
                }
            }

            if(!tmp)
            {
                flag=false;
                goto AA;
            }

        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)   flag=false;
    }
    AA: if(flag)
    {
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            printf("%d", ans[i]);
            if(i!=n)
            {
                printf(" ");
            }
        }
    }
    else
    {
        printf("NO");
    }
    return 0;
}
