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

int n,x;
int c[MAXN];

struct node
{
    int value,id;
}day[MAXN];

bool cmp1(node a, node b)
{
    return a.value>b.value;
}

int main(int argc, char const *argv[])
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(day,0,sizeof(day));
	scanf("%d%d", &n,&x);
	for(int i=1;i<=n;i++)
    {
        scanf("%d", &c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n-i+1;j<=n;j++)
        {
            day[i].value+=(n-j+1)*c[j];
        }
    }
    sort(day+1, day+n+1,cmp1);
    for(int i=n;i>0;i--)
    {
        if(x>=day[i].value)
        {
            printf("%d", i);
            return 0;
        }
    }
	return 0;
}
