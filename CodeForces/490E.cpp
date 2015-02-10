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

#define MAXN 100000+10

int n;
char a[MAXN][10];
int len[MAXN];

bool judge(int i, int j)
{
    for(; j<len[i]; j++)
    {
        if(a[i][j]=='?')    continue;
        if(a[i][j]<a[i-1][j])   return false;
    }
    return true;
}

bool check()
{
    for(int i=1; i<n; i++)
    {
        if(len[i]<len[i-1]) return false;
    }
    for(int j=0; j<len[0]; j++)
    {
        if(a[0][j]=='?')    a[0][j]='1';
    }
    for(int i=1;i<n;i++)
    {
        if(a[i][0]=='?'&&judge(i,1))    a[i][0]=a[i-1][0];
        else if(a[i][0]=='?'&&!judge(i,1)&&a[i-1][0]<'9') a[i][0]=a[i-1][0]+1;
        else if(a[i][0]=='?'&&!judge(i,1)&&a[i-1][0]=='9')  return false;
    }
    for(int i=1; i<n; i++)
    {
        if(len[i]==len[i-1])
        {
            for(int j=0; j<len[i]; j++)
            {
                if(a[i][j]=='?')
                {
                    if(judge(i,j+1))
                    {
                        if(a[i-1][j]<='9'&&j<len[i]-1)
                        {
                            a[i][j]=a[i-1][j];
                            break;
                        }
                        else if(a[i-1][j]<'9'&&j==len[i]-1)
                        {
                            a[i][j]=a[i-1][j]+1;
                            break;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if(a[i-1][j]<='8')
                        {
                            a[i][j]=a[i-1][j]+1;
                            break;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if(a[i][j]<a[i-1][j])   return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", a[i]);
        len[i]=strlen(a[i]);
    }
    if(check())
    {
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<len[i];j++)
            {
                if(a[i][j]=='?')    a[i][j]='1';
            }
        }
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            puts(a[i]);
        }
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
