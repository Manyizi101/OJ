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

int a,b,n;
int x;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &a,&b,&n);
    if(a==0&&b==0)
    {
        printf("%d", 5);
    }
    else
    {
        if(a*b>0)
        {
            for(x=0; x<=1000; x++)
            {
                if(fabs(pow(1.0*x,1.0*n)-b*1.0/a)<eps)
                {
                    printf("%d\n", x);
                    return 0;
                }
            }
        }
        else if(a*b<0)
        {
            for(x=-1000; x<=0; x++)
            {
                if(fabs(pow(1.0*x,1.0*n)-b*1.0/a)<eps)
                {
                    printf("%d\n", x);
                    return 0;
                }
            }
        }
        else if(b==0)
        {
            printf("0\n");
            return 0;
        }
        printf("No solution\n");
    }
    return 0;
}
