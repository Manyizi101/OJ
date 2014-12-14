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

int n,k,cnt;
char a[4][4];
char str[1005][1005];
char temp[1005][1005];

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d", &n,&k);
    cnt=n;
    for(int i=0; i<n; i++)
    {
        scanf("%s", a[i]);
        strcpy(str[i],a[i]);
    }
    while(--k)
    {
        cnt*=n;
        for(int i=0; i<cnt; i++)
        {
            for(int j=0; j<cnt; j++)
            {
                if(str[i][j]=='.')
                {
                    for(int ii=0;ii<n;ii++)
                    {
                        for(int jj=0;jj<n;jj++)
                        {
                            temp[i*n+ii][j*n+jj]=a[ii][jj];
                        }
                    }
                }
                else
                {
                    for(int ii=0;ii<n;ii++)
                    {
                        for(int jj=0;jj<n;jj++)
                        {
                            temp[i*n+ii][j*n+jj]='*';
                        }
                    }
                }
            }
        }
        for(int i=0;i<cnt;i++)
        {
            strcpy(str[i],temp[i]);
        }
    }
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<cnt; j++)
        {
            printf("%c", str[i][j]);
        }
        printf("\n");
    }
    return 0;
}

