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
//                  ������¥                  BUG����
//          ��Ի:
//                  д��¥��д�ּ䣬д�ּ������Ա��
//                  ������Աд�������ó��򻻾�Ǯ��
//                  ����ֻ���������������������ߣ�
//                  ��������ո��գ����������긴�ꡣ
//                  ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
//                  ���۱������Ȥ���������г���Ա��
//                  ����Ц��߯��񲣬��Ц�Լ���̫����
//                  ��������Ư���ã��ĸ���ó���Ա��
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

int n,m;
int a[MAXN];
int l[MAXN],r[MAXN];
int ans=0;

int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}

/*
int judge(int a,int b)
{
    if(gcd(a,b)==1) return 0;
    else
    {
        for(int i=2; i<=min(a,b); i++)
        {
            if(a%i==0&&b%i==0)  return i;
        }
    }
    return 0;
}
**/

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }
    ans=m;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        if(gcd(a[l[i]], a[r[i]])==1)
        {
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
