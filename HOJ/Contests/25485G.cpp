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

#define MAXM  100+10
#define MAXN 500+10

int t,m,n,ans;
int k[MAXM];

struct node
{
    int number;
    int x[MAXN];
}arch[MAXN];

bool cmp(node a, node b)
{
    return a.number<b.number;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
    {
        memset(k,0,sizeof(k));
        ans=0;
        scanf("%d %d", &n,&m);
        for(int i=1;i<n;i++)
        {
            arch[i].number=0;
            memset(arch[i].x,0,sizeof(arch[i].x));
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &arch[i].number);
            for(int j=1;j<=arch[i].number;j++)
            {
                scanf("%d", &arch[i].x[j]);
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d", &k[i]);
        }
        sort(arch+1,arch+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=arch[i].number;j++)
            {
                if(k[arch[i].x[j]]!=0)
                {
                    k[arch[i].x[j]]--;
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}
