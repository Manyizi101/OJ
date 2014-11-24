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

#define MAXN 5000+10

int n,w;
int t[MAXN];
int flag1,flag2;

struct node
{
    int id;
    int t;
} team[MAXN];

bool cmp(node a, node b)
{
    return a.t<b.t;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &team[i].t);
        team[i].id=i+1;
    }
    sort(team, team+n,cmp);
    for(int i=0; i<n; i++)
    {
        if(team[i].t==1)
        {
            flag1=i+1;
        }
        if(team[i].t==2)
        {
            flag2=i+1;
        }
    }
    w=min(n-flag2,min(flag2-flag1,flag1));
    if(w<=0)    printf("0\n");
    else
    {
        printf("%d\n", w);
        for(int i=0; i<w; i++)
        {
            printf("%d %d %d\n", team[i].id, team[i+flag1].id, team[i+flag2].id);
        }
    }
    return 0;
}
