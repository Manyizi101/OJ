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

#define MAXN (2<<16)+10

int flag=0;
ll n;
ll a[MAXN],b[MAXN];
ll mark,ans;

void cal(ll n)
{
    mark=0;
    for(ll i=1;i<=(ll)(sqrt(n)+1);i++)
    {
        a[mark]=i;
        b[mark]=n/i;
        if(a[mark]*b[mark]==n)
        {
            mark++;
        }
    }
}

int main(int argc, char const *argv[])
{
	while(~scanf("%I64d", &n)&&n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        printf("Case: %d\n", ++flag);
        cal(n);
        ans=inf;
        for(ll i=0;i<mark;i++)
        {
            ans=min(ans,a[i]+b[i]);
        }
        printf("%I64d\n", ans);
    }
	return 0;
}
