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

#define MAXN 200+10

int k,a,b,len;
char str[MAXN];
int num[MAXN];
int tmp,flag=0,cnt=0;

int main(int argc, char const *argv[])
{
    memset(num,0,sizeof(num));
    scanf("%d%d%d", &k, &a, &b);
    scanf("%s", str);
    len=strlen(str);
    if(len<k*a||len>k*b)
    {
        printf("No solution");
        return 0;
    }
    else
    {
        for(int i=0;i<k;i++)
        {
            num[i]=a;
        }
        tmp=len-k*a;
        while(tmp)
        {
            num[flag%k]++;
            flag++;
            tmp--;
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<num[i];j++)
            {
                printf("%c", str[j+cnt]);
            }
            printf("\n");
            cnt+=num[i];
        }
    }
    return 0;
}
