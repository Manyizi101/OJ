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
