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

int n,bmax,breg;
int t=0;
int tdmg,total;
int j=0;

struct node
{
    int p,d;
    bool used;
} scroll[MAXN];

struct nodeans
{
    int id;
    int t;
} ans[MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n,&bmax,&breg);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &scroll[i].p, &scroll[i].d);
        scroll[i].used=false;
    }
    total=bmax;
    for(t=0; t<3000; t++)
    {
        bmax-=tdmg;
        bmax+=breg;
        bmax=min(bmax,total);
        if(bmax<=0)
            break;
        int tmp=0;
        for(int i=0; i<n; i++)
        {
            if((bmax*1.0/total)<=(scroll[i].p*1.0/100)&&scroll[i].used==false&&scroll[i].d>tmp)
            {
                tmp=scroll[i].d;
            }
        }
        if(tmp>0)
        {
            for(int i=0; i<n; i++)
            {
                if((bmax*1.0/total)<=(scroll[i].p*1.0/100)&&scroll[i].used==false&&scroll[i].d==tmp)
                {
                    scroll[i].used=true;
                    tdmg+=scroll[i].d;
                    ans[j].id=i+1;
                    ans[j++].t=t;
                    break;
                }
            }
        }
    }
    if(t==3000)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("%d %d\n", t, j);
    for(int i=0; i<j; i++)
    {
        printf("%d %d\n", ans[i].t, ans[i].id);
    }
    return 0;
}
