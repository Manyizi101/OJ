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

#define MAXN 300+10

double ax,bx,ay,by;
int n;
double a[MAXN],b[MAXN],c[MAXN];
double mix,mxx,miy,mxy;

int main(int argc, char const *argv[])
{
    scanf("%lf%lf%lf%lf", &ax,&ay,&bx,&by);
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
    }
    mix=min(ax,bx),miy=min(ay,by),mxx=max(ax,bx),mxy=max(ay,by);
    int cnt1=0,cnt2=0;
    for(int i=0; i<n; i++)
    {
        double ans = -(a[i]*ax+c[i])/b[i];
        if(ans>=miy&& ans<=mxy) cnt1++;
        ans=-(b[i]*by+c[i])/a[i];
        if(ans>=mix && ans<=mxx) cnt1++;
    }

    for(int i=0; i<n; i++)
    {
        double ans = -(a[i]*bx+c[i])/b[i];
        if(ans>=miy&& ans<=mxy) cnt2++;
        ans=-(b[i]*ay+c[i])/a[i];
        if(ans>=mix && ans<=mxx) cnt2++;
    }
    cout<<min(cnt1,cnt2);
    return 0;
}
