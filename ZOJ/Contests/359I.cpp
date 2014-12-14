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

int t,n,ans;
char a[MAXN][MAXN];


struct node
{
    int id,num;
    char c;
}tmp[4];

bool cmp(node a, node b)
{
    return a.c>b.c;
}

bool cmp1(node a. node b)
{
    return a.num>b.num;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
    {
        for(int i=0;i<4;i++)
        {
            tmp[i].id=i;
        }
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s", a[i]+1);
        }
        //左上角
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=n/2;j++)
            {
                int flag=1;
                tmp[0].c=a[i][j];
                tmp[1].c=a[n+1-i][j];
                tmp[2].c=a[n+1-i][n+1-j];
                tmp[3].c=a[i][n+1-j];
                for(int i=0;i<4;i++)
                {
                    tmp[i].num=1;
                }
                sort(tmp,tmp+4,cmp);
                for(int i=1;i<4;i++)
                {
                    if(tmp[i].c!=tmp[i-1].c)
                    {
                        flag++;
                    }
                    else
                    {
                        tmp[i].num=tmp[i-1]+1;
                    }
                }
                sort(tmp,tmp+4,cmp1);
            }
        }
    }
	return 0;
}
