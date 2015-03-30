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
const int maxn =1005;
using namespace std;
struct node
{
    int l,r;
} a[maxn],ans[maxn];
bool cmp(node a,node b)
{
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
int sta,ed;
int main(int argc, char const *argv[])
{
    int n,m,i;
    while(cin>>n>>m)
    {
        int cnt = 0;
        for(i=0; i<m; i++)
        {
            cin>>a[i].l>>a[i].r;
        }
        sort(a,a+n,cmp);
        sta = 0,ed = a[0].r;
        for(i=1; i<=n; i++)
        {
            if(ed>=a[i].l)
            {
                ed = a[i].r;
            }
            else
            {
                ans[cnt].l = sta,ans[cnt++].r = ed;
                sta = a[i].l,ed = a[i].r;
            }
        }
        sort(ans,ans+cnt,cmp);
        for(i=0;i<cnt;i++) cout<<ans[i].l<<" "<<ans[i].r<<endl;

        int res = 0,pre = 0;
        bool flag = 0;
        for(i=0; i<cnt; i++)
        {
            if(flag==0)
            {
                res += abs(ans[i].r - pre);
                pre = ans[i].l;
                flag = 1;
            }
            else
            {
                res += abs(ans[i].l-pre);
                pre = ans[i].r;
                flag = 0;
            }
        }
        cout<<res + n+1-pre<<endl;
    }
    return 0;
}
