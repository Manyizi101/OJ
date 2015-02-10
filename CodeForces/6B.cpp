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
//                  佛祖镇楼                  BUG辟易
//          佛曰:
//                  写字楼里写字间，写字间里程序员；
//                  程序人员写程序，又拿程序换酒钱。
//                  酒醒只在网上坐，酒醉还来网下眠；
//                  酒醉酒醒日复日，网上网下年复年。
//                  但愿老死电脑间，不愿鞠躬老板前；
//                  奔驰宝马贵者趣，公交自行程序员。
//                  别人笑我忒疯癫，我笑自己命太贱；
//                  不见满街漂亮妹，哪个归得程序员？
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

char c,road[MAXN][MAXN];
int n,m;
pair<int,int> lt(-1,-1);
	pair<int,int> rb(-1,-1);
	set<char> ans;

 void init()
 {
     scanf("%d %d %c", &n,&m,&c);
     for(int i=0;i<n;i++)
     {
         scanf("%s", road[i]);
     }
 }

int main(int argc, char const *argv[])
{
	init();

	for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(road[i][j]==c)
            {
                rb=pair<int,int>(i,j);
                if(lt.first<0)  lt=pair<int,int>(i,j);
            }
        }
    }
    for(int i=lt.first;i<=rb.first;i++)
    {
        for(int j=lt.second;j<=rb.second;j++)
        {
            if(i>0&&road[i-1][j]!=c&&road[i-1][j]!='.') ans.insert(road[i-1][j]);
            if(i<n-1&&road[i+1][j]!=c&&road[i+1][j]!='.')   ans.insert(road[i+1][j]);
            if(j>0&&road[i][j-1]!=c&&road[i][j-1]!='.') ans.insert(road[i][j-1]);
            if(j<m-1&&road[i][j+1]!=c&&road[i][j+1]!='.')   ans.insert(road[i][j+1]);
        }
    }
    printf("%d", ans.size());
    return 0;
}
