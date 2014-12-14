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

#define MAXN 1000+10

int t, n, k;
double cost[MAXN][MAXN];
double mincost[MAXN];
bool used[MAXN];
int stx,sty;

double prim()
{
    for(int i=0; i<n; ++i)
    {
        mincost[i]=inf;
        used[i]=false;
    }
    mincost[0]=0;
    double res=0;

    while(true)
    {
        int v=-1;

        for(int u=0; u<n; u++)
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))
                v=u;

        if(v==-1)   break;
        used[v]=true;
        res+=mincost[v];

        for(int u=0; u<n; u++)
            mincost[u]=min(mincost[u],cost[v][u]);

            cout<<res<<endl;
    }
    return res;
}

double dis(int x, int y)
{
    return sqrt((double)(x-stx)*(x-stx)+(y-sty)*(y-sty));
}

void init()
{
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        if(i==0)
        {
            stx=x;
            sty=y;
        }
        cost[x][y]=cost[y][x]=dis(x,y);

    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        printf("%.2f\n", k*1.0*prim());
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%f ", cost[i][j]);
            }
            cout<<endl;
        }
        **/
    }
    return 0;
}
