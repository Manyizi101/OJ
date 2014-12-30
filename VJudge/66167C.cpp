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

#define MAXN 100+10

int n, ans = 0;;

struct node
{
    double x1, x2, y1, y2;
    double m, n;
} cube[MAXN];

bool judge(node a, node b)
{
    if(((a.m > b.x1 && a.m < b.x2)||(a.m > b.x2 && a.m < b.x1)) && ((a.n > b.y1 && a.n < b.y2)||(a.n > b.y2 && a.n < b.y1))) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <=n; i++)
    {
        scanf("%lf%lf%lf%lf", &cube[i].x1, &cube[i].y1, &cube[i].x2, &cube[i].y2);
        cube[i].m = (cube[i].x1 + cube[i].x2) / 2;
        cube[i].n = (cube[i].y1 + cube[i].y2) / 2;
    }
    ans=1;
    for (int i = 2; i <= n; i++)
    {
        node tmp;
        tmp.x1=tmp.x2=tmp.y1=tmp.y2=0;
        for(int j=1; j<i; j++)
        {
            tmp.x1+=cube[i].x1;
            tmp.x2+=cube[i].x2;
            tmp.y1+=cube[i].y1;
            tmp.y2+=cube[i].y2;
        }
        tmp.x1/=i-1;
        tmp.x2/=i-1;
        tmp.y1/=i-1;
        tmp.y2/=i-1;
        if (judge(cube[i], tmp))    ans++;
    }
    cout<<ans;
    return 0;
}
