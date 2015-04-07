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
int a[5][5],nowx,nowy,mn1,mn2,n,l,ans;
int dirx[20] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3};
int diry[20] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
void init()
{
    memset(a,-1,sizeof(a));
    int cnt = 0,i,j;
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++)
        {
            a[i][j] = ++cnt;

        }
    }
    a[4][2] = 0;
}
bool can(int x,int y)
{
    if(x==4 && y==2) return true;
    if(x>3 || x<1 || y>3 || y<1) return false;
    if(a[x][y]==-1) return false;
    return true;
}
void get_pos(int val)
{
    int i,j;
    if(val==0) nowx = 4,nowy = 2;
    else
    {
        for(i=1; i<=3; i++)
        {
            for(j=1; j<=3; j++)
            {
                if(a[i][j]==val)
                {
                    nowx = i,nowy = j;
                }

            }
        }

    }
}
void gao(int x,int y,int cur,int sum)
{
    if(cur == l)
    {
        if(sum<n)
        {
            if(mn1>n-sum)
            {
                mn1 = n-sum;
            }
        }
        else
        {
            if(mn2>sum-n)
            {
                mn2 = sum-n;
            }
        }
        return ;
    }
    else
    {
        for(int i=0; i<16; i++)
        {
            if(can(x+dirx[i],y+diry[i]))
            {
                gao(x+dirx[i],y+diry[i],cur+1,sum*10+a[x][y]);
            }
        }
    }
    return ;
}
char tmp[5];
int main(int argc, char const *argv[])
{
    freopen("in.txt", "r",stdin);
    freopen("out.txt", "w",stdout);
    init();
    int t;
    cin>>t;
    while(t--)
    {
        memset(tmp,0,sizeof(tmp));
        mn1 = inf,mn2=inf,n = 0;
        cin>>tmp;
        l = strlen(tmp);
        for(int i=0; i<l; i++)
        {
            n = n*10 + tmp[i]-'0';
        }
        int first = tmp[0]-'0';
        get_pos(first);
        if(can(nowx,nowy-1))
        {
            gao(nowx,nowy-1,0,0);
        }
        if(can(nowx-1,nowy))
        {
            gao(nowx-1,nowy,0,0);
        }
        if(can(nowx,nowy))
        {
            gao(nowx,nowy,0,0);
        }
        if(can(nowx+1,nowy))
        {
            gao(nowx+1,nowy,0,0);
        }
        if(can(nowx,nowy+1))
        {
            gao(nowx,nowy+1,0,0);
        }
        //cout<<tmp<<": ";
        if(mn1<mn2) cout<<n-mn1<<endl;
        else cout<<n+mn2<<endl;
        //cout<<ans<<endl;
    }
    return 0;
}
