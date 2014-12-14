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
int t,n,m,ans;
char tmp[MAXN];
int flag[6];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        memset(flag, 0, sizeof(flag));
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            memset(tmp,0,sizeof(tmp));
            scanf("%s", tmp);
            int len=strlen(tmp);
            for(int i=0; i<len; i++)
            {
                if(tmp[i]=='I') flag[0]++;
                else if(tmp[i]=='L')    flag[1]++;
                else if(tmp[i]=='O')    flag[2]++;
                else if(tmp[i]=='V')    flag[3]++;
                else if(tmp[i]=='E')    flag[4]++;
                else if(tmp[i]=='U')    flag[5]++;
            }
        }
        ans=inf;
        for(int i=0; i<6; i++)
        {
            ans=min(ans,flag[i]);
        }
        if(ans>=m)
            printf("KK will have a girlfriend!\n");
        else
            printf("KK can only have gay friend~\n");
    }
    return 0;
}
