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

#define MAXN 10000+10

int flag,lena,lenb,leng,mis,tru,tmp,lent;
char a[MAXN];
char b[MAXN];
char guess[MAXN];
char tguess[MAXN];

int main(int argc, char const *argv[])
{
aaa:
    while(scanf("%d", &flag)&&flag!=-1)
    {
        memset(b,0,sizeof(b));
        memset(tguess,0,sizeof(tguess));
        printf("Round %d\n", flag);
        scanf("%s", a);
        scanf("%s", guess);
        lena=strlen(a);
        lenb=1;
        leng=strlen(guess);
        lent=1;
        mis=tru=0;
        b[0]=a[0];
        tguess[0]=guess[0];
        sort(a,a+lena);
        sort(guess,guess+leng);
        for(int i=1; i<lena; i++)
        {
            if(a[i]==b[lenb-1])
            {
                continue;
            }
            else
            {
                b[++lenb-1]=a[i];
            }
        }
        for(int i=1; i<leng; i++)
        {
            if(guess[i]==tguess[lent-1])
            {
                continue;
            }
            else
            {
                tguess[++lent-1]=guess[i];
            }
        }
        for(int i=0; i<lent; i++)
        {
            for(int j=0; j<lenb; j++)
            {
                if(tguess[i]==b[j])
                {
                    tmp=1;
                    break;
                }
            }
            tmp?tru++:mis++;
            tmp=0;
            if(tru==lenb)
            {
                printf("You win.\n");
                goto aaa;
            }
            if(mis==7)
            {
                printf("You lose.\n");
                goto aaa;
            }
        }
        printf("You chickened out.\n");
        goto aaa;
    }
    return 0;
}
