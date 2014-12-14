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


string s;
int sa[3],a[3];
int month[2][13]= {{0,31,29,31,30,31,30,31,31,30,31,30,31},{0,31,28,31,30,31,30,31,31,30,31,30,31}};


bool check()
{
    if(a[1]>12)
        return false;
    if(month[a[2]%4!=0][a[1]]<a[0])
        return false;
    if(sa[2]-a[2]>18)
        return true;
    else if(sa[2]-a[2]==18)
    {
        if(sa[1]>a[1])
            return true;
        else if(sa[1]==a[1])
        {
            return sa[0]>=a[0];
        }
        else  return false;
    }
    else  return false;
}

int main(int argc, char const *argv[])
{

    bool flag=false;
    int i;
    cin >>s;
    for(i=0; i<3; i++)
        sa[i]=(s[i*2+i]-'0')*10+s[i*2+1+i]-'0';
    cin >>s;
    for(i=0; i<3; i++)
        a[i]=(s[i*2+i]-'0')*10+s[i*2+1+i]-'0';
    for(i=0; i<6; i++)
    {
        if(check())flag=true;;
        next_permutation(a,a+3);
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;

}
