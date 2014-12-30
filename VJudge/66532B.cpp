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

char a[MAXN];
int n;
bool flag1=0,flag2=0;
int j=0;
stack<char> que;

int main(int argc, char const *argv[])
{
	scanf("%s", a);
	n=strlen(a);
	que.push(a[0]);
	for(int i=1;i<n;i++)
    {
        que.push(a[i]);
        if(i>=2&&!flag1)
        {
            char tmp1=que.top();
            que.pop();
            char tmp2=que.top();
            if(tmp1=='t'&&tmp2=='a')
            {
                que.pop();
                que.push('@');
                flag1=true;
            }
            else
            {
                que.push(tmp1);
            }
        }
        if(i>=3&&i<=n-2)
        {
            char tmp1=que.top();
            que.pop();
            char tmp2=que.top();
            que.pop();
            char tmp3=que.top();
            if(tmp3=='d'&&tmp2=='o'&&tmp1=='t')
            {
                que.pop();
                que.push('.');
            }
            else
            {
                que.push(tmp2);
                que.push(tmp1);
            }
        }
    }
    while(!que.empty())
    {
        a[j++]=que.top();
        que.pop();
    }
    for(int i=j-1;i>=0;i--)
    {
        cout<<a[i];
    }
	return 0;
}
