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


string s;

int main(int argc, char const *argv[])
{
    while( cin >> s )
    {
        int len = s.size();
        vector<int> v;
        bool flag = true;
        string o;

        int pos = 0;
        if(s[0]=='@' || s[len-1]=='@')
        {
            flag = false;
        }
        else
        {
            for(int i=0; i<len; i++) if(s[i] == '@' )
                    v.push_back(i);
            if( v.size()==0 )
                flag = false;

            if(flag)
            {
                for(int i=0; i<v.size()-1; i++)
                {
                    if( v[i+1] - v[i] -1 < 2) flag = false;
                    else
                    {
                        for(int j=pos; j<=v[i]+1; j++) o += s[j];
                        pos = v[i] + 2;
                        o += ',';
                    }
                }
            }
        }
        for(int j=pos; j<s.size(); j++)
            o += s[j];
        if(!flag)
            cout << "No solution\n";
        else
            cout << o << endl;
    }
    return 0;
}
