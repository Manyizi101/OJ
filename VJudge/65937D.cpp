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

#define MOD 1000007
#define MAXN 100000+10

int n;
bool flag;
vector<int> f[MOD];
int a[MAXN][6];


int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    flag = false;
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<6; j++)
        {
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }

        //�г����غ�
        for(int kk=0; kk<f[sum%MOD].size(); kk++)
        {
            int j = f[sum % MOD][kk];
            for (int k = 0; k < 6; k++)
            {
                flag = true;
                for (int p = 0; p < 6; p++)
                {
                    if (a[i][p] != a[j][(k + p) % 6])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;

            //����ת�غ�
            flag = true;
            for (int k = 0; k < 6; k++)
            {
                flag = true;
                for (int p = 0; p < 6; p++)
                    if (a[i][p] != a[j][(k - p + 6) % 6])
                    {
                        flag = false;
                        break;
                    }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) break;

        f[sum % MOD].push_back(i);
    }
    flag?puts("Twin snowflakes found."):puts("No two snowflakes are alike.");
    return 0;
}
