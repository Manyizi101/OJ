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

int t,n,ans;
char a[MAXN][MAXN];


struct node
{
    int id,num;
    char c;
}tmp[4];

bool cmp(node a, node b)
{
    return a.c>b.c;
}

bool cmp1(node a. node b)
{
    return a.num>b.num;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
    {
        for(int i=0;i<4;i++)
        {
            tmp[i].id=i;
        }
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s", a[i]+1);
        }
        //���Ͻ�
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=n/2;j++)
            {
                int flag=1;
                tmp[0].c=a[i][j];
                tmp[1].c=a[n+1-i][j];
                tmp[2].c=a[n+1-i][n+1-j];
                tmp[3].c=a[i][n+1-j];
                for(int i=0;i<4;i++)
                {
                    tmp[i].num=1;
                }
                sort(tmp,tmp+4,cmp);
                for(int i=1;i<4;i++)
                {
                    if(tmp[i].c!=tmp[i-1].c)
                    {
                        flag++;
                    }
                    else
                    {
                        tmp[i].num=tmp[i-1]+1;
                    }
                }
                sort(tmp,tmp+4,cmp1);
            }
        }
    }
	return 0;
}
