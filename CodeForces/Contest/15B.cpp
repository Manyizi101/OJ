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

ll n, m , cnt, h, l, i, t ;
ll v[4];

int main(int argc, char const *argv[])
{
    ll x1,x2,y1,y2;
    scanf("%I64d", &t);
    while(t--)
    {
        cnt = 0;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &n,&m,&x1,&y1,&x2,&y2);
        v[0] = min(y1,y2) - 1;
        v[1] = min(x1,x2) - 1;
        v[2] = m - max(y1,y2);
        v[3] = n - max(x1,x2);
        for(i=0; i<4; i++)
        {
            cnt += v[i];
            if(i==3)
                cnt += v[3]*v[0];
            else
                cnt += v[i]*v[i+1];
        }
        if((max(y1,y2)-v[0])<=(min(y1,y2)+v[2]))
            h = v[2]+v[0]-abs(y1-y2) + 1;
        else
            h = 0;
        if((min(x1,x2)+v[3])>=(max(x1,x2)-v[1]))
            l = v[1]+v[3] - abs(x1-x2) +1;
        else
            l = 0;
        cnt = m*n - cnt*2 - 2 + l*h;
        cout<<cnt<<endl;
    }
    return 0;
}
