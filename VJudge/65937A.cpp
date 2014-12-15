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

#define MAXN 300+10

int dp[35][MAXN], s[35][MAXN];
int w[MAXN][MAXN];
int v, p;
int a[MAXN];

void init()
{
    for (int i = 1; i <= v; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= v; i++)
    {
        w[i][i] = 0;
        for (int j = i + 1; j <= v; j++)
        {
            w[i][j] = w[i][j - 1] + a[j] - a[(i + j) / 2];
            w[j][i] = inf;
        }
    }
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= v; i++)
    {
        dp[1][i] = w[1][i];
        s[1][i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &v, &p) != EOF)
    {
        init();
        for (int i = 2; i <= p; i++)
        {
            s[i][v + 1] = v;
            for (int j = v; j >= i; j--)
            {
                for (int k = s[i - 1][j]; k <= s[i][j + 1]; k++)
                {
                    if (dp[i][j] > dp[i - 1][k] + w[k + 1][j])
                    {
                        s[i][j] = k;
                        dp[i][j] = dp[i - 1][k] + w[k + 1][j];
                    }
                }
            }
        }
        printf("%d\n", dp[p][v]);
    }
    return 0;
}
