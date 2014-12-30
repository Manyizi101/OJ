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

char a[10];
int road[9][9];
int dir[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int ans=0;

struct node
{
    int x,y;
}rook,knight;

bool judge(int x,int y)
{
    if(x>=1&&x<=8&&y>=1&&y<=8)  return true;
    else return false;
}

void init()
{
    memset(road,0,sizeof(road));
    for(int i=0;i<9;i++)
    {
        road[0][i]=1;
        road[i][0]=1;
    }
	scanf("%s", a);
	rook.x=a[0]-'a'+1;
	rook.y=a[1]-'0';
	scanf("%s", a);
	knight.x=a[0]-'a'+1;
	knight.y=a[1]-'0';
}

int main(int argc, char const *argv[])
{
    init();
    road[rook.x][rook.y]=1;
    road[knight.x][knight.y]=1;
    for(int i=1;i<=8;i++)
    {
        road[rook.x][i]=1;
        road[i][rook.y]=1;
    }
	for(int i=0;i<8;i++)
    {
        if(judge(knight.x+dir[i][0],knight.y+dir[i][1]))
        {
            road[knight.x+dir[i][0]][knight.y+dir[i][1]]=1;
        }
        if(judge(rook.x+dir[i][0],rook.y+dir[i][1]))
        {
            road[rook.x+dir[i][0]][rook.y+dir[i][1]]=1;
        }
    }
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(road[i][j]==0)   ans++;
        }
    }
    cout<<ans;
	return 0;
}
