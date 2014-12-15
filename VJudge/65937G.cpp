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

#define MAXN 10000+10

int t,n,m,l,r;
int a[MAXN];
char com;

int solve(int l, int r)
{
    int len=1;
    for(int i=l;i<=r-1;i++)
    {
        int tmp=1;
        if(a[i+1]>=a[i])
        {
            tmp++;
        }
        else
        {
            tmp=1;
        }
        len=max(len,tmp);
    }
    return len;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d", &n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        while(m--)
        {
            scanf(" %c%d%d", &com,&l, &r);
            if(com=='Q')
            {
                printf("%d\n",solve(l,r));
            }
            else if(com=='U')
            {
                a[l]=r;
            }
        }
    }
    return 0;
}
