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

#define MAXN 200000+10

int len[4],kp[MAXN],ans;
string str[4];

int getMinKmp(int a, int b)
{
    int i=0,j=-1;
    memset(kp,0,sizeof(kp));
    kp[0]=-1;
    while(i<len[b])
    {
        while(j>=0&&str[b][i]!=str[b][j])
        {
            j=kp[j];
        }
        i++;
        j++;
        kp[i]=j;
    }
    i=0;
    j=0;
    while(i<len[a])
    {
        while(j>=0&&str[a][i]!=str[b][j])
        {
            j=kp[j];
        }
        i++;
        j++;
        if(j==len[b])
        {
            return len[b];
        }
    }
    return j;
}

int getMinContainStr(int a, int b ,int c)
{
    int t=getMinKmp(a,b);
    if(t!=len[b])
    {
        str[3]=str[a].substr(0,len[a]-t);
        str[3]=str[3]+str[b];
    }
    else
    {
        str[3]=str[a];
    }
    len[3]=str[3].length();
    t=getMinKmp(3,c);
    if(t==len[c])
    {
        return str[3].length();
    }
    return str[3].length()+len[c]-t;
}

int main(int argc, char const *argv[])
{
    for(int i=0; i<3; i++)
    {
        cin>>str[i];
        len[i]=str[i].length();
    }
    ans=inf;
    /*
    do
    {
        ans=min(ans,getMinContainStr(0,1,2));
        ans=min(ans,getMinContainStr(2,1,0));
        cout<<str[0]<<endl<<str[1]<<endl<<str[2]<<endl;
    }
    while(next_permutation(str,str+3));
    **/
    ans = min(ans, getMinContainStr(0, 1, 2));
    ans = min(ans, getMinContainStr(0, 2, 1));
    ans = min(ans, getMinContainStr(1, 0, 2));
    ans = min(ans, getMinContainStr(1, 2, 0));
    ans = min(ans, getMinContainStr(2, 0, 1));
    ans = min(ans, getMinContainStr(2, 1, 0));
    printf("%d\n", ans);
    return 0;
}
